#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ressource.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QPainter>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QPrinter>
#include <QTextDocument>
#include <QPageSize>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->confirmer, &QPushButton::clicked, this, &MainWindow::on_pushButton_confirmer_clicked);
    connect(ui->supprimerr, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimerr_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->confirmermodification, &QPushButton::clicked, this, &MainWindow::on_pushButton_confirmermodification_clicked);
   //connect(ui->generatePDFButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_generatePDFButton_clicked); // Added for PDF generation
     connect(ui->statbutton, &QPushButton::clicked, this, &MainWindow::on_statbutton_clicked);
    connect(ui->pdfButton, &QPushButton::clicked, this, &MainWindow::on_pdfButton_clicked);
    //connect(ui->search, &QPushButton::clicked, this, &MainWindow::on_pushButton_search_clicked);
    ui->table->setModel(R.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isValidInput()
{
    // Vérifier si tous les champs sont remplis
    if (ui->nom->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ NOM ne peut pas être vide.");
        return false;
    }

    if (ui->description->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ DESCRIPTION ne peut pas être vide.");
        return false;
    }

    if (ui->type->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ TYPE ne peut pas être vide.");
        return false;
    }

    if (ui->localisation->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ LOCALISATION ne peut pas être vide.");
        return false;
    }

    if (ui->etat->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ ETAT ne peut pas être vide.");
        return false;
    }

    bool ok;
    ui->quantite->text().toInt(&ok); // Vérifier si QUANTITE est un nombre entier
    if (!ok) {
        QMessageBox::warning(this, "Quantité invalide", "Veuillez entrer un nombre valide pour QUANTITE.");
        return false;
    }

    return true;
}

void MainWindow::on_pushButton_confirmer_clicked()
{
    if (!isValidInput()) {
        return;
    }

    QString NOM = ui->nom->text();
    QString DESCRIPTION = ui->description->text();
    QString TYPE = ui->type->text();
    QString LOCALISATION = ui->localisation->text();
    int QUANTITE = ui->quantite->text().toInt();
    QString ETAT = ui->etat->text();
    ressource R(NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT);

    bool test = R.ajouter();
    ui->nom->clear();
    ui->description->clear();
    ui->type->clear();
    ui->localisation->clear();
    ui->quantite->clear();
    ui->etat->clear();

    if (test) {
        ui->table->setModel(R.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout réussi.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ajout échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimerr_clicked()
{
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner une ressource à supprimer."));
        return;
    }

    int id = selectedRows.first().data().toInt();
    bool test = R.supprimer(id);

    if (test) {
        ui->table->setModel(R.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression réussie.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Suppression échouée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner une ressource à modifier."));
        return;
    }

    int id = selectedRows.first().data().toInt();
    ressource R = R.trouver(id);

    ui->nom->setText(R.getNOM());
    ui->description->setText(R.getDESCRIPTION());
    ui->type->setText(R.getTYPE());
    ui->localisation->setText(R.getLOCALISATION());
    ui->quantite->setText(QString::number(R.getQUANTITE()));
    ui->etat->setText(R.getETAT());

    connect(ui->confirmermodification, &QPushButton::clicked, [this, id]() {
        ressource R;  // Créer un objet ressource vide
        R = R.trouver(id);  // Utiliser la méthode trouver pour récupérer la ressource par ID

        R.setNom(ui->nom->text());
        R.setDescription(ui->description->text());
        R.setType(ui->type->text());
        R.setLocalisation(ui->localisation->text());
        R.setQuantite(ui->quantite->text().toInt());
        R.setEtat(ui->etat->text());
    });
}

void MainWindow::on_pushButton_confirmermodification_clicked()
{
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ressource à modifier.");
        return;
    }

    int id = selectedRows.first().data().toInt();
    ressource R = R.trouver(id);

    if (R.getID() == 0) {
        QMessageBox::warning(this, "Erreur", "La ressource avec l'ID spécifié n'existe pas.");
        return;
    }

    if (!isValidInput()) {
        return;
    }

    QString NOM = ui->nom->text();
    QString DESCRIPTION = ui->description->text();
    QString TYPE = ui->type->text();
    QString LOCALISATION = ui->localisation->text();
    int QUANTITE = ui->quantite->text().toInt();
    QString ETAT = ui->etat->text();

    R.setNom(NOM);
    R.setDescription(DESCRIPTION);
    R.setType(TYPE);
    R.setLocalisation(LOCALISATION);
    R.setQuantite(QUANTITE);
    R.setEtat(ETAT);

    bool test = R.modifier(id);

    if (test) {
        ui->table->setModel(R.afficher());
        QMessageBox::information(this, "Modification réussie", "La ressource a été modifiée avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }

    ui->nom->clear();
    ui->description->clear();
    ui->type->clear();
    ui->localisation->clear();
    ui->quantite->clear();
    ui->etat->clear();
}


void MainWindow::on_statbutton_clicked()
{

        QTabWidget *tabWidget = new QTabWidget();

        struct StatInfo {
            QString title;
            QString field;
        };

        QList<StatInfo> stats = {
            {"Répartition par nom", "NOM"},
            {"Répartition par type", "TYPE"},
            {"Répartition par quantité", "QUANTITE"}
        };

        QStringList colors = {
            "#ff6f61", "#6b5b95", "#88b04b", "#f7cac9",
            "#92a8d1", "#955251", "#b565a7", "#009688",
            "#f4b400", "#607d8b"
        };

        for (const StatInfo &stat : stats)
        {
            QPieSeries *series = new QPieSeries();

            QSqlQuery query;
            QString queryString = "SELECT " + stat.field + ", COUNT(*) AS count FROM RESSOURCE GROUP BY " + stat.field;
            query.prepare(queryString);

            if (query.exec()) {
                while (query.next()) {
                    QString label = query.value(0).toString();
                    int count = query.value(1).toInt();
                    if (!label.isEmpty()) {
                        QPieSlice *slice = series->append(label, count);
                        slice->setLabelVisible(true);
                        slice->setExploded(true);
                        slice->setLabel(QString("%1 (%2)").arg(label).arg(count));
                    }
                }
            } else {
                qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
            }

            int i = 0;
            for (QPieSlice *slice : series->slices()) {
                slice->setColor(QColor(colors[i % colors.size()]));
                i++;
            }

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle(stat.title);
            chart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);
            chart->legend()->setFont(QFont("Segoe UI", 10));

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            QWidget *tab = new QWidget();
            QVBoxLayout *layout = new QVBoxLayout(tab);
            layout->addWidget(chartView);
            tab->setLayout(layout);

            tabWidget->addTab(tab, stat.title);
        }

        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Statistiques des ressources");
        QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
        dialogLayout->addWidget(tabWidget);
        dialog->setLayout(dialogLayout);
        dialog->resize(800, 500);
        dialog->exec();


}





void MainWindow::on_quantite_2_clicked()
{
    QSqlQueryModel* model = R.Trier_Ressources("QUANTITE"); // R est l'objet de la classe ressource
    ui->table->setModel(model);
}


void MainWindow::on_type_2_clicked()
{
    QSqlQueryModel* model = R.Trier_Ressources("TYPE");
    ui->table->setModel(model);
}


void MainWindow::on_rechercher_textChanged(const QString &text)
{
    ressource R; // Assure-toi que tu as une instance de ressource
    QSqlQueryModel* model = R.recherche(text); // Appel de la fonction recherche dans ressource

    if (model)
    {
        ui->table->setModel(model); // Mise à jour de la table
    }
}




void MainWindow::on_pdfButton_clicked()
{
    // Sélection du fichier PDF de destination
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QString(), "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    // Connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données non établie.");
        return;
    }

    // Configuration de l'imprimante
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    // Création du document PDF
    QTextDocument doc;
    QString text;
    QTextStream stream(&text);

    stream << "<h2 style='text-align: center;'>Liste des Ressources</h2>";
    stream << "<hr><br>";
    stream << "<table style='width:100%; border-collapse: collapse; font-size: 12px;'>";

    stream << "<tr style='background-color: #f2f2f2;'>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>ID</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Nom</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Description</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Type</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Localisation</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Quantité</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>État</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>ID Projet</th>";
    stream << "</tr>";

    // Requête pour récupérer les ressources
    QSqlQuery query(db);
    query.prepare("SELECT ID, NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, IDPROJET FROM RESSOURCE");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // Boucle pour récupérer les données et remplir le PDF
    while (query.next()) {
        stream << "<tr>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("ID").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("NOM").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("DESCRIPTION").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("TYPE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("LOCALISATION").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("QUANTITE").toInt() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("ETAT").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("IDPROJET").toInt() << "</td>";
        stream << "</tr>";
    }

    stream << "</table>";
    doc.setHtml(text);
    doc.print(&printer);

    QMessageBox::information(this, "PDF", "PDF généré avec succès.");
}

