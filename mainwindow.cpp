#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Arduino_RDV.h"
#include "rendezvous.h"
#include <QMessageBox>
#include <QSqlError>
#include <QRegularExpression>
#include <QFileDialog>
#include <QFileInfo>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QListWidget>
#include <QDateTime>
#include <QCalendarWidget>
 #include <QTextCharFormat>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret = A.connect_arduino(); // Lancer la connexion à Arduino

    switch (ret) {
    case 0:
        qDebug() << "Arduino is available and connected to : " << A.getarduino_port_name();
        break;
    case 1:
        qDebug() << "Arduino is available but not connected to :" << A.getarduino_port_name();
        break;
    case -1:
        qDebug() << "Arduino is not available";
        break;
    }

    // Connexion du signal readyRead() au slot handleSerialData()
    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(handleSerialData()));













     connect(ui->calander_rdv, &QCalendarWidget::clicked, this, &MainWindow::on_calander_rdv_clicked);
   /* QObject::connect(serial, &QSerialPort::readyRead, this, &Arduino_RDV::handleSerialData);
     Arduino_RDV ard;

     // dans ton constructeur MainWindow
     ard.connect_arduino();*/

    QTimer::singleShot(2000, this, [this]() { checkUpcomingRdvNotification(); });
   // connect(ui->calander_rdv, &QCalendarWidget::clicked, this, &MainWindow::on_calander_rdv_clicked);

    ui->calander_rdv->setStyleSheet(
        "QCalendarWidget {"
        "  background-color: #f0f0f0;"
        "  border: 1px solid #888;"
        "  font-size: 14px;"
        "}"

        "QCalendarWidget QAbstractItemView:enabled {"
        "  background-color: white;"
        "  selection-background-color: #0078d7;"
        "  selection-color: white;"
        "  gridline-color: #ccc;"
        "}"

        "QCalendarWidget QToolButton {"
        "  background-color: #0078d7;"
        "  color: white;"
        "  border: none;"
        "  padding: 5px;"
        "  font-weight: bold;"
        "}"

        "QCalendarWidget QToolButton:hover {"
        "  background-color: #005fa3;"
        "}"

        "QCalendarWidget QMenu {"
        "  background-color: white;"
        "  border: 1px solid #ccc;"
        "}"

        "QCalendarWidget QSpinBox {"
        "  margin: 2px;"
        "  padding: 2px;"
        "}"
        );




    ///////////////


////////////
updateRdvButton();
    ui->tab_affichage->setModel(rdv.afficher_RDV());
    ui->tab_affichage->resizeColumnsToContents();

    ui->tab_affichage->update();
    ui->tab_affichage->show();
    ui->tab_affichage->setStyleSheet(
        "QTableView::item:selected { "
        "background-color: #e27396; "  // Jaune doré
        "color: black; "
        "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleSerialData()
{
    A.processSensorData(); // Appeler la méthode qui gère la lecture et mise à jour
}
void MainWindow::on_addRDV_clicked()
{
    // Récupération des données saisies

    QDate date = ui->dateRDV->date();  // Récupération de la date (QDate)
    QString heure = ui->heureRDV->time().toString("HH:mm");  // Récupération de l'heure au format "HH:mm"
    QString mode = ui->modeRDV->currentText().trimmed();  // Récupération du mode sélectionné dans le QComboBox
    QString objectif = ui->objectifRDV->text().trimmed();
    QString client = ui->clientRDV->text().trimmed();

    // Vérification des champs
    if (heure.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'heure du rendez-vous est obligatoire.");
        return;
    }
    if (date < QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date du rendez-vous doit être aujourd'hui ou ultérieure.");
        return;
    }

    if (mode.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le mode du rendez-vous est obligatoire.");
        return;
    }
    if (objectif.length() < 10) {
        QMessageBox::warning(this, "Erreur", "L'objectif doit contenir au moins 10 caractères.");
        return;
    }
    if (client.length() <3) {
        QMessageBox::warning(this, "Erreur", "Le nom doit contenir au moins 3 caractères.");
        return;
    }
    if (client.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom du client est obligatoire.");
        return;
    }

    // Création de l'objet RendezVous sans ID (auto-incrémenté)
    RendezVous rdv(0, date, heure, mode, objectif, client);  // Assurer que l'ID est à 0 si auto-incrémenté
    bool test = rdv.ajouter_RDV();  // Utilisation de la méthode correcte

    if (test) {
        QMessageBox::information(this, "Succès", "Rendez-vous ajouté avec succès.");

        // Réinitialisation des champs
        ui->dateRDV->setDate(QDate::currentDate());
        ui->heureRDV->clear();
        ui->modeRDV->setCurrentIndex(0);  // Réinitialiser le QComboBox
        ui->objectifRDV->clear();
        ui->clientRDV->clear();

        // Mise à jour de l'affichage
        ui->tab_affichage->setModel(rdv.afficher_RDV());
        ui->tab_affichage->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du rendez-vous.");
    }
}


void MainWindow::on_tab_affichageRDV_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }

    // Récupération des valeurs depuis le tableau
    int id = ui->tab_affichage->model()->data(index.siblingAtColumn(0)).toInt();
    QDate date = ui->tab_affichage->model()->data(index.siblingAtColumn(1)).toDate();
    QString heure = ui->tab_affichage->model()->data(index.siblingAtColumn(2)).toString();
    QString mode = ui->tab_affichage->model()->data(index.siblingAtColumn(3)).toString();
    QString objectif = ui->tab_affichage->model()->data(index.siblingAtColumn(4)).toString();
    QString client = ui->tab_affichage->model()->data(index.siblingAtColumn(5)).toString();

    // Remplissage des champs
   // ui->idR->setText(QString::number(id));
    ui->dateRDV->setDate(date);
    ui->heureRDV->setTime(QTime::fromString(heure, "HH:mm"));  // Conversion en QTime
    ui->modeRDV->setCurrentText(mode);
    ui->objectifRDV->setText(objectif);
    ui->clientRDV->setText(client);
}


void MainWindow::on_updateRDV_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QItemSelectionModel *selection = ui->tab_affichage->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à modifier.");
        return;
    }



    // Récupérer l'ID de la ligne sélectionnée (colonne 0)
    QModelIndex index = selection->currentIndex();
    int id = ui->tab_affichage->model()->data(index.siblingAtColumn(0)).toInt();

    qDebug() << "ID sélectionné :" << id;

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return;
    }
    // Récupérer les nouvelles valeurs

    QDate date = ui->dateRDV->date();
    QString heure = ui->heureRDV->time().toString("HH:mm");
    QString mode = ui->modeRDV->currentText();
    QString objectif = ui->objectifRDV->text().trimmed();
    QString client = ui->clientRDV->text().trimmed();

    if (date < QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date du rendez-vous doit être aujourd'hui ou ultérieure.");
        return;
    }
    if (client.length() <3) {
        QMessageBox::warning(this, "Erreur", "Le nom doit contenir au moins 3 caractères.");
        return;
    }
    if (objectif.length() < 10) {
        QMessageBox::warning(this, "Erreur", "L'objectif doit contenir au moins 10 caractères.");
        return;
    }


    // Création de l'objet RendezVous et tentative de modification
    RendezVous rdv(id, date, heure, mode, objectif, client);
    bool test = rdv.modifier_RDV(id);

    qDebug() << "Résultat modification : " << test;

    if (test) {
        QMessageBox::information(this, "Succès", "Modification effectuée.");

        // Rafraîchir le tableau
        ui->tab_affichage->setModel(rdv.afficher_RDV());
        ui->tab_affichage->resizeColumnsToContents();

        // Réinitialisation des champs
        ui->dateRDV->setDate(QDate::currentDate());
        ui->heureRDV->setTime(QTime::currentTime());
        ui->modeRDV->setCurrentIndex(0);
        ui->objectifRDV->clear();
        ui->clientRDV->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}


void MainWindow::on_suppRDV_clicked()
{
    QItemSelectionModel *selection = ui->tab_affichage->selectionModel();

    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    QModelIndex index = selection->currentIndex();
    int id = ui->tab_affichage->model()->data(index.siblingAtColumn(0)).toInt();  // Colonne 0 = ID_RDV

    if (id < 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide. Veuillez sélectionner une ligne valide.");
        return;
    }

    // Demande de confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce rendez-vous ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        RendezVous rdv;
        bool test = rdv.supprimer_RDV(id);  // Suppression du rendez-vous

        if (test) {
            QMessageBox::information(this, "Succès", "Rendez-vous supprimé.");
            ui->tab_affichage->setModel(rdv.afficher_RDV());  // Rafraîchir l'affichage
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}




void MainWindow::on_rechercherRDV_textChanged(const QString &text)
{
    RendezVous rdv;
    QSqlQueryModel* model = rdv.recherche_RDV(text); // Appel à la fonction recherche

    if (model)
    {
        ui->tab_affichage->setModel(model); // Mettre à jour l'affichage
    }
}





void MainWindow::on_pdfRDV_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QString(), "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données non établie.");
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString text;
    QTextStream stream(&text);

    stream << "<h2 style='text-align: center;'>Liste des Rendez-vous</h2>";
    stream << "<hr><br>";
    stream << "<table style='width:100%; border-collapse: collapse; font-size: 12px;'>";

    stream << "<tr style='background-color: #f2f2f2;'>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>ID</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Date</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Heure</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Mode</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Objectif</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Client</th>";
    stream << "</tr>";

    QSqlQuery query(db);
    query.prepare("SELECT ID_RDV, DATE_RDV, HEURE_RDV, MODE_RDV, OBJECTIF, NOM_CLIENT FROM RENDEZ_VOUS");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    while (query.next()) {
        stream << "<tr>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("ID_RDV").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("DATE_RDV").toDate().toString("dd/MM/yyyy") << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("HEURE_RDV").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("MODE_RDV").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("OBJECTIF").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("NOM_CLIENT").toString() << "</td>";
        stream << "</tr>";
    }

    stream << "</table>";
    doc.setHtml(text);
    doc.print(&printer);

    QMessageBox::information(this, "PDF", "PDF généré avec succès.");
}


void MainWindow::on_modeRDV_2_clicked()
{
    QSqlQueryModel* model = rdv.Trier_RDV("MODE_RDV");
    ui->tab_affichage->setModel(model);
}


void MainWindow::on_dateRDV_2_clicked()
{
    QSqlQueryModel* model = rdv.Trier_RDV("DATE_RDV");
    ui->tab_affichage->setModel(model);
}


void MainWindow::on_statbuttonRDV_clicked()
{
    QTabWidget *tabWidget = new QTabWidget();

    struct StatInfo {
        QString title;
        QString field;
    };

    QList<StatInfo> stats = {
        {"Répartition par mode", "MODE_RDV"},
        {"Répartition par date", "TO_CHAR(DATE_RDV, 'YYYY-MM-DD')"},
        {"Répartition par objectif", "OBJECTIF"}
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
        QString queryString = "SELECT " + stat.field + ", COUNT(*) AS count FROM RENDEZ_VOUS GROUP BY " + stat.field;
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
    dialog->setWindowTitle("Statistiques des rendez-vous");
    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->addWidget(tabWidget);
    dialog->setLayout(dialogLayout);
    dialog->resize(800, 500);
    dialog->exec();
}




void MainWindow::checkUpcomingRdvNotification()
{
    // Définir le délai avant la notification (5 minutes avant l'heure du rendez-vous)
    QDateTime currentDateTime = QDateTime::currentDateTime();
    qDebug() << "Current DateTime:" << currentDateTime.toString();

    // Requête SQL pour récupérer tous les rendez-vous dans les 5 prochaines minutes
    QSqlQuery query;
    QString startTime = currentDateTime.addSecs(300).toString("HH:mm");
    QString endTime = currentDateTime.addSecs(600).toString("HH:mm");
    qDebug() << "Start Time:" << startTime << "End Time:" << endTime;

    query.prepare("SELECT ID_RDV, DATE_RDV, HEURE_RDV FROM RENDEZ_VOUS WHERE "
                  "DATE_RDV = :date AND "
                  "HEURE_RDV BETWEEN :startTime AND :endTime");
    query.bindValue(":date", currentDateTime.date());
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);

    if (query.exec()) {
        int count = 0;
        while (query.next()) {
            int idRdv = query.value("ID_RDV").toInt();
            QString heureRdv = query.value("HEURE_RDV").toString();
            qDebug() << "Rendez-vous trouvé avec ID:" << idRdv << "à" << heureRdv;

            // Si un rendez-vous est trouvé, afficher un pop-up moderne
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Rendez-vous imminent");
            msgBox.setText(QString("Vous avez un rendez-vous à %1 dans 5 minutes.").arg(heureRdv));

            // Appliquer un stylesheet moderne pour l'apparence du message
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: #2d2d2d;" // Fond sombre
                "    border-radius: 10px;"        // Bordure arrondie
                "    color: white;"               // Texte blanc
                "    font-family: 'Segoe UI';"    // Police moderne
                "    font-size: 14px;"            // Taille de la police
                "    padding: 20px;"              // Espacement interne
                "}"
                "QPushButton {"
                "    background-color: #3a3a3a;" // Fond des boutons
                "    color: white;"               // Texte des boutons en blanc
                "    border-radius: 5px;"         // Bordures arrondies
                "    padding: 8px 16px;"          // Espacement des boutons
                "}"
                "QPushButton:hover {"
                "    background-color: #5c5c5c;" // Changer la couleur au survol
                "}"
                );

            // Afficher la fenêtre modale
            msgBox.exec();
            count++;
        }
        if (count == 0) {
            qDebug() << "Aucun rendez-vous trouvé dans la plage de temps.";
        }
    } else {
        qDebug() << "Erreur dans la requête SQL:" << query.lastError();
    }
}

void MainWindow::updateRdvButton()
{
    // Obtenir la date actuelle
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDate currentDate = currentDateTime.date();

    // Requête SQL pour récupérer le nombre de rendez-vous pour la journée
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM RENDEZ_VOUS WHERE DATE_RDV = :date");
    query.bindValue(":date", currentDate);

    if (query.exec()) {
        query.next();
        int count = query.value(0).toInt();  // Nombre de rendez-vous pour la journée
        QString buttonText = QString("%1").arg(count); // Texte du bouton avec le nombre

        // Mettre à jour le texte du bouton
        ui->btnRdvJour->setText(buttonText);

        // Appliquer un style en rouge au texte du bouton uniquement
        ui->btnRdvJour->setStyleSheet("color: red; font-size: 16px;");
    } else {
        qDebug() << "Erreur dans la requête SQL:" << query.lastError();
    }
}



void MainWindow::on_btnRdvJour_clicked()
{
    // Obtenir la date actuelle
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDate currentDate = currentDateTime.date();

    // Requête SQL pour récupérer tous les rendez-vous pour la journée
    QSqlQuery query;
    query.prepare("SELECT ID_RDV, DATE_RDV, HEURE_RDV, OBJECTIF, NOM_CLIENT FROM RENDEZ_VOUS WHERE DATE_RDV = :date");
    query.bindValue(":date", currentDate);

    if (query.exec()) {
        QString rendezvousDetails;
        QListWidget *listWidget = new QListWidget(this);  // Création d'un QListWidget pour afficher les rendez-vous

        // Style de base pour le QListWidget
        listWidget->setStyleSheet(
            "QListWidget {"
            "    background-color: #2d2d2d;"  // Fond sombre pour la liste
            "    color: white;"                // Texte en blanc
            "    border-radius: 8px;"          // Bordures arrondies
            "    font-family: 'Segoe UI';"     // Police moderne
            "    font-size: 14px;"             // Taille de la police
            "    padding: 10px;"               // Padding pour espacement interne
            "}"
            "QListWidget::item {"
            "    background-color: #444444;"  // Fond sombre pour les items
            "    border-radius: 5px;"          // Bordure arrondie pour chaque élément
            "    margin: 5px 0px;"             // Espacement entre les items
            "    padding: 10px;"               // Espacement interne des items
            "}"
            "QListWidget::item:hover {"
            "    background-color: #5c5c5c;"  // Changer la couleur au survol
            "}"
            );

        while (query.next()) {
            QString heureRdv = query.value("HEURE_RDV").toString();
            QString objectif = query.value("OBJECTIF").toString();
            QString clientName = query.value("NOM_CLIENT").toString();

            // Formatage des données à afficher dans chaque item de la liste
            QString itemText = QString("Client: %1\nHeure: %2\nObjectif: %3")
                                   .arg(clientName)
                                   .arg(heureRdv)
                                   .arg(objectif);

            // Ajouter l'élément à la liste
            QListWidgetItem *item = new QListWidgetItem(itemText);
            listWidget->addItem(item);
        }

        // Si aucun rendez-vous, ajouter un message pour l'indiquer
        if (listWidget->count() == 0) {
            QListWidgetItem *item = new QListWidgetItem("Aucun rendez-vous aujourd'hui.");
            listWidget->addItem(item);
        }

        // Créer une fenêtre modale (QDialog) pour afficher les rendez-vous
        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(listWidget);

        // Configurer la taille de la fenêtre modale
        dialog->setWindowTitle("Rendez-vous du jour");
        dialog->resize(600, 400);  // Ajustez la taille de la fenêtre selon vos besoins

        // Afficher la fenêtre modale
        dialog->exec();  // Afficher le pop-up
    } else {
        qDebug() << "Erreur dans la requête SQL:" << query.lastError();
    }
}



void MainWindow::on_calenderierRDV_clicked()
{
    ui->calander_rdv=r_tmp->getAllRDV_RDV(ui->calander_rdv);

    if(ui->calander_rdv->isVisible())
    {
        ui->calander_rdv->hide();
    }
    else
    {
        ui->calander_rdv->show();
    }
    ui->tab_affichage->setModel(r_tmp->afficher_RDV());

}

void MainWindow::on_calander_rdv_clicked(const QDate &date)
{
    RendezVous r;
    QSqlQueryModel* model = r.Select_by_date_r_RDV(date);
    ui->tab_affichage->setModel(model);
}




