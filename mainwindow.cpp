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

//hammmaaaaaaaaaaaaaaaaaa


#include "loginwindow.h"
#include "ui_editemployeedialog.h"
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QDesktopServices>
#include <QtCharts>
#include <QSqlQuery>
#include <QTabWidget>
#include <QDialog>
#include <QVBoxLayout>
//hammmaaaaaaaaaaaaaaaaa
ButtonDelegate::ButtonDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    deleteButton = new QPushButton("Supprimer");
    editButton = new QPushButton("Modifier");
}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 10 || index.column() == 11) {
        QStyleOptionButton buttonOption;
        buttonOption.rect = option.rect.adjusted(5, 5, -5, -5);

        if (index.column() == 10) {
            buttonOption.text = "Supprimer";
        } else if (index.column() == 11) {
            buttonOption.text = "Modifier";
        }

        QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (index.column() == 10) {
            emit deleteButtonClicked(index);
            return true;
        } else if (index.column() == 11) {
            emit editButtonClicked(index);
            return true;
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

EditEmployeeDialog::EditEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEmployeeDialog)
{
    ui->setupUi(this);
    ui->comboBox_specialite->addItems({"Chef de projet", "Responsable Service Client", "Responsable Ressources Humaines", "Responsable Commercial", "Responsable Formation"});
    ui->comboBox_disponibilite->addItems({"Disponible", "Occupe"});
    connect(ui->saveButton, &QPushButton::clicked, this, &EditEmployeeDialog::on_saveButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &EditEmployeeDialog::on_cancelButton_clicked);
}

EditEmployeeDialog::~EditEmployeeDialog()
{
    delete ui;
}

void EditEmployeeDialog::setEmployeeData(QString nom, QString prenom, QString email, int telephone, QString specialite, int exp, QString dispo, QString log, QString mdp)
{
    ui->lineEdit_nom->setText(nom);
    ui->lineEdit_prenom->setText(prenom);
    ui->lineEdit_email->setText(email);
    ui->lineEdit_telephone->setText(QString::number(telephone));
    ui->comboBox_specialite->setCurrentText(specialite);
    ui->lineEdit_experience->setText(QString::number(exp));
    ui->comboBox_disponibilite->setCurrentText(dispo);
    ui->lineEdit_login->setText(log);
    ui->lineEdit_mdp->setText(mdp);
}

QString EditEmployeeDialog::getNom() const { return ui->lineEdit_nom->text(); }
QString EditEmployeeDialog::getPrenom() const { return ui->lineEdit_prenom->text(); }
QString EditEmployeeDialog::getEmail() const { return ui->lineEdit_email->text(); }
int EditEmployeeDialog::getTelephone() const { return ui->lineEdit_telephone->text().toInt(); }
QString EditEmployeeDialog::getSpecialite() const { return ui->comboBox_specialite->currentText(); }
int EditEmployeeDialog::getExperience() const { return ui->lineEdit_experience->text().toInt(); }
QString EditEmployeeDialog::getDisponibilite() const { return ui->comboBox_disponibilite->currentText(); }
QString EditEmployeeDialog::getLogin() const { return ui->lineEdit_login->text(); }
QString EditEmployeeDialog::getMdp() const { return ui->lineEdit_mdp->text(); }
void EditEmployeeDialog::setID(int id) { employeeID = id; }
int EditEmployeeDialog::getID() const { return employeeID; }

void EditEmployeeDialog::on_saveButton_clicked()
{
    accept();
}

void EditEmployeeDialog::on_cancelButton_clicked()
{
    reject();
}


//hamaaaaaaaaaaaaaaaaaa
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize employee table
    ui->tableViewEMP->setModel(Etmp.afficherem());
    ui->tableViewEMP->resizeColumnsToContents();
    rdvbox = new QVBoxLayout();

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
    //hammaaaaaaaaaaa
    // Hide the IDEMPLOYE column (column 0)
    ui->tableViewEMP->setColumnHidden(0, true);

    // Set the custom delegate for the buttons
    ButtonDelegate *buttonDelegate = new ButtonDelegate(this);
    ui->tableViewEMP->setItemDelegateForColumn(10, buttonDelegate); // Column 10: Supprimer
    ui->tableViewEMP->setItemDelegateForColumn(11, buttonDelegate); // Column 11: Modifier

    // Connect button signals to slots
    connect(buttonDelegate, &ButtonDelegate::deleteButtonClicked, this, &MainWindow::onDeleteButtonClicked);
    connect(buttonDelegate, &ButtonDelegate::editButtonClicked, this, &MainWindow::onEditButtonClicked);

    ui->tableViewEMP->resizeColumnsToContents();

    //hammaaaaaaaaaaaaaa
}

MainWindow::~MainWindow()
{
    delete ui;
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
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
//hamaaaaaaaaaaaaaa
// Validation function for name (only alphabets)
bool MainWindow::isValidName(const QString& name) const {
    QRegularExpression regex("^[A-Za-z]+$");
    return regex.match(name).hasMatch();
}

// Validation function for email (must follow a valid email format)
bool MainWindow::isValidEmail(const QString& email) const {
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex.match(email).hasMatch();
}

// Validation function for phone (must be exactly 8 digits)
bool MainWindow::isValidPhone(int phone) const {
    QString phoneStr = QString::number(phone);
    QRegularExpression regex("^\\d{8}$");
    return regex.match(phoneStr).hasMatch();
}

// Validation function for experience (must be between 0 and 50)
bool MainWindow::isValidExperience(int experience) const {
    return experience >= 0 && experience <= 50;
}

// Validation function for password (must contain at least 1 uppercase, 3 digits, 1 special character, and be at least 8 characters long)
bool MainWindow::isValidPassword(const QString& password) const {
    QRegularExpression regex("^(?=.*[A-Z])(?=.*\\d{3,})(?=.*[!@#$%^&*])(?=.*[a-z]).{8,}$");
    return regex.match(password).hasMatch();
}
void MainWindow::on_pushButton_ajouterEMP_clicked()
{
    qDebug() << "ffafa" ;
    QString NOM = ui->lineEdit_nomEMP->text();
    QString PRENOM = ui->lineEdit_prenomEMP->text();
    QString EMAIL = ui->lineEdit_emailEMP->text();
    QString SPECIALITE = ui->specialiteEMP->currentText();
    bool ok1, ok2;
    int TELEPHONE = ui->lineEdit_telephoneEMP->text().toInt(&ok1);
    int EXPERIENCE = ui->lineEdit_experienceEMP->text().toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer des nombres valides pour le téléphone et l'expérience.");
        return;
    }

    QString DISPONIBILITE = ui->dispoEMP->currentText();
    QString LOGIN = ui->lineEdit_loginEMP->text();
    QString MDP = ui->lineEdit_mdpEMP->text();

    // Check if all fields are filled
    if (NOM.isEmpty() || PRENOM.isEmpty() || EMAIL.isEmpty() || SPECIALITE.isEmpty() ||
        !ok1 || !ok2 || DISPONIBILITE.isEmpty() || LOGIN.isEmpty() || MDP.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Validate name and surname
    if (!isValidName(NOM) || !isValidName(PRENOM)) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }

    // Validate email
    if (!isValidEmail(EMAIL)) {
        QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
        return;
    }

    // Validate phone
    if (!isValidPhone(TELEPHONE)) {
        QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // Validate experience
    if (!isValidExperience(EXPERIENCE)) {
        QMessageBox::warning(this, "Erreur", "L'expérience ne doit pas dépasser 50.");
        return;
    }

    // Validate password
    if (!isValidPassword(MDP)) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une majuscule, trois chiffres, un caractère spécial, et avoir une longueur minimale de 8 caractères.");
        return;
    }

    em E(NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN, MDP);

    bool test = E.ajouterem();
    ui->lineEdit_nomEMP->clear();
    ui->lineEdit_prenomEMP->clear();
    ui->lineEdit_emailEMP->clear();
    ui->lineEdit_telephoneEMP->clear();
    ui->specialiteEMP->setCurrentIndex(0);
    ui->lineEdit_experienceEMP->clear();
    ui->dispoEMP->setCurrentIndex(0);
    ui->lineEdit_loginEMP->clear();
    ui->lineEdit_mdpEMP->clear();
    if (test) {
        ui->tableViewEMP->setModel(Etmp.afficherem());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::onDeleteButtonClicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the IDEMPLOYE value from the hidden column (column 0)
    QModelIndex idIndex = ui->tableViewEMP->model()->index(row, 0);
    int id = ui->tableViewEMP->model()->data(idIndex).toInt();

    // Call the supprimer method
    bool success = Etmp.supprimerem(id);

    if (success) {
        // Refresh the table view
        ui->tableViewEMP->setModel(Etmp.afficherem());
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::onEditButtonClicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the employee data from the model
    QModelIndex idIndex = ui->tableViewEMP->model()->index(row, 0);
    int id = ui->tableViewEMP->model()->data(idIndex).toInt();

    QString nom = ui->tableViewEMP->model()->index(row, 1).data().toString();
    QString prenom = ui->tableViewEMP->model()->index(row, 2).data().toString();
    QString email = ui->tableViewEMP->model()->index(row, 3).data().toString();
    int telephone = ui->tableViewEMP->model()->index(row, 4).data().toInt();
    QString specialite = ui->tableViewEMP->model()->index(row, 5).data().toString();
    int experience = ui->tableViewEMP->model()->index(row, 6).data().toInt();
    QString disponibilite = ui->tableViewEMP->model()->index(row, 7).data().toString();
    QString login = ui->tableViewEMP->model()->index(row, 8).data().toString();
    QString mdp = ui->tableViewEMP->model()->index(row, 9).data().toString();

    // Open the edit dialog
    EditEmployeeDialog dialog(this);
    dialog.setID(id); // Set the ID internally
    dialog.setEmployeeData(nom, prenom, email, telephone, specialite, experience, disponibilite, login, mdp);

    if (dialog.exec() == QDialog::Accepted) {
        // Retrieve the updated data from the dialog
        QString newNom = dialog.getNom();
        QString newPrenom = dialog.getPrenom();
        QString newEmail = dialog.getEmail();
        int newTelephone = dialog.getTelephone();
        QString newSpecialite = dialog.getSpecialite();
        int newExperience = dialog.getExperience();
        QString newDisponibilite = dialog.getDisponibilite();
        QString newLogin = dialog.getLogin();
        QString newMdp = dialog.getMdp();

        // Validate the updated fields
        if (newNom.isEmpty() || newPrenom.isEmpty() || newEmail.isEmpty() || newSpecialite.isEmpty() ||
            newDisponibilite.isEmpty() || newLogin.isEmpty() || newMdp.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
            return;
        }

        if (!isValidName(newNom) || !isValidName(newPrenom)) {
            QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
            return;
        }

        if (!isValidEmail(newEmail)) {
            QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
            return;
        }

        if (!isValidPhone(newTelephone)) {
            QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir exactement 8 chiffres.");
            return;
        }

        if (!isValidExperience(newExperience)) {
            QMessageBox::warning(this, "Erreur", "L'expérience ne doit pas dépasser 50.");
            return;
        }

        if (!isValidPassword(newMdp)) {
            QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une majuscule, trois chiffres, un caractère spécial, et avoir une longueur minimale de 8 caractères.");
            return;
        }

        // If all validations pass, proceed to update the employee
        bool success = Etmp.modifierem(dialog.getID(), newNom, newPrenom, newEmail, newTelephone, newSpecialite, newExperience, newDisponibilite, newLogin, newMdp);

        if (success) {
            // Refresh the table view
            ui->tableViewEMP->setModel(Etmp.afficherem());
            QMessageBox::information(this, "Succès", "Employé modifié avec succès.");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification.");
        }
    }
}

void MainWindow::on_lineEditEMP_textChanged(const QString &arg1)
{
    QString searchText = arg1.trimmed();

    if (searchText.isEmpty()) {
        // If search field is empty, show all employees
        ui->tableViewEMP->setModel(Etmp.afficherem());
        return;
    }

    // Create a new model
    QSqlQueryModel *model = new QSqlQueryModel();

    // Prepare the query with multiple search conditions (Oracle-specific syntax)
    QString queryStr = "SELECT IDEMPLOYE, NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, "
                       "EXPERIENCE, DISPONIBILITE, LOGIN, MDP FROM EMPLOYE "
                       "WHERE (NOM LIKE :search OR "
                       "PRENOM LIKE :search OR "
                       "SPECIALITE LIKE :search OR "
                       "TO_CHAR(IDEMPLOYE) LIKE :search OR "
                       "TO_CHAR(EXPERIENCE) LIKE :search)";

    // Create and execute the query
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":search", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Search query error:" << query.lastError().text();
        delete model; // Clean up the model if query fails
        return;
    }

    // Set the query using the new recommended approach
    model->setQuery(std::move(query));

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEMPLOYE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SPECIALITE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EXPERIENCE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("LOGIN"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("MDP"));

    // Add empty columns for buttons (to match the original display)
    model->insertColumn(10); // Column 10: Supprimer
    model->insertColumn(11); // Column 11: Modifier

    // Set headers for the new columns
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Modifier"));

    ui->tableViewEMP->setModel(model);
    ui->tableViewEMP->setColumnHidden(0, true); // Hide the IDEMPLOYE column
}
void MainWindow::on_dispoSortButton_clicked()
{
    static bool ascending = true;
    QString order = ascending ? "DISPONIBILITE" : "DISPONIBILITE_DESC";
    ascending = !ascending;

    QSqlQueryModel* model = Etmp.Trier_Employe(order);
    if (model) {
        ui->tableViewEMP->setModel(model);
        ui->tableViewEMP->setColumnHidden(0, true);
    }
}

void MainWindow::on_emailSortButton_clicked()
{
    static bool ascending = true;
    QString order = ascending ? "EMAIL" : "EMAIL_DESC";
    ascending = !ascending;

    QSqlQueryModel* model = Etmp.Trier_Employe(order);
    if (model) {
        ui->tableViewEMP->setModel(model);
        ui->tableViewEMP->setColumnHidden(0, true);
    }
}

void MainWindow::on_telephoneSortButton_clicked()
{
    static bool ascending = true;
    QString order = ascending ? "TELEPHONE" : "TELEPHONE_DESC";
    ascending = !ascending;

    QSqlQueryModel* model = Etmp.Trier_Employe(order);
    if (model) {
        ui->tableViewEMP->setModel(model);
        ui->tableViewEMP->setColumnHidden(0, true);
    }
}
void MainWindow::on_pdfButtonEMP_clicked()
{
    // Get save file name
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QString(), "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;

    // Ensure .pdf extension
    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    // Check database connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données non établie.");
        return;
    }

    // Set up PDF printer
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    // Create HTML document
    QTextDocument doc;
    QString html;
    QTextStream stream(&html);

    // HTML header and title
    stream << "<html><body>";
    stream << "<h2 style='text-align: center;'>Liste des Employés</h2>";
    stream << "<hr><br>";
    stream << "<table style='width:100%; border-collapse: collapse; font-size: 12px;'>";

    // Table headers (excluding ID and button columns)
    stream << "<tr style='background-color: #f2f2f2;'>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Nom</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Prénom</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Email</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Téléphone</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Spécialité</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Expérience</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Disponibilité</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Login</th>";
    stream << "</tr>";

    // Query employee data
    QSqlQuery query(db);
    query.prepare("SELECT NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN FROM EMPLOYE");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // Add table rows
    while (query.next()) {
        stream << "<tr>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("NOM").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("PRENOM").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("EMAIL").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("TELEPHONE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("SPECIALITE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("EXPERIENCE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("DISPONIBILITE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("LOGIN").toString() << "</td>";
        stream << "</tr>";
    }

    stream << "</table></body></html>";
    doc.setHtml(html);

    // Print to PDF
    doc.print(&printer);

    // Show success message
    QMessageBox::information(this, "PDF", "Liste des employés exportée en PDF avec succès.");

    // Open the PDF automatically
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}
void MainWindow::on_statbuttonEMP_clicked()
{
    QTabWidget *tabWidget = new QTabWidget();

    struct StatInfo {
        QString title;
        QString field;
    };

    // Define the statistics we want to show
    QList<StatInfo> stats = {
        {"Répartition par spécialité", "SPECIALITE"},
        {"Répartition par disponibilité", "DISPONIBILITE"},
        {"Répartition par expérience", "EXPERIENCE"}
    };

    // Color palette for the pie charts
    QStringList colors = {
        "#ff6f61", "#6b5b95", "#88b04b", "#f7cac9",
        "#92a8d1", "#955251", "#b565a7", "#009688",
        "#f4b400", "#607d8b"
    };

    // Create a tab for each statistic
    for (const StatInfo &stat : stats)
    {
        QPieSeries *series = new QPieSeries();

        // Build and execute the query
        QSqlQuery query;
        QString queryString = QString("SELECT %1, COUNT(*) FROM EMPLOYE GROUP BY %1").arg(stat.field);
        query.prepare(queryString);

        if (query.exec()) {
            while (query.next()) {
                QString label = query.value(0).toString();
                int count = query.value(1).toInt();

                // For experience, add "years" to the label
                if (stat.field == "EXPERIENCE") {
                    label = QString("%1 ans").arg(label);
                }

                if (!label.isEmpty()) {
                    QPieSlice *slice = series->append(label, count);
                    slice->setLabelVisible(true);
                    slice->setExploded(true);
                    slice->setLabel(QString("%1\n%2 employés").arg(label).arg(count));
                }
            }
        } else {
            qDebug() << "Query error:" << query.lastError().text();
            continue;
        }

        // Apply colors to slices
        int colorIndex = 0;
        for (QPieSlice *slice : series->slices()) {
            slice->setColor(QColor(colors[colorIndex % colors.size()]));
            colorIndex++;
        }

        // Configure the chart
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(stat.title);
        chart->setTitleFont(QFont("Arial", 14, QFont::Bold));
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setFont(QFont("Arial", 9));

        // Create chart view
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Create tab content
        QWidget *tab = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(tab);
        layout->addWidget(chartView);
        tab->setLayout(layout);

        // Add tab to the tab widget
        tabWidget->addTab(tab, stat.title);
    }

    // Create and show the dialog
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des employés");
    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->addWidget(tabWidget);
    dialog->setLayout(dialogLayout);
    dialog->resize(900, 600);
    dialog->exec();
}
void MainWindow::on_logoutButton_clicked()
{
    // Close the current window
    this->close();

    // Show the login window again
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
}
//hammaaaaaaaaaaaaaaaaaaaaaaa

// In mainwindow.cpp
void MainWindow::setRdvBoxVisible(bool visible)
{
    if (ui->rdvbox) {  // Make sure rdvbox exists in your UI
        ui->rdvbox->setVisible(visible);
    }
}

void MainWindow::setEmpBoxVisible(bool visible)
{
    if (ui->empbox) {  // Make sure empbox exists in your UI
        ui->empbox->setVisible(visible);
    }
}




