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

//ferreeeesssss
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QFileInfo>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QTimer>


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
#include "qrcodegen.hpp"
#include "smsnotif.h"


#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QSqlQuery>

#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextEdit>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QScopedPointer>
//akram
const QString HF_API_TOKEN = "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";
//ferreesss
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

    //ferrreeessssss
    // Initialize Arduino
    arduino = new Arduino(this);
    setupArduinoConnection();

    // Initialize the table view
    ui->tableView_2c->setModel(cli.afficher_client());
    ui->tableView_2c->resizeColumnsToContents();

    populateEmployeeComboBox();
    populateTypeComboBox();
    populateSpecialiteComboBox();

    // Connect the search button
    connect(ui->pushButton_search_mod_2c, &QPushButton::clicked, this, &MainWindow::on_pushButton_search_mod_2c_clicked);
    connect(ui->pushButton_pdf_2c, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_2c_clicked);
    connect(ui->pushButton_trier_nom_2c, &QPushButton::clicked, this, &MainWindow::on_trier_nom_2c_clicked);
    connect(ui->pushButton_trier_date_2c, &QPushButton::clicked, this, &MainWindow::on_trier_date_2c_clicked);
    connect(ui->pushButton_trier_type_2c, &QPushButton::clicked, this, &MainWindow::on_trier_type_2c_clicked);
    connect(ui->pushButton_6c, &QPushButton::clicked, this, &MainWindow::on_pushbutton_6c_clicked);

    // Connect real-time search
    connect(ui->rechercher_2c, &QLineEdit::textChanged, this, &MainWindow::on_rechercher_2c_textChanged);


    //fereeesssssssss
    //moataz
    manager = new QNetworkAccessManager(this);
    connect(ui->confirmer_res, &QPushButton::clicked, this, &MainWindow::on_pushButton_confirmer_res_clicked);
    connect(ui->supprimerr_res, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimerr_res_clicked);
    connect(ui->modifier_res, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_res_clicked);
    connect(ui->confirmermodification_res, &QPushButton::clicked, this, &MainWindow::on_pushButton_confirmermodification_res_clicked);
    //connect(ui->generatePDFButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_generatePDFButton_clicked); // Added for PDF generation
    connect(ui->statbutton_res, &QPushButton::clicked, this, &MainWindow::on_statbutton_res_clicked);
    connect(ui->pdfButton_res, &QPushButton::clicked, this, &MainWindow::on_pdfButton_res_clicked);
    connect(ui->qrCodeButton_res, &QPushButton::clicked, this, &MainWindow::on_qrCodeButton_clicked);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onSMSResponseReceived);
    connect(ui->pushButton_envoyer_res, &QPushButton::clicked, this, &MainWindow::on_pushButton_envoyer_res_clicked);

    //connect(ui->search, &QPushButton::clicked, this, &MainWindow::on_pushButton_search_clicked);
    ui->table_res->setModel(R.afficher_res());

    //moataz
    //akram
    ui->tableView->setModel(pro.afficher_projet());

    ButtonDelegate *projButtonDelegate = new ButtonDelegate(this);
    ui->tableView->setItemDelegateForColumn(6, projButtonDelegate); // Delete button column
    ui->tableView->setItemDelegateForColumn(7, projButtonDelegate); // Edit button column
    connect(projButtonDelegate, &ButtonDelegate::deleteButtonClicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(projButtonDelegate, &ButtonDelegate::editButtonClicked, this, &MainWindow::on_pushButton_modifier_clicked);

    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_search_clicked);
    connect(ui->pushButton_statistiques, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistiques_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_up_clicked);
    connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_down_clicked);
    connect(ui->pushButton_down, &QPushButton::clicked, this, &MainWindow::openChatbot);
    if (!m_networkManager) {
        qCritical() << "Failed to initialize network manager";
    }

    // Adjust column widths
    ui->tableView->resizeColumnsToContents();
    //akram
}

MainWindow::~MainWindow()
{
    delete ui;
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
    if (!m_chatbotDialog.isNull()) {
        m_chatbotDialog->deleteLater();
    }
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

//feeeeereeeesssss
void MainWindow::on_pushButton_ajouter_2c_clicked()
{
    // Validate required fields
    if(ui->nom_client_2c->text().isEmpty() ||
        ui->prenom_client_2c->text().isEmpty() ||
        ui->email_client_2c->text().isEmpty() ||
        ui->tel_client_2c->text().isEmpty() ||
        ui->type_client_2c->currentText().isEmpty() ||
        ui->adresse_client_2c->text().isEmpty() ||
        ui->specialite_client_2c->currentText().isEmpty() ||
        ui->id_emp_2c->currentText().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Veuillez remplir tous les champs obligatoires");
        return;
    }


    // Validate name contains only letters
    QRegularExpression nameRegex("^[a-zA-Z\\s]+$");
    if(!nameRegex.match(ui->nom_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "Warning", "Le nom ne doit contenir que des lettres");
        return;
    }

    if(!nameRegex.match(ui->prenom_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "Warning", "Le prénom ne doit contenir que des lettres");
        return;
    }

    // Validate email format
    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                                  QRegularExpression::CaseInsensitiveOption);
    if(!emailRegex.match(ui->email_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "Warning", "Email invalide");
        return;
    }

    // Validate phone number (Tunisian format)
    QRegularExpression phoneRegex("^[0-9]{8}$");
    if(!phoneRegex.match(ui->tel_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "Warning", "Numéro de téléphone doit contenir 8 chiffres");
        return;
    }


    // Get employee info from combo box
    QVariantList empData = ui->id_emp_2c->currentData().toList();
    int id_employe = empData[0].toInt();
    QString nom_employe = empData[1].toString();


    // Get values
    QString prenom = ui->prenom_client_2c->text();
    QString nom = ui->nom_client_2c->text();
    QString email = ui->email_client_2c->text();
    QString tel = ui->tel_client_2c->text();
    QString adresse = ui->adresse_client_2c->text();
    QString date = ui->date_inscri_client_2c->date().toString("yyyy-MM-dd");
    QString type = ui->type_client_2c->currentText();
    QString specialite = ui->specialite_client_2c->currentText();

    QString smokeStatus = "Non";
    if (arduino && arduino->isSmokeDetected()) {  // We'll need to add this method to Arduino class
        smokeStatus = "Oui";
    }
    // Set values
    cli.setNom_client(nom);
    cli.setPrenom_client(prenom);
    cli.setEmail_client(email);
    cli.setTel_client(tel);
    cli.setType_client(type);
    cli.setAdresse_client(adresse);
    cli.setDate_client(date);
    cli.setSpecialite_client(specialite);
    cli.setId_emp(id_employe);
    cli.setNom_emp(nom_employe);
    cli.setSmokeDetected(smokeStatus);

    if (cli.ajouter_client()) {
        // Refresh table
        QSqlQueryModel *model = cli.afficher_client();
        ui->tableView_2c->setModel(model);
        ui->tableView_2c->resizeColumnsToContents();

        QMessageBox::information(this, "Success", "Client ajouté avec succès");

        // Send welcome SMS
        SMSSender smsSender;
        QString message = QString("Bonjour %1 %2,\nMerci pour votre inscription!").arg(ui->prenom_client_2c->text()).arg(ui->nom_client_2c->text());
        smsSender.sendSMS(ui->tel_client_2c->text(), message);

    } else {
        QMessageBox::critical(this, "erreur", "Échec de l'ajout du client");
    }
    // Clear input fields
    ui->prenom_client_2c->clear();
    ui->nom_client_2c->clear();
    ui->email_client_2c->clear();
    ui->tel_client_2c->clear();
    ui->type_client_2c->setCurrentIndex(0);
    ui->adresse_client_2c->clear();
    ui->specialite_client_2c->setCurrentIndex(0);
    ui->id_emp_2c->setCurrentIndex(0);
}

void MainWindow::on_pushButton_supprimer_2c_clicked()
{
    if(ui->id_client_supp_2c->text().isEmpty()) {
        QMessageBox::warning(this, "erreur", "Veuillez saisir un identifiant client à supprimer");
        return;
    }

    int id = ui->id_client_supp_2c->text().toInt();

    // Check if client exists
    if (!cli.clientExists_client(id)) {
        QMessageBox::warning(this, "erreur", "L'ID client n'existe pas");
        return;
    }

    bool test = cli.supprimer_client(id);

    if(test) {
        // Refresh the table view
        QSqlQueryModel *model = cli.afficher_client();
        if(model) {
            ui->tableView_2c->setModel(model);
            ui->tableView_2c->resizeColumnsToContents();
        }

        QMessageBox::information(this, "Success", "Client supprimé avec succès");

    } else {
        QMessageBox::critical(this, "erreur", "Échec de la suppression du client");
    }
    ui->id_client_supp_2c->clear();
}

void MainWindow::on_tableView_2c_clicked(const QModelIndex &index)
{
    // Vérification de l'index
    if (!index.isValid()) {
        qWarning() << "Index non valide.";
        return; // Si l'index est invalide, on quitte la fonction
    }

    int row = index.row();
    QAbstractItemModel *model = ui->tableView_2c->model();

    // Get data from the selected row
    QString id_client = model->data(model->index(row, 0)).toString();
    QString prenom_client = model->data(model->index(row, 1)).toString();
    QString nom_client = model->data(model->index(row, 2)).toString();
    QString email_client = model->data(model->index(row, 3)).toString();
    QString tel_client = model->data(model->index(row, 4)).toString();
    QString type_client = model->data(model->index(row, 5)).toString();
    QString adresse_client = model->data(model->index(row, 6)).toString();
    QString date_inscri_client = model->data(model->index(row, 7)).toString();
    QString specialite_client = model->data(model->index(row, 8)).toString();
    QString id_emp = model->data(model->index(row, 9)).toString();
    QString nom_emp = model->data(model->index(row, 10)).toString();

    // Update the form fields
    ui->prenom_client_2c->setText(prenom_client);
    ui->nom_client_2c->setText(nom_client);
    ui->email_client_2c->setText(email_client);
    ui->tel_client_2c->setText(tel_client);
    ui->adresse_client_2c->setText(adresse_client);

    int specialiteIndex = ui->specialite_client_2c->findText(specialite_client);
    if (specialiteIndex != -1) {
        ui->specialite_client_2c->setCurrentIndex(specialiteIndex);
    }
    int typeIndex = ui->type_client_2c->findText(type_client);
    if (typeIndex != -1) {
        ui->type_client_2c->setCurrentIndex(typeIndex);
    }

    // Set the combo box value
    int comboIndex = ui->id_emp_2c->findData(QVariantList() << id_emp << nom_emp);
    if (comboIndex != -1) {
        ui->id_emp_2c->setCurrentIndex(comboIndex);
    } else {
        ui->id_emp_2c->setCurrentIndex(0);
    }

    // Store original values for modification checks
    originalEmpId = id_emp;
    originalEmpName = nom_emp;

    // Handle date
    QDate date = QDate::fromString(date_inscri_client, "yyyy-MM-dd");
    if(date.isValid()) {
        ui->date_inscri_client_2c->setDate(date);
    } else {
        qDebug() << "Format de date invalide:" << date_inscri_client;
        ui->date_inscri_client_2c->setDate(QDate::currentDate());
    }
}

void MainWindow::on_pushButton_modifier_2c_clicked()
{

    // Get the selected employee from combo box
    QVariantList empData = ui->id_emp_2c->currentData().toList();
    if (empData.size() < 2) {
        QMessageBox::warning(this, "erreur", "Veuillez sélectionner un employé valide");
        return;
    }

    int id_employe = empData[0].toInt();
    QString nom_employe = empData[1].toString();

    // Validate required fields
    if(ui->nom_client_2c->text().isEmpty() ||
        ui->prenom_client_2c->text().isEmpty() ||
        ui->email_client_2c->text().isEmpty() ||
        ui->tel_client_2c->text().isEmpty() ||
        ui->type_client_2c->currentText().isEmpty() ||
        ui->adresse_client_2c->text().isEmpty() ||
        ui->specialite_client_2c->currentText().isEmpty()) {
        QMessageBox::warning(this, "erreur", "Please fill all required fields");
        return;
    }

    QRegularExpression nameRegex("^[a-zA-Z\\s]+$");
    if(!nameRegex.match(ui->nom_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "erreur", "Le nom ne doit contenir que des lettres");
        return;
    }

    if(!nameRegex.match(ui->prenom_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "Warning", "Le prénom ne doit contenir que des lettres");
        return;
    }

    // Validate email format
    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                                  QRegularExpression::CaseInsensitiveOption);
    if(!emailRegex.match(ui->email_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "erreur", "Email invalide");
        return;
    }

    // Validate phone number (Tunisian format)
    QRegularExpression phoneRegex("^[0-9]{8}$");
    if(!phoneRegex.match(ui->tel_client_2c->text()).hasMatch()) {
        QMessageBox::warning(this, "erreur", "Numéro de téléphone doit contenir 8 chiffres");
        return;
    }



    // Get values from form
    QString prenom = ui->prenom_client_2c->text();
    QString nom = ui->nom_client_2c->text();
    QString email = ui->email_client_2c->text();
    QString tel = ui->tel_client_2c->text();
    QString adresse = ui->adresse_client_2c->text();
    QString date = ui->date_inscri_client_2c->date().toString("yyyy-MM-dd");
    QString type = ui->type_client_2c->currentText();
    QString specialite = ui->specialite_client_2c->currentText();
    int id = ui->id_client_mod_2c->text().toInt();

    // Set employee name
    cli.setNom_emp(nom_employe);

    // Call modifier with original_id_emp
    bool test = cli.modifier_client(id, nom, prenom, email, tel, type, adresse, date, specialite, id_employe);

    if(test) {
        // Refresh the table view
        QSqlQueryModel *model = cli.afficher_client();
        if(model) {
            ui->tableView_2c->setModel(model);
            ui->tableView_2c->resizeColumnsToContents();
        }
        QMessageBox::information(this, "Success", "Client mis à jour avec succès");
    } else {
        QMessageBox::critical(this, "erreur", "Échec de la mise à jour du client. L'identifiant client et l'identifiant employé ne peuvent pas être modifiés.");
    }
    // Clear input fields
    ui->id_client_mod_2c->clear();
    ui->prenom_client_2c->clear();
    ui->nom_client_2c->clear();
    ui->email_client_2c->clear();
    ui->tel_client_2c->clear();
    ui->type_client_2c->setCurrentIndex(0);
    ui->adresse_client_2c->clear();
    ui->specialite_client_2c->setCurrentIndex(0);
    ui->id_emp_2c->setCurrentIndex(0);
}

void MainWindow::on_pushButton_search_mod_2c_clicked()
{
    if(ui->id_client_mod_2c->text().isEmpty()) {
        QMessageBox::warning(this, "erreur", "Veuillez saisir un identifiant client pour effectuer la recherche");
        return;
    }

    int id = ui->id_client_mod_2c->text().toInt();

    // Check if client exists
    if (!cli.clientExists_client(id)) {
        QMessageBox::warning(this, "erreur", "L'ID client n'existe pas");
        return;
    }

    // Fetch client data
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if(!query.exec()) {
        QMessageBox::critical(this, "erreur", "Échec de la récupération des données client");
        return;
    }

    if(query.next()) {
        // Get data from the query
        QString id_client = query.value(0).toString();
        QString prenom_client = query.value(2).toString();
        QString nom_client = query.value(1).toString();
        QString email_client = query.value(3).toString();
        QString tel_client = query.value(4).toString();
        QString type_client = query.value(5).toString();
        QString adresse_client = query.value(6).toString();
        QString date_inscri_client = query.value(7).toString();
        QString specialite_client = query.value(8).toString();
        QString id_emp = query.value(9).toString();
        QString nom_emp = query.value(10).toString(); // Get the employee name from the query

        // Update the form fields
        ui->prenom_client_2c->setText(prenom_client);
        ui->nom_client_2c->setText(nom_client);
        ui->email_client_2c->setText(email_client);
        ui->tel_client_2c->setText(tel_client);
        ui->adresse_client_2c->setText(adresse_client);

        int typeIndex = ui->type_client_2c->findText(type_client);
        if (typeIndex != -1) {
            ui->type_client_2c->setCurrentIndex(typeIndex);
        }

        // Update specialite combo box
        int specialiteIndex = ui->specialite_client_2c->findText(specialite_client);
        if (specialiteIndex != -1) {
            ui->specialite_client_2c->setCurrentIndex(specialiteIndex);
        }

        // Set the combo box value - search for exact match of both ID and name
        bool found = false;
        for (int i = 0; i < ui->id_emp_2c->count(); ++i) {
            QVariantList empData = ui->id_emp_2c->itemData(i).toList();
            if (empData.size() >= 2 &&
                empData[0].toString() == id_emp &&
                empData[1].toString() == nom_emp) {
                ui->id_emp_2c->setCurrentIndex(i);
                found = true;
                break;
            }
        }

        if (!found) {
            // If exact match not found, try to find by ID only
            int index = ui->id_emp_2c->findData(QVariantList() << id_emp << nom_emp, Qt::UserRole, Qt::MatchContains);
            if (index != -1) {
                ui->id_emp_2c->setCurrentIndex(index);
            } else {
                // If still not found, add the employee to the combo box
                ui->id_emp_2c->addItem(QString("%1 - %2").arg(id_emp).arg(nom_emp),
                                    QVariantList() << id_emp << nom_emp);
                ui->id_emp_2c->setCurrentIndex(ui->id_emp_2c->count() - 1);
            }
        }

        // Store original values
        originalEmpId = id_emp;
        originalEmpName = nom_emp;

        // Handle date
        QDate date = QDate::fromString(date_inscri_client, "yyyy-MM-dd");
        if(date.isValid()) {
            ui->date_inscri_client_2c->setDate(date);
        } else {
            qDebug() << "Format de date invalide:" << date_inscri_client;
            ui->date_inscri_client_2c->setDate(QDate::currentDate());
        }
    }
}

void MainWindow::on_pushButton_pdf_2c_clicked()
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

    html += "<h2>Liste des Clients</h2>";
    html += "<table>";
    html += "<tr>";

    // Récupérer le modèle du QTableView
    QAbstractItemModel *model = ui->tableView_2c->model();

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

    // En-têtes du tableau
    for (int col = 0; col < columnCount; col++) {
        QString headerText = model->headerData(col, Qt::Horizontal).toString();
        html += "<th>" + headerText + "</th>";
    }
    html += "</tr>";

    // Remplissage du tableau avec les données
    for (int row = 0; row < rowCount; row++) {
        html += "<tr>";
        for (int col = 0; col < columnCount; col++) {
            QVariant data = model->data(model->index(row, col));
            QString cellText = data.toString().trimmed();

            // Correction du format de la date pour éviter "T00:00:00.000"
            if (cellText.contains("T")) {
                cellText = cellText.split("T")[0];
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

void MainWindow::on_rechercher_2c_textChanged(const QString &text)
{
    QSqlQueryModel* model = cli.recherche_client(text); // Use the recherche() method we implemented earlier

    if (model)
    {
        ui->tableView_2c->setModel(model); // Update the table view
        ui->tableView_2c->resizeColumnsToContents();
    }
}

void MainWindow::on_trier_nom_2c_clicked()
{
    QSqlQueryModel* model = cli.Trier_client("NOM");
    if (model) {
        ui->tableView_2c->setModel(model);
        ui->tableView_2c->resizeColumnsToContents();
    }
}

void MainWindow::on_trier_date_2c_clicked()
{
    QSqlQueryModel* model = cli.Trier_client("DATE_INSCRIPTION");
    if (model) {
        ui->tableView_2c->setModel(model);
        ui->tableView_2c->resizeColumnsToContents();
    }
}

void MainWindow::on_trier_type_2c_clicked()
{
    QSqlQueryModel* model = cli.Trier_client("TYPE_CLIENT");
    if (model) {
        ui->tableView_2c->setModel(model);
        ui->tableView_2c->resizeColumnsToContents();
    }
}

void MainWindow::populateEmployeeComboBox()
{
    QSqlQuery query("SELECT IDEMPLOYE, NOM FROM EMPLOYE ORDER BY IDEMPLOYE");
    ui->id_emp_2c->clear();

    // Add a default empty option
    ui->id_emp_2c->addItem("Selecter un Employee", QVariantList() << "" << "");

    QSet<QPair<QString, QString>> existingEmployees;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QPair<QString, QString> employee(id, name);

        if (!existingEmployees.contains(employee)) {
            ui->id_emp_2c->addItem(QString("%1 - %2").arg(id).arg(name),
                                QVariantList() << id << name);
            existingEmployees.insert(employee);
        }
    }
}

void MainWindow::on_pushbutton_6c_clicked()
{
    // Create a dialog to display the statistics
    QDialog *statDialog = new QDialog(this);
    statDialog->setWindowTitle("Client Statistiques");
    statDialog->resize(800, 600);

    // Create a tab widget to organize different statistics
    QTabWidget *tabWidget = new QTabWidget(statDialog);

    // Create layouts for the tabs
    QVBoxLayout *mainLayout = new QVBoxLayout(statDialog);
    mainLayout->addWidget(tabWidget);

    // 1. Statistics for Specialite
    QPieSeries *specialiteSeries = new QPieSeries();
    QSqlQuery specialiteQuery("SELECT SPECIALITE, COUNT(*) FROM CLIENT GROUP BY SPECIALITE");
    while (specialiteQuery.next()) {
        QString specialite = specialiteQuery.value(0).toString();
        int count = specialiteQuery.value(1).toInt();
        QPieSlice *slice = specialiteSeries->append(specialite, count);
        slice->setLabel(QString("%1 (%2)").arg(specialite).arg(count));
        slice->setLabelVisible(true);
    }

    QChart *specialiteChart = new QChart();
    specialiteChart->addSeries(specialiteSeries);
    specialiteChart->setTitle("Répartition des clients par spécialité");
    specialiteChart->legend()->setVisible(true);
    specialiteChart->legend()->setAlignment(Qt::AlignRight);

    QChartView *specialiteChartView = new QChartView(specialiteChart);
    specialiteChartView->setRenderHint(QPainter::Antialiasing);

    QWidget *specialiteTab = new QWidget();
    QVBoxLayout *specialiteLayout = new QVBoxLayout(specialiteTab);
    specialiteLayout->addWidget(specialiteChartView);
    tabWidget->addTab(specialiteTab, "par spécialité");

    // 2. Statistics for Type
    QPieSeries *typeSeries = new QPieSeries();
    QSqlQuery typeQuery("SELECT TYPE_CLIENT, COUNT(*) FROM CLIENT GROUP BY TYPE_CLIENT");
    while (typeQuery.next()) {
        QString type = typeQuery.value(0).toString();
        int count = typeQuery.value(1).toInt();
        QPieSlice *slice = typeSeries->append(type, count);
        slice->setLabel(QString("%1 (%2)").arg(type).arg(count));
        slice->setLabelVisible(true);
    }

    QChart *typeChart = new QChart();
    typeChart->addSeries(typeSeries);
    typeChart->setTitle("Répartition des clients par type");
    typeChart->legend()->setVisible(true);
    typeChart->legend()->setAlignment(Qt::AlignRight);

    QChartView *typeChartView = new QChartView(typeChart);
    typeChartView->setRenderHint(QPainter::Antialiasing);

    QWidget *typeTab = new QWidget();
    QVBoxLayout *typeLayout = new QVBoxLayout(typeTab);
    typeLayout->addWidget(typeChartView);
    tabWidget->addTab(typeTab, "par type");

    // Show the dialog
    statDialog->exec();
}

void MainWindow::populateTypeComboBox()
{
    ui->type_client_2c->clear();
    ui->type_client_2c->addItem("Individuel");
    ui->type_client_2c->addItem("Entreprise");
}

void MainWindow::populateSpecialiteComboBox()
{
    ui->specialite_client_2c->clear();
    ui->specialite_client_2c->addItem("Finance");
    ui->specialite_client_2c->addItem("IT");
    ui->specialite_client_2c->addItem("Marketing");
    ui->specialite_client_2c->addItem("RH");
}



void MainWindow::setupArduinoConnection()
{
    if(arduino->connectToArduino()) {
        // Create a persistent message box
        QMessageBox *smokeAlert = new QMessageBox(this);
        smokeAlert->setWindowTitle("Smoke Alert");
        smokeAlert->setIcon(QMessageBox::Critical);
        smokeAlert->setStandardButtons(QMessageBox::Ok);
        smokeAlert->setModal(false);  // Non-modal so it doesn't block the app

        connect(arduino, &Arduino::smokeStateChanged, this, [smokeAlert](bool detected) {
            if(detected) {
                smokeAlert->setText("WARNING: Smoke detected! Please evacuate immediately!");
                smokeAlert->show();
            } else {
                smokeAlert->setText("Smoke cleared. Area is now safe.");
                smokeAlert->setIcon(QMessageBox::Information);
                // Auto-close after 5 seconds
                QTimer::singleShot(5000, smokeAlert, &QMessageBox::hide);
                // Reset to critical for next detection
                QTimer::singleShot(5000, [smokeAlert]() {
                    smokeAlert->setIcon(QMessageBox::Critical);
                });
            }
        });

        connect(arduino, &Arduino::arduinoError, this, [this](const QString &message) {
            QMessageBox::warning(this, "Arduino Error", message);
        });
    }
}
void MainWindow::setClientBoxVisible(bool visible)
{
    if (ui->clientbox) {  // Make sure clientbox exists in your UI
        ui->clientbox->setVisible(visible);
    }
}




//ferreessssssssssss

//moataz
bool MainWindow::isValidInput()
{
    // Vérifier si tous les champs sont remplis
    if (ui->nom_res->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ NOM ne peut pas être vide.");
        return false;
    }

    if (ui->description_res->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ DESCRIPTION ne peut pas être vide.");
        return false;
    }

    if (ui->type_res->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ TYPE ne peut pas être vide.");
        return false;
    }

    if (ui->localisation_res->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ LOCALISATION ne peut pas être vide.");
        return false;
    }

    // Vérifier si une valeur valide est sélectionnée dans le QComboBox pour l'état
    if (ui->etat_res->currentText().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ ETAT ne peut pas être vide.");
        return false;
    }

    bool ok;
    ui->quantite_res->text().toInt(&ok); // Vérifier si QUANTITE est un nombre entier
    if (!ok) {
        QMessageBox::warning(this, "Quantité invalide", "Veuillez entrer un nombre valide pour QUANTITE.");
        return false;
    }

    return true;
}

void MainWindow::on_pushButton_confirmer_res_clicked()
{
    if (!isValidInput()) {
        return;
    }

    QString NOM = ui->nom_res->text();
    QString DESCRIPTION = ui->description_res->text();
    QString TYPE = ui->type_res->text();
    QString LOCALISATION = ui->localisation_res->text();
    int QUANTITE = ui->quantite_res->text().toInt();
    QString ETAT = ui->etat_res->currentText();
    QString TELEPHONE = ui->telephone_res->text();  // Changer pour QString si besoin
    QString FOURNISSEUR = ui->fournisseur_res->text();

    // Créer une instance de ressource avec les informations récupérées
    ressource R(NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR);

    bool test = R.ajouter_res();  // Ajouter la ressource dans la base de données

    // Effacer les champs après ajout
    ui->nom_res->clear();
    ui->description_res->clear();
    ui->type_res->clear();
    ui->localisation_res->clear();
    ui->quantite_res->clear();
    ui->etat_res->setCurrentIndex(0);
    ui->telephone_res->clear();
    ui->fournisseur_res->clear();

    if (test) {
        ui->table_res->setModel(R.afficher_res());  // Rafraîchir l'affichage des ressources


        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout réussi.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ajout échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_supprimerr_res_clicked()
{
    QModelIndexList selectedRows = ui->table_res->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner une ressource à supprimer."));
        return;
    }

    int id = selectedRows.first().data().toInt();
    bool test = R.supprimer_res(id);

    if (test) {
        ui->table_res->setModel(R.afficher_res());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression réussie.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Suppression échouée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_modifier_res_clicked()
{
    QModelIndexList selectedRows = ui->table_res->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner une ressource à modifier."));
        return;
    }

    int id = selectedRows.first().data().toInt();
    ressource R = R.trouver_res(id);

    ui->nom_res->setText(R.getNOM());
    ui->description_res->setText(R.getDESCRIPTION());
    ui->type_res->setText(R.getTYPE());
    ui->localisation_res->setText(R.getLOCALISATION());
    ui->quantite_res->setText(QString::number(R.getQUANTITE()));

    // Mettre à jour le QComboBox avec l'état actuel
    int indexEtat = ui->etat_res->findText(R.getETAT());
    if (indexEtat != -1) {
        ui->etat_res->setCurrentIndex(indexEtat);  // Sélectionner l'état existant dans le QComboBox
    }

    //ui->idprojet->setText(QString::number(R.getIDPROJET()));
    ui->telephone_res->setText(R.getTELEPHONE());
    ui->fournisseur_res->setText(R.getFOURNISSEUR());

    connect(ui->confirmermodification_res, &QPushButton::clicked, [this, id]() {
        ressource R;  // Créer un objet ressource vide
        R = R.trouver_res(id);  // Utiliser la méthode trouver pour récupérer la ressource par ID

        R.setNom(ui->nom_res->text());
        R.setDescription(ui->description_res->text());
        R.setType(ui->type_res->text());
        R.setLocalisation(ui->localisation_res->text());
        R.setQuantite(ui->quantite_res->text().toInt());

        // Mettre à jour l'état avec la valeur sélectionnée dans la liste déroulante
        R.setEtat(ui->etat_res->currentText());

        //R.setIdprojet(ui->idprojet->text().toInt());
        R.setTelephone(ui->telephone_res->text());
        R.setFournisseur(ui->fournisseur_res->text());
    });
}


void MainWindow::on_pushButton_confirmermodification_res_clicked()
{
    QModelIndexList selectedRows = ui->table_res->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ressource à modifier.");
        return;
    }

    int id = selectedRows.first().data().toInt();
    ressource R = R.trouver_res(id);

    if (R.getID() == 0) {
        QMessageBox::warning(this, "Erreur", "La ressource avec l'ID spécifié n'existe pas.");
        return;
    }

    if (!isValidInput()) {
        return;
    }

    QString NOM = ui->nom_res->text();
    QString DESCRIPTION = ui->description_res->text();
    QString TYPE = ui->type_res->text();
    QString LOCALISATION = ui->localisation_res->text();
    int QUANTITE = ui->quantite_res->text().toInt();

    // Mettre à jour l'état avec la valeur sélectionnée dans la liste déroulante
    QString ETAT = ui->etat_res->currentText();  // Utiliser currentText() pour récupérer l'état sélectionné dans le QComboBox

    //int IDPROJET = ui->idprojet->text().toInt();
    QString TELEPHONE = ui->telephone_res->text();
    QString FOURNISSEUR = ui->fournisseur_res->text();

    R.setNom(NOM);
    R.setDescription(DESCRIPTION);
    R.setType(TYPE);
    R.setLocalisation(LOCALISATION);
    R.setQuantite(QUANTITE);
    R.setEtat(ETAT);  // Mettre à jour l'état dans la ressource
    //R.setIdprojet(IDPROJET);
    R.setTelephone(TELEPHONE);
    R.setFournisseur(FOURNISSEUR);

    bool test = R.modifier_res(id);

    if (test) {
        ui->table_res->setModel(R.afficher_res());
        QMessageBox::information(this, "Modification réussie", "La ressource a été modifiée avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }

    // Vider les champs après la modification
    ui->nom_res->clear();
    ui->description_res->clear();
    ui->type_res->clear();
    ui->localisation_res->clear();
    ui->quantite_res->clear();
    ui->etat_res->setCurrentIndex(0);  // Réinitialiser l'état à la première valeur de la liste déroulante
    //ui->idprojet->clear();
    ui->telephone_res->clear();
    ui->fournisseur_res->clear();
}


void MainWindow::on_statbutton_res_clicked()
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
    QSqlQueryModel* model = R.Trier_Ressources_res("QUANTITE"); // R est l'objet de la classe ressource
    ui->table_res->setModel(model);
}


void MainWindow::on_type_2_clicked()
{
    QSqlQueryModel* model = R.Trier_Ressources_res("TYPE");
    ui->table_res->setModel(model);
}


void MainWindow::on_rechercher_textChanged(const QString &text)
{
    ressource R; // Assure-toi que tu as une instance de ressource
    QSqlQueryModel* model = R.recherche_res(text); // Appel de la fonction recherche dans ressource

    if (model)
    {
        ui->table_res->setModel(model); // Mise à jour de la table
    }
}




void MainWindow::on_pdfButton_res_clicked()
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
    //stream << "<th style='border: 1px solid black; padding: 8px;'>ID Projet</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Téléphone</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Fournisseur</th>";
    stream << "</tr>";

    // Requête pour récupérer les ressources
    QSqlQuery query(db);
    query.prepare("SELECT ID, NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR FROM RESSOURCE");
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

        // Modifier l'affichage de l'état en utilisant un tableau de correspondance pour le rendre plus lisible
        QString etat = query.value("ETAT").toString();
        if (etat == "Neuf") {
            etat = "Neuf (New)";
        } else if (etat == "En bon état") {
            etat = "En bon état (Good Condition)";
        } else if (etat == "En réparation") {
            etat = "En réparation (In Repair)";
        } else if (etat == "Hors service") {
            etat = "Hors service (Out of Order)";
        }

        stream << "<td style='border: 1px solid black; padding: 8px;'>" << etat << "</td>";

        //stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("IDPROJET").toInt() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("TELEPHONE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("FOURNISSEUR").toString() << "</td>";
        stream << "</tr>";
    }

    stream << "</table>";
    doc.setHtml(text);
    doc.print(&printer);

    QMessageBox::information(this, "PDF", "PDF généré avec succès.");
}

void MainWindow::on_qrCodeButton_clicked()
{
    QModelIndexList selectedRows = ui->table_res->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ressource.");
        return;
    }

    int id = selectedRows.first().data().toInt();

    ressource R = R.trouver_res(id);

    //if (R.getID() == 0) {
    //QMessageBox::warning(this, "Erreur", "La ressource avec l'ID spécifié n'existe pas.");
    //return;
    //}

    // Modifier l'affichage de l'état dans une version lisible (liste déroulante)
    QString etat = R.getETAT();
    if (etat == "Neuf") {
        etat = "Neuf (New)";
    } else if (etat == "En bon état") {
        etat = "En bon état (Good Condition)";
    } else if (etat == "En réparation") {
        etat = "En réparation (In Repair)";
    } else if (etat == "Hors service") {
        etat = "Hors service (Out of Order)";
    }

    // Créer le texte des détails de la ressource
    QString resourceDetails = QString("ID: %1\nNom: %2\nDescription: %3\nType: %4\nLocalisation: %5\nQuantité: %6\nÉtat: %7\nTéléphone: %8\nFournisseur: %9")
                                  .arg(R.getID())
                                  .arg(R.getNOM())
                                  .arg(R.getDESCRIPTION())
                                  .arg(R.getTYPE())
                                  .arg(R.getLOCALISATION())
                                  .arg(R.getQUANTITE())
                                  .arg(R.getETAT())  // Utiliser l'état modifié
                                  .arg(R.getTELEPHONE())
                                  .arg(R.getFOURNISSEUR());

    // Convertir les détails de la ressource en une chaîne de texte brute
    std::string data = resourceDetails.toStdString();

    // Créer un code QR
    using namespace qrcodegen;
    const QrCode qr = QrCode::encodeText(data.c_str(), QrCode::Ecc::LOW);

    // Convertir le code QR en QImage
    int size = qr.getSize();
    QImage qrImage(size, size, QImage::Format_RGB888);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qr.getModule(x, y)) {
                qrImage.setPixel(x, y, qRgb(0, 0, 0));  // Pixel noir
            } else {
                qrImage.setPixel(x, y, qRgb(255, 255, 255));  // Pixel blanc
            }
        }
    }

    // Afficher le code QR dans un QLabel
    QPixmap pixmap = QPixmap::fromImage(qrImage);
    ui->qrCodeLabel_res->setPixmap(pixmap.scaled(ui->qrCodeLabel_res->size(), Qt::KeepAspectRatio));
}
void MainWindow::on_pushButton_envoyer_res_clicked()
{
    QString TELEPHONE = ui->telephone_res->text();  // Numéro de téléphone du fournisseur
    QString message = "Votre ressource a été mise à jour. Etat: " + ui->etat_res->currentText();  // Message à envoyer

    if (envoyerSMS(TELEPHONE, message)) {
        QMessageBox::information(this, "Message", "SMS envoyé avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "L'envoi du message a échoué.");
    }
}

bool MainWindow::envoyerSMS(const QString& numero, const QString& message)
{
    QString SID = "AC66dfae1055e801ab177829f3a57a979a";  // Remplace par ton SID Twilio
    QString AUTH_TOKEN = "dc14de8383c844bfa9edac0fa5a8c95a";  // Remplace par ton token Twilio
    QString FROM_NUMBER = "+19472172605";  // Numéro Twilio
    //QString toNumber = "+19898868244";

    const QString url = "https://api.twilio.com/2010-04-01/Accounts/" + SID + "/Messages.json";

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Paramètres de la requête POST
    QUrlQuery params;
    params.addQueryItem("To", numero);  // Numéro du destinataire
    params.addQueryItem("From", "+19898868244");  // Numéro Twilio
    params.addQueryItem("Body", message);  // Corps du message

    // Requête HTTP POST avec les paramètres
    QByteArray postData = params.toString(QUrl::FullyEncoded).toUtf8();
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(SID, AUTH_TOKEN).toUtf8().toBase64()));

    manager->post(request, postData);

    return true;
}

void MainWindow::onSMSResponseReceived(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        // Si la requête réussit, afficher un message de confirmation
        QMessageBox::information(this, "SMS", "Message envoyé avec succès !");
    } else {
        // En cas d'erreur, afficher le code d'erreur et le message retourné
        QByteArray response = reply->readAll();
        QMessageBox::critical(this, "Erreur SMS",
                              QString("L'envoi du message a échoué.\nErreur: %1\nDétails: %2")
                                  .arg(reply->errorString())
                                  .arg(response));
    }
    reply->deleteLater();
}

void MainWindow::setResBoxVisible(bool visible)
{
    if (ui->ressbox) {  // Make sure resbox exists in your UI
        ui->ressbox->setVisible(visible);
    }
}






//moataz
//akram
void MainWindow::on_pushButton_ajouter_clicked() {
    QString nom_projet = ui->lineEdit_2->text().trimmed();
    QString description = ui->lineEdit_10->text().trimmed();
    QString date_debut = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString date_fin = ui->dateEdit_2->date().toString("dd/MM/yyyy");
    QString statue = ui->lineEdit_9->text().trimmed();

    // Date validation
    QDate debutDate = ui->dateEdit->date();
    QDate finDate = ui->dateEdit_2->date();

    if (finDate < debutDate) {
        QMessageBox::warning(this, tr("Warning"), tr("End date cannot be before start date!"));
        return;
    }


    if (nom_projet.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty() || statue.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("Please fill all fields!"));
        return;
    }

    if (isEditMode) {
        // In Edit Mode, update the existing project
        if (pro.modifier_projet(currentProjectId, nom_projet, description, date_debut, statue, date_fin)) {
            QMessageBox::information(this, tr("Success"), tr("Project updated successfully!"));
            ui->tableView->setModel(pro.afficher_projet());  // Refresh the table view
            isEditMode = false;  // Reset to Add mode after editing
            currentProjectId = -1;  // Clear the project ID
            ui->pushButton_14->setText("Add");  // Change button text back to "Add"

            // Clear the input fields after updating
            ui->lineEdit_2->clear();
            ui->lineEdit_10->clear();
            ui->dateEdit->clear();
            ui->dateEdit_2->clear();
            ui->lineEdit_9->clear();
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to update project!"));
        }
    } else {
        QString smokeStatus = "Non";
        if (arduino && arduino->isSmokeDetected()) {  // We'll need to add this method to Arduino class
            smokeStatus = "Oui";
        }

        // In Add Mode, add a new project
        Projets p(0, nom_projet, description, date_debut, date_fin, statue, 37,smokeStatus   );
        if (p.ajouter_projet()) {
            QMessageBox::information(this, tr("Success"), tr("Project added successfully!"));
            ui->tableView->setModel(pro.afficher_projet());  // Refresh the table view

            // Clear the input fields after adding
            ui->lineEdit_2->clear();
            ui->lineEdit_10->clear();
            ui->dateEdit->clear();
            ui->dateEdit_2->clear();
            ui->lineEdit_9->clear();
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to add project!"));
        }
    }
}



void MainWindow::on_pushButton_supprimer_clicked(const QModelIndex &index)
{
    int id_projet = index.siblingAtColumn(0).data().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirm Delete"),
                                  tr("Are you sure you want to delete this project?"),
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (pro.supprimer_projet(id_projet)) {
            QMessageBox::information(this, tr("Success"), tr("Project deleted successfully!"));

            // Manually update the table view here
            ui->tableView->setModel(pro.afficher_projet());  // Refresh the table with new data
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to delete project!"));
        }
    }
}

void MainWindow::on_pushButton_modifier_clicked(const QModelIndex &index) {
    int id_projet = index.siblingAtColumn(0).data().toInt();
    QString nom_projet = index.siblingAtColumn(1).data().toString();
    QString description = index.siblingAtColumn(2).data().toString();
    QString date_debut = index.siblingAtColumn(3).data().toString();
    QString date_fin = index.siblingAtColumn(4).data().toString();
    QString statue = index.siblingAtColumn(5).data().toString();

    // Convert dates from database format to display format
    QDate db_debut = QDate::fromString(date_debut, "yyyy-MM-dd");
    QDate db_fin = QDate::fromString(date_fin, "yyyy-MM-dd");

    ui->lineEdit_2->setText(nom_projet);
    ui->lineEdit_10->setText(description);
    ui->dateEdit->setDate(db_debut);
    ui->dateEdit_2->setDate(db_fin);
    ui->lineEdit_9->setText(statue);

    isEditMode = true;
    currentProjectId = id_projet;
    ui->pushButton_14->setText("Update");
}


void MainWindow::on_pushButton_search_clicked()
{
    QString searchTerm = ui->lineEdit->text().trimmed();

    // Call the recherche function and update the table view with search results
    if (!searchTerm.isEmpty()) {
        ui->tableView->setModel(pro.recherche_projet(searchTerm));
    } else {
        // If the search box is empty, you can either leave the table as it is
        // or refresh it with the full list of projects.
        ui->tableView->setModel(pro.afficher_projet());
    }
}

void MainWindow::generatePdf(const QSqlQueryModel *model)
{
    // Open file dialog to get the save location
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty()) {
        return;  // User canceled the save dialog
    }

    // Create a QPdfWriter instance to write to a PDF file
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);  // Set the page size to A4

    // Create a QTextDocument to hold the content
    QTextDocument document;

    // Set the document's font (you can change it based on your preferences)
    QFont font("Arial", 12);
    document.setDefaultFont(font);

    // Prepare content for the PDF in HTML format
    QString htmlContent = "<h1 style='text-align:center;'>Project List</h1>";
    htmlContent += "<table style='width:100%; border: 1px solid black; border-collapse: collapse;'>";
    htmlContent += "<tr><th>ID</th><th>Name</th><th>Description</th><th>Status</th></tr>";

    // Loop through each row in the model and create an HTML table row
    for (int row = 0; row < model->rowCount(); ++row) {
        htmlContent += "<tr>";

        // Get the values of each column in the row
        for (int column = 0; column < model->columnCount(); ++column) {
            htmlContent += "<td style='border: 1px solid black; padding: 5px;'>"
                           + model->data(model->index(row, column)).toString()
                           + "</td>";
        }

        htmlContent += "</tr>";
    }

    htmlContent += "</table>";

    // Set the HTML content to the QTextDocument
    document.setHtml(htmlContent);

    // Render the document to the PDF writer
    document.print(&writer);

    // Notify the user that the PDF was generated
    QMessageBox::information(this, "PDF Generated", "The PDF file has been generated successfully.");
}

void MainWindow::on_pushButton_pdf_clicked()
{
    // Get the model from the table view
    QSqlQueryModel *model = static_cast<QSqlQueryModel *>(ui->tableView->model());

    // Call the PDF generation function
    if (model) {
        generatePdf(model);
    } else {
        QMessageBox::warning(this, "No Data", "There is no data to generate the PDF.");
    }
}


void MainWindow::generateStatistiques()
{
    // Get the counts of each status
    QMap<QString, int> statusCounts = getStatusCounts();

    // Calculate the total number of projects
    int totalProjects = 0;
    for (const auto& item : statusCounts) {
        totalProjects += item;  // item is an integer representing the count
    }

    // Avoid division by zero if no projects are present
    if (totalProjects == 0) {
        qDebug() << "No projects found.";
        return;
    }

    // Calculate and display the percentage for each status
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        QString status = it.key();  // Get the key (status)
        int count = it.value();     // Get the value (count)
        double percentage = (count / static_cast<double>(totalProjects)) * 100;

        // Debug output to check the calculated percentages
        qDebug() << "Status:" << status << "Count:" << count << "Percentage:" << percentage << "%";
    }
}


void MainWindow::drawStatistiquesChart(const QMap<QString, double> &statusPercentages)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up the pen and brush for drawing the chart
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::blue));  // Default color for "En cours"

    // Get the center and radius of the circle
    int radius = 100;
    int centerX = width() / 2;
    int centerY = height() / 2;

    // Initialize start angle for the first sector
    int startAngle = 90 * 16;  // 90 degrees in 1/16th degree units

    // Loop through each status and draw the sectors
    for (auto it = statusPercentages.begin(); it != statusPercentages.end(); ++it) {
        double percentage = it.value();
        int spanAngle = (360 * percentage / 100) * 16;  // Convert percentage to angle (in 1/16th degree units)

        if (it.key() == "En cours") {
            painter.setBrush(QBrush(Qt::yellow));  // Color for "En cours"
        } else if (it.key() == "Terminé") {
            painter.setBrush(QBrush(Qt::green));  // Color for "Terminé"
        } else if (it.key() == "Annulé") {
            painter.setBrush(QBrush(Qt::red));  // Color for "Annulé"
        }

        // Draw the pie slice for this status
        painter.drawPie(centerX - radius, centerY - radius, 2 * radius, 2 * radius, startAngle, spanAngle);

        // Update the start angle for the next sector
        startAngle += spanAngle;
    }

    // Draw the percentages text in the center
    painter.setPen(QPen(Qt::black));
    painter.setFont(QFont("Arial", 14, QFont::Bold));

    // Display the percentage text in the center
    painter.drawText(centerX - 50, centerY + 20, "Statistics");
}

void MainWindow::on_pushButton_statistiques_clicked()
{
    // Create a dialog to display the chart
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Project Statistics");
    chartDialog->resize(600, 500);

    QVBoxLayout *layout = new QVBoxLayout(chartDialog);

    // Fetch status counts and calculate percentages
    QMap<QString, int> statusCounts = getStatusCounts();
    int totalProjects = 0;
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        totalProjects += it.value();
    }

    if (totalProjects == 0) {
        QMessageBox::information(this, "No Data", "No projects found for statistics.");
        delete chartDialog;
        return;
    }

    QPieSeries *series = new QPieSeries();
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        double percentage = (it.value() / static_cast<double>(totalProjects)) * 100;
        QPieSlice *slice = series->append(it.key() + ": " + QString::number(percentage, 'f', 1) + "%", percentage);
        slice->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Project Status Statistics");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    chartDialog->exec();
    delete chartDialog;
}



QMap<QString, int> MainWindow::getStatusCounts() {
    QSqlQuery query;
    query.prepare("SELECT STATUT, COUNT(*) FROM PROJET GROUP BY STATUT");
    query.exec();

    QMap<QString, int> statusCounts;
    while (query.next()) {
        QString statut = query.value(0).toString();
        int count = query.value(1).toInt();
        statusCounts[statut] = count;
    }
    return statusCounts;
}


void MainWindow::on_pushButton_up_clicked()
{
    ui->tableView->setModel(pro.afficherSortedAsc_projet());
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_pushButton_down_clicked()
{
    ui->tableView->setModel(pro.afficherSortedDesc_projet());
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::openChatbot()
{
    if (m_chatbotDialog.isNull()) {
        initializeChatbotUI();
    }
    m_chatbotDialog->show();
    m_chatbotDialog->raise();
    m_chatbotDialog->activateWindow();
}

// Initialize chatbot UI components
void MainWindow::initializeChatbotUI()
{
    m_chatbotDialog = new QDialog(this);
    m_chatbotDialog->setWindowTitle("AI Assistant");
    m_chatbotDialog->setMinimumSize(400, 500);

    QVBoxLayout *mainLayout = new QVBoxLayout(m_chatbotDialog);

    // Chat display area
    m_chatDisplay = new QTextEdit(m_chatbotDialog);
    m_chatDisplay->setReadOnly(true);
    mainLayout->addWidget(m_chatDisplay);

    // Input area
    QHBoxLayout *inputLayout = new QHBoxLayout();
    m_messageInput = new QLineEdit(m_chatbotDialog);
    QPushButton *sendButton = new QPushButton("Send", m_chatbotDialog);
    inputLayout->addWidget(m_messageInput);
    inputLayout->addWidget(sendButton);
    mainLayout->addLayout(inputLayout);

    // Connections
    connect(sendButton, &QPushButton::clicked, this, &MainWindow::handleSendMessage);
    connect(m_messageInput, &QLineEdit::returnPressed, this, &MainWindow::handleSendMessage);

    // Welcome message
    showChatMessage("Assistante", "Comment puis-je t’aider aujourd’hui ?");
}

// Handle send button click
void MainWindow::handleSendMessage()
{
    if (m_messageInput.isNull()) return;

    QString message = m_messageInput->text().trimmed();
    if (message.isEmpty()) return;

    showChatMessage("You", message);
    m_messageInput->clear();

    sendToChatbotAPI(message);
}

// Send message to chatbot API
void MainWindow::sendToChatbotAPI(const QString &message)
{
    if (!m_networkManager) {
        showError("Network service unavailable");
        return;
    }

    const QString apiKey = "Bearer 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";
    if (apiKey.contains("your_actual_api_key")) {
        showError("API key not configured");
        return;
    }

    QUrl apiUrl("https://api-inference.huggingface.co/models/facebook/blenderbot-3B");
    QNetworkRequest request(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", apiKey.toUtf8());

    QJsonObject payload;
    payload["inputs"] = message;
    payload["parameters"] = QJsonObject{
        {"max_length", 150},
        {"temperature", 0.7},
        {"wait_for_model", true}
    };

    QNetworkReply *reply = m_networkManager->post(request, QJsonDocument(payload).toJson());

    // Set timeout
    QTimer::singleShot(30000, reply, &QNetworkReply::abort);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        this->handleNetworkReply(reply);
    });
}

// Handle network response
void MainWindow::handleNetworkReply(QNetworkReply *reply)
{
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response);

        if (!json.isNull() && json.isArray()) {
            QString replyText = json.array().first().toString();
            showChatMessage("Assistant", replyText);
        } else {
            showError("Invalid response format");
        }
    } else {
        showError(QString("Network error: %1").arg(reply->errorString()));
    }

    reply->deleteLater();
}

// Display message in chat
void MainWindow::showChatMessage(const QString &sender, const QString &message)
{
    if (!m_chatDisplay.isNull()) {
        m_chatDisplay->append(QString("<b>%1:</b> %2").arg(sender, message));
    }
}

// Display error message
void MainWindow::showError(const QString &error)
{
    qDebug() << "Error:" << error;
    if (!m_chatDisplay.isNull()) {
        m_chatDisplay->append(QString("<font color='red'>Error: %1</font>").arg(error));
    }
}
void MainWindow::setprojetBoxVisible(bool visible)
{
    if (ui->projetbox) {  // Make sure resbox exists in your UI
        ui->projetbox->setVisible(visible);
    }
}
//akram
