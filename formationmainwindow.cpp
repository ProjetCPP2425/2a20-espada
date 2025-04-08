#include "formationmainwindow.h"
#include "QtCharts/qchart.h"
#include "QtCharts/qchartview.h"
#include "QtCharts/qpieseries.h"
#include "ui_formationmainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include <QPageSize>
#include <QStandardPaths>
#include <QPdfWriter>

FormationMainWindow::FormationMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FormationMainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ftmp.afficher());
    ui->tableView->setColumnHidden(0, true);

    ButtonDelegate *buttonDelegate = new ButtonDelegate(this);
    ui->tableView->setItemDelegateForColumn(7, buttonDelegate);
    ui->tableView->setItemDelegateForColumn(8, buttonDelegate);

    connect(buttonDelegate, &ButtonDelegate::deleteButtonClicked, this, &FormationMainWindow::onDeleteButtonClicked);
    connect(buttonDelegate, &ButtonDelegate::editButtonClicked, this, &FormationMainWindow::onEditButtonClicked);
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &FormationMainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &FormationMainWindow::on_pushButton_rechercher_clicked);
    ui->tableView->resizeColumnsToContents();
    connect(ui->pushButton_6, &QPushButton::clicked, this, &FormationMainWindow::on_pdf_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &FormationMainWindow::on_statbutton_clicked);


}

FormationMainWindow::~FormationMainWindow()
{
    delete ui;
}

void FormationMainWindow::on_pushButton_ajouter_clicked()
{
    QString TITRE = ui->lineEdit_titre->text();
    QString DESCRIPTION = ui->lineEdit_description->text();
    QString DATE_DEBUT = ui->dateEdit_debut->date().toString("yyyy-MM-dd");
    QString DATE_FIN = ui->dateEdit_fin->date().toString("yyyy-MM-dd");
    int DUREE = ui->spinBox_duree->value();
    float PRIX = ui->doubleSpinBox_prix->value();

    Formation F( TITRE, DESCRIPTION, DATE_DEBUT, DATE_FIN, DUREE, PRIX, 1);

    bool test = F.ajouter();

    if (test) {
        ui->tableView->setModel(Ftmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"),
                                 QMessageBox::Cancel);
    }
}

void FormationMainWindow::onDeleteButtonClicked(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    bool success = Ftmp.supprimer(id);

    if (success) {
        ui->tableView->setModel(Ftmp.afficher());
        QMessageBox::information(this, "Succès", "Formation supprimée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}

void FormationMainWindow::onEditButtonClicked(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    QString titre = ui->tableView->model()->index(row, 1).data().toString();
    QString description = ui->tableView->model()->index(row, 2).data().toString();
    QString date_debut = ui->tableView->model()->index(row, 3).data().toString();
    QString date_fin = ui->tableView->model()->index(row, 4).data().toString();
    int duree = ui->tableView->model()->index(row, 5).data().toInt();
    float prix = ui->tableView->model()->index(row, 6).data().toFloat();

    EditFormationDialog dialog(this);
    dialog.setID(id);
    dialog.setFormationData(titre, description, date_debut, date_fin, duree, prix);

    if (dialog.exec() == QDialog::Accepted) {
        bool success = Ftmp.modifier(dialog.getID(), dialog.getTitre(), dialog.getDescription(),
                                     dialog.getDateDebut(), dialog.getDateFin(), dialog.getDuree(), dialog.getPrix());

        if (success) {
            ui->tableView->setModel(Ftmp.afficher());
            QMessageBox::information(this, "Succès", "Formation modifiée avec succès.");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification.");
        }
    }
}

void FormationMainWindow::on_pushButton_rechercher_clicked()
{
    QString searchText = ui->lineEdit->text();
    QSqlQueryModel *model = Ftmp.recherche(searchText);
    ui->tableView->setModel(model);
}
void FormationMainWindow::on_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QTextDocument doc;
    QString html = "<html><head><style>"
                   "body { background-color: white; color: black; font-family: Arial, sans-serif; }"
                   "h2 { text-align: center; color: black; }"
                   "table { width: 100%; border-collapse: collapse; }"
                   "th, td { border: 1px solid black; padding: 5px; text-align: left; }"
                   "th { font-weight: bold; background-color: #f2f2f2; }"
                   "tr:nth-child(even) { background-color: #f9f9f9; }"
                   "tr:nth-child(odd) { background-color: #ffffff; }"
                   "</style></head><body>";

    html += "<h2>Liste des Formations</h2>";
    html += "<table>";
    html += "<tr>";

    // Récupérer le modèle du QTableView
    QAbstractItemModel *model = ui->tableView->model();

    if (!model) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données du tableau.");
        return;
    }

    int columnCount = model->columnCount();
    int rowCount = model->rowCount();

    // Vérifier si le tableau contient des données
    if (rowCount == 0) {
        QMessageBox::warning(this, "Exportation PDF", "Aucune donnée à exporter.");
        return;
    }

    // En-têtes du tableau (en excluant les colonnes des boutons)
    for (int col = 0; col < columnCount - 2; col++) { // -2 pour exclure les colonnes Supprimer/Modifier
        QString headerText = model->headerData(col, Qt::Horizontal).toString();
        html += "<th>" + headerText + "</th>";
    }
    html += "</tr>";

    // Remplissage du tableau avec les données
    for (int row = 0; row < rowCount; row++) {
        html += "<tr>";
        for (int col = 0; col < columnCount - 2; col++) { // -2 pour exclure les colonnes Supprimer/Modifier
            QVariant data = model->data(model->index(row, col));
            QString cellText = data.toString().trimmed();

            // Correction du format de la date pour éviter "T00:00:00.000"
            if (cellText.contains("T")) {
                cellText = cellText.split("T")[0];
            }

            // Formatage spécifique pour les colonnes
            if (col == 5) { // Colonne Durée
                cellText += " jours";
            } else if (col == 6) { // Colonne Prix
                cellText += " €";
            }

            html += "<td>" + cellText + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";

    // Génération du PDF
    doc.setHtml(html);
    QPainter painter(&pdfWriter);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "Exportation PDF", "Le fichier PDF a été généré avec succès !");
}
void FormationMainWindow::on_statbutton_clicked()
{
    QTabWidget *tabWidget = new QTabWidget();


    struct StatInfo {
        QString title;
        QString field;
        QString unit;
    };

    QList<StatInfo> stats = {
        {"Durée des formations", "DUREE", " jours"},
        {"Prix des formations", "PRIX", " €"},

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
        QString queryString = "SELECT " + stat.field + ", COUNT(*) AS count FROM FORMATION GROUP BY " + stat.field;
        query.prepare(queryString);

        if (query.exec()) {
            while (query.next()) {
                QString label = query.value(0).toString();
                int count = query.value(1).toInt();
                if (!label.isEmpty()) {
                    // Ajoute l'unité si nécessaire
                    if (!stat.unit.isEmpty() && stat.field != "TITRE") {
                        label += stat.unit;
                    }
                    QPieSlice *slice = series->append(label, count);
                    slice->setLabelVisible(true);
                    slice->setExploded(true);
                    slice->setLabel(QString("%1 (%2)").arg(label).arg(count));
                }
            }
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
    dialog->setWindowTitle("Statistiques des formations");
    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->addWidget(tabWidget);
    dialog->setLayout(dialogLayout);
    dialog->resize(800, 500);
    dialog->exec();
}
