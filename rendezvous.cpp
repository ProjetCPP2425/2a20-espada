#include "rendezvous.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QTextCharFormat>
#include <QMap>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QBuffer>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QElapsedTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QMessageBox>
#include <QProcess>
#include <QObject>  // Assure-toi que cet en-tête est inclus
#include <QProcess>
#include <QDebug>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
// Constructeur par défaut
RendezVous::RendezVous() {}

// Constructeur avec paramètres
RendezVous::RendezVous(int idRdv, QDate dateRdv, QString heureRdv, QString modeRdv, QString objectif, QString nomClient) {
    this->id_rdv = idRdv;
    this->date_rdv = dateRdv;
    this->heure_rdv = heureRdv;
    this->mode_rdv = modeRdv;
    this->objectif = objectif;
    this->nom_client = nomClient;
}

// Getters
int RendezVous::get_id_rdv() {
    return id_rdv;
}

QDate RendezVous::get_date_rdv() {
    return date_rdv;
}

QString RendezVous::get_heure_rdv() {
    return heure_rdv;
}

QString RendezVous::get_mode_rdv() {
    return mode_rdv;
}

QString RendezVous::get_objectif() {
    return objectif;
}

QString RendezVous::get_nom_client() {
    return nom_client;
}

// Setters
void RendezVous::set_id_rdv(int idRdv) {
    this->id_rdv = idRdv;
}

void RendezVous::set_date_rdv(QDate dateRdv) {
    this->date_rdv = dateRdv;
}

void RendezVous::set_heure_rdv(QString heureRdv) {
    this->heure_rdv = heureRdv;
}

void RendezVous::set_mode_rdv(QString modeRdv) {
    this->mode_rdv = modeRdv;
}

void RendezVous::set_objectif(QString objectif) {
    this->objectif = objectif;
}

void RendezVous::set_nom_client(QString nomClient) {
    this->nom_client = nomClient;
}

// CRUD Operations

// Ajouter un rendez-vous
bool RendezVous::ajouter_RDV() {
    QSqlQuery query;
    query.prepare("INSERT INTO RENDEZ_VOUS (NOM_CLIENT, DATE_RDV, HEURE_RDV,OBJECTIF, MODE_RDV) "
                  "VALUES ( :nom_client,:date_rdv, :heure_rdv, :objectif, :mode_rdv)");
    query.bindValue(":id_rdv", id_rdv);
    query.bindValue(":nom_client", nom_client);
    query.bindValue(":date_rdv", date_rdv);
    query.bindValue(":heure_rdv", heure_rdv);
    query.bindValue(":objectif", objectif);
    query.bindValue(":mode_rdv", mode_rdv);



    return query.exec();
}

// Afficher les rendez-vous
QSqlQueryModel* RendezVous::afficher_RDV() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RDV, NOM_CLIENT, TO_CHAR(DATE_RDV, 'DD/MM/YYYY') AS DATE_RDV, HEURE_RDV, OBJECTIF , MODE_RDV FROM RENDEZ_VOUS");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_RDV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE_RDV"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("OBJECTIF"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MODE_RDV"));


    return model;
}

// Modifier un rendez-vous
bool RendezVous::modifier_RDV(int idRdv) {
    QSqlQuery query;
    query.prepare("UPDATE RENDEZ_VOUS SET DATE_RDV=:date_rdv, HEURE_RDV=:heure_rdv, MODE_RDV=:mode_rdv, "
                  "OBJECTIF=:objectif, NOM_CLIENT=:nom_client WHERE ID_RDV=:id_rdv");

    query.bindValue(":id_rdv", idRdv);
    query.bindValue(":date_rdv", date_rdv);
    query.bindValue(":heure_rdv", heure_rdv);
    query.bindValue(":mode_rdv", mode_rdv);
    query.bindValue(":objectif", objectif);
    query.bindValue(":nom_client", nom_client);

    return query.exec();
}

// Supprimer un rendez-vous
bool RendezVous::supprimer_RDV(int idRdv) {
    QSqlQuery query;
    query.prepare("DELETE FROM RENDEZ_VOUS WHERE ID_RDV=:id_rdv");
    query.bindValue(":id_rdv", idRdv);

    return query.exec();
}
QSqlQueryModel* RendezVous::recherche_RDV(const QString &searchQuery)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString searchValue = "%" + searchQuery + "%";

    query.prepare("SELECT ID_RDV, NOM_CLIENT, DATE_RDV, HEURE_RDV, MODE_RDV, OBJECTIF "
                  "FROM RENDEZ_VOUS "
                  "WHERE TO_CHAR(ID_RDV) LIKE :val "
                  "OR LOWER(NOM_CLIENT) LIKE LOWER(:val) "
                  "OR TO_CHAR(DATE_RDV, 'YYYY-MM-DD') LIKE :val "
                  "OR HEURE_RDV LIKE :val "
                  "OR LOWER(MODE_RDV) LIKE LOWER(:val) "
                  "OR LOWER(OBJECTIF) LIKE LOWER(:val)");

    query.bindValue(":val", searchValue);

    if (query.exec())
    {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mode"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Objectif"));

        return model;
    }
    else
    {
        qDebug() << "Erreur de requête RDV :" << query.lastError().text();
        delete model;
        return afficher_RDV(); // retourne tous les RDV
    }
}
QSqlQueryModel* RendezVous::Trier_RDV(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString;

    // Tri selon le critère
    if (critere == "MODE_RDV") {
        queryString = "SELECT * FROM RENDEZ_VOUS ORDER BY MODE_RDV ASC";
    } else if (critere == "DATE_RDV") {
        queryString = "SELECT * FROM RENDEZ_VOUS ORDER BY DATE_RDV ASC";
    } else {
        return afficher_RDV();  // Affichage sans tri si critère invalide
    }

    query.prepare(queryString);

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_RDV"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODE_RDV"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("OBJECTIF"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
        return model;
    } else {
        delete model;
        return nullptr;
    }
}

QSqlQueryModel* RendezVous::Select_by_date_r_RDV(QDate date)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString dateStr = date.toString("yyyy-MM-dd");

    QString queryStr = "SELECT ID_RDV, DATE_RDV, HEURE_RDV, MODE_RDV, OBJECTIF, NOM_CLIENT "
                       "FROM RENDEZ_VOUS "
                       "WHERE DATE_RDV = TO_DATE('" + dateStr + "', 'YYYY-MM-DD') "
                                   "ORDER BY HEURE_RDV";

    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mode"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Objectif"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nom Client"));

    return model;
}




QCalendarWidget* RendezVous::getAllRDV_RDV(QCalendarWidget* qcalendarwidget)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(ID_RDV) AS count, DATE_RDV "
                  "FROM RENDEZ_VOUS "
                  "GROUP BY DATE_RDV");

    if (!query.exec()) {
        qWarning() << "Erreur SQL : " << query.lastError().text();
        return qcalendarwidget;
    }

    while (query.next()) {
        int count = query.value(0).toInt();
        QDate date = query.value(1).toDate();
        QTextCharFormat fmt;

        if (count >= 5) {
            fmt.setBackground(Qt::red);
        } else if (count >= 2) {
            fmt.setBackground(Qt::yellow);
        } else {
            fmt.setBackground(Qt::green);
        }

        qcalendarwidget->setDateTextFormat(date, fmt);
    }

    return qcalendarwidget;
}


int RendezVous::nombre_RDV()
{
    QSqlQuery query("SELECT COUNT(*) FROM RENDEZ_VOUS");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}
//hammaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
em::em(QString nomem,QString prenomem,QString emailem,int telephoneem,QString specialiteem,int expem,QString dispoem,QString log ,QString mdp)
{

    this->NOMEM=nomem;
    this->PRENOMEM=prenomem;
    this->EMAILEM=emailem;
    this->TELEPHONEEM=telephoneem;
    this->SPECIALITEEM=specialiteem;
    this->EXPERIENCEEM=expem;
    this->DISPONIBILITEEM=dispoem;
    this->LOGIN=log;
    this->MDP=mdp;

}

bool em::ajouterem()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN, MDP) "
                  "VALUES (:NOM, :PRENOM, :EMAIL, :TELEPHONE, :SPECIALITE, :EXPERIENCE, :DISPONIBILITE, :LOGIN, :MDP)");

    query.bindValue(":NOM", NOMEM);
    query.bindValue(":PRENOM", PRENOMEM);
    query.bindValue(":EMAIL", EMAILEM);
    query.bindValue(":TELEPHONE", TELEPHONEEM);
    query.bindValue(":SPECIALITE", SPECIALITEEM);
    query.bindValue(":EXPERIENCE", EXPERIENCEEM);
    query.bindValue(":DISPONIBILITE", DISPONIBILITEEM);
    query.bindValue(":LOGIN", LOGIN);
    query.bindValue(":MDP", MDP);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        return false;
    }
    return true;
}
QSqlQueryModel * em::afficherem()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT  IDEMPLOYE, NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN, MDP FROM EMPLOYE");


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
    // Add empty columns for buttons
    model->insertColumn(10); // Column 10: Supprimer
    model->insertColumn(11); // Column 11: Modifier

    // Set headers for the new columns
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Modifier"));



    return model;
}
bool em::supprimerem(int IDEMPLOYE)
{
    QSqlQuery query;
    QString res=QString::number(IDEMPLOYE);
    query.prepare("Delete from EMPLOYE where IDEMPLOYE= :IDEMPLOYE");
    query.bindValue(":IDEMPLOYE",res);


    return query.exec();
}
// Update employee record
bool em::modifierem(int IDEMPLOYE, QString nomem, QString prenomem, QString emailem, int telephoneem, QString specialiteem, int expem, QString dispoem, QString log, QString mdp)
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOM = :NOM, PRENOM = :PRENOM, EMAIL = :EMAIL, TELEPHONE = :TELEPHONE, "
                  "SPECIALITE = :SPECIALITE, EXPERIENCE = :EXPERIENCE, DISPONIBILITE = :DISPONIBILITE, "
                  "LOGIN = :LOGIN, MDP = :MDP WHERE IDEMPLOYE = :IDEMPLOYE");

    query.bindValue(":NOM", nomem);
    query.bindValue(":PRENOM", prenomem);
    query.bindValue(":EMAIL", emailem);
    query.bindValue(":TELEPHONE", telephoneem);
    query.bindValue(":SPECIALITE", specialiteem);
    query.bindValue(":EXPERIENCE", expem);
    query.bindValue(":DISPONIBILITE", dispoem);
    query.bindValue(":LOGIN", log);
    query.bindValue(":MDP", mdp);
    query.bindValue(":IDEMPLOYE", IDEMPLOYE);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        return false;
    }
    return true;
}
QSqlQueryModel* em::Trier_Employe(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryString = "SELECT IDEMPLOYE, NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, "
                          "EXPERIENCE, DISPONIBILITE, LOGIN, MDP FROM EMPLOYE ";

    if (critere == "DISPONIBILITE") {
        queryString += "ORDER BY DISPONIBILITE ASC";
    }
    else if (critere == "DISPONIBILITE_DESC") {
        queryString += "ORDER BY DISPONIBILITE DESC";
    }
    else if (critere == "EMAIL") {
        queryString += "ORDER BY EMAIL ASC";
    }
    else if (critere == "EMAIL_DESC") {
        queryString += "ORDER BY EMAIL DESC";
    }
    else if (critere == "TELEPHONE") {
        queryString += "ORDER BY TELEPHONE ASC";
    }
    else if (critere == "TELEPHONE_DESC") {
        queryString += "ORDER BY TELEPHONE DESC";
    }
    else {
        return afficherem();
    }

    // Use the modern setQuery() approach
    model->setQuery(queryString);

    if (model->lastError().isValid()) {
        qDebug() << "Sorting error:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    // Set headers
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

    // Add button columns
    model->insertColumn(10); // Supprimer
    model->insertColumn(11); // Modifier

    return model;
}
//hammaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//fereeeessssssssss
Clients::Clients(int id_e, QString n, QString p, QString e, QString t, QString y, QString a, QString d, QString s) {
    nom_client = n;
    prenom_client = p;
    email_client = e;
    tel_client = t;
    type_client = y;
    adresse_client = a;
    date_inscri_client = d;
    specialite_client = s;
    id_emp = id_e;
}


bool Clients::ajouter_client() {
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (NOM, PRENOM, EMAIL, TELEPHONE, TYPE_CLIENT, ADRESSE, "
                  "DATE_INSCRIPTION, SPECIALITE, IDE, NOM_EMP, SMOKE_DETECTED) "
                  "VALUES (:nom, :prenom, :email, :tel, :type, :adresse, TO_DATE(:date, 'YYYY-MM-DD'), "
                  ":specialite, :ide, :nom_emp, :smoke_detected)");

    query.bindValue(":nom", nom_client);
    query.bindValue(":prenom", prenom_client);
    query.bindValue(":email", email_client);
    query.bindValue(":tel", tel_client);
    query.bindValue(":type", type_client);
    query.bindValue(":adresse", adresse_client);
    query.bindValue(":date", date_inscri_client);
    query.bindValue(":specialite", specialite_client);
    query.bindValue(":ide", id_emp);
    query.bindValue(":nom_emp", nom_emp);
    query.bindValue(":smoke_detected", smoke_detected);

    if (!query.exec()) {
        qDebug() << "Error adding client:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Clients::supprimer_client(int id_c){
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE IDCLIENT = :id_c"); // Changed from SECURITE to CLIENT
    query.bindValue(":id_c", id_c);
    return query.exec();
}
QSqlQueryModel * Clients::afficher_client(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDCLIENT, NOM, PRENOM, EMAIL, TELEPHONE, TYPE_CLIENT, ADRESSE, "
                    "DATE_INSCRIPTION, SPECIALITE, IDE, NOM_EMP, SMOKE_DETECTED from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDCLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("TYPE_CLIENT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("DATE_INSCRIPTION"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("IDE"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("NOM_EMP"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("SMOKE_DETECTED"));

    return model;
}

bool Clients::modifier_client(int id_client, QString nom_client, QString prenom_client, QString email_client,
                              QString tel_client, QString type_client, QString adresse_client,
                              QString date_inscri_client, QString specialite_client, int original_id_emp)
{
    QSqlQuery query;

    // First, get the original values to compare
    query.prepare("SELECT IDCLIENT, IDE FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id_client);

    if (!query.exec() || !query.next()) {
        qDebug() << "Error fetching original values:" << query.lastError().text();
        return false;
    }

    int original_id_client = query.value(0).toInt();
    int current_id_emp = query.value(1).toInt();

    // Check if IDs are being changed
    if (original_id_client != id_client) {
        qDebug() << "Attempt to modify ID_CLIENT from" << original_id_client << "to" << id_client;
        return false;
    }

    if (current_id_emp != original_id_emp) {
        qDebug() << "Attempt to modify ID_EMP from" << current_id_emp << "to" << original_id_emp;
        return false;
    }

    // Proceed with the update if IDs haven't changed
    if (!query.prepare("UPDATE CLIENT SET "
                       "NOM = :nom_client, "
                       "PRENOM = :prenom_client, "
                       "EMAIL = :email_client, "
                       "TELEPHONE = :tel_client, "
                       "TYPE_CLIENT = :type_client, "
                       "ADRESSE = :adresse_client, "
                       "DATE_INSCRIPTION = TO_DATE(:date_inscri_client, 'YYYY-MM-DD'), "
                       "SPECIALITE = :specialite_client "
                       "WHERE IDCLIENT = :id_client"))
    {
        qDebug() << "Prepare error:" << query.lastError().text();
        return false;
    }

    // Bind values (excluding ID_EMP since we're not changing it)
    query.bindValue(":id_client", id_client);
    query.bindValue(":nom_client", nom_client);
    query.bindValue(":prenom_client", prenom_client);
    query.bindValue(":email_client", email_client);
    query.bindValue(":tel_client", tel_client);
    query.bindValue(":type_client", type_client);
    query.bindValue(":adresse_client", adresse_client);
    query.bindValue(":date_inscri_client", date_inscri_client);
    query.bindValue(":specialite_client", specialite_client);

    if (!query.exec()) {
        qDebug() << "Execution error:" << query.lastError().text();
        return false;
    }

    return true;
}


bool Clients::employeeExists_client(int id_emp) {
    QSqlQuery query;
    query.prepare("SELECT 1 FROM EMPLOYE WHERE IDEMPLOYE = :id");
    query.bindValue(":id", id_emp);
    return query.exec() && query.next();
}

bool Clients::clientExists_client(int id_c) {
    QSqlQuery query;
    query.prepare("SELECT 1 FROM CLIENT WHERE IDCLIENT = :id_c");
    query.bindValue(":id_c", id_c);
    return query.exec() && query.next();
}

QSqlQueryModel* Clients::recherche_client(const QString &searchQuery)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString searchValue = "%" + searchQuery + "%";

    query.prepare("SELECT IDCLIENT, NOM, PRENOM, EMAIL, TELEPHONE, TYPE_CLIENT, ADRESSE, "
                  "TO_CHAR(DATE_INSCRIPTION, 'YYYY-MM-DD'), SPECIALITE, IDE "
                  "FROM CLIENT "
                  "WHERE TO_CHAR(IDCLIENT) LIKE :val "
                  "OR LOWER(NOM) LIKE LOWER(:val) "
                  "OR LOWER(PRENOM) LIKE LOWER(:val) "
                  "OR LOWER(EMAIL) LIKE LOWER(:val) "
                  "OR TELEPHONE LIKE :val "
                  "OR LOWER(TYPE_CLIENT) LIKE LOWER(:val) "
                  "OR LOWER(ADRESSE) LIKE LOWER(:val) "
                  "OR TO_CHAR(DATE_INSCRIPTION, 'YYYY-MM-DD') LIKE :val "
                  "OR LOWER(SPECIALITE) LIKE LOWER(:val) "
                  "OR TO_CHAR(IDE) LIKE :val");

    query.bindValue(":val", searchValue);

    if (query.exec())
    {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_CLIENT"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE_INSCRIPTION"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("SPECIALITE"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("IDE"));

        return model;
    }
    else
    {
        qDebug() << "Erreur de recherche client :" << query.lastError().text();
        delete model;
        return afficher_client(); // retourne tous les clients
    }
}

QSqlQueryModel* Clients::Trier_client(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString;

    // Tri selon le critère
    if (critere == "NOM") {
        queryString = "SELECT * FROM CLIENT ORDER BY NOM ASC";
    } else if (critere == "DATE_INSCRIPTION") {
        queryString = "SELECT * FROM CLIENT ORDER BY DATE_INSCRIPTION ASC";
    } else if (critere == "TYPE_CLIENT") {
        queryString = "SELECT * FROM CLIENT ORDER BY TYPE_CLIENT ASC";
    } else {
        return afficher_client();  // Affichage sans tri si critère invalide
    }

    query.prepare(queryString);

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_CLIENT"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE_INSCRIPTION"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("SPECIALITE"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("IDE"));
        return model;
    } else {
        qDebug() << "Erreur de tri client :" << query.lastError().text();
        delete model;
        return nullptr;
    }
}
//fereeeeeeeessss
//moataz
ressource::ressource()
    : NOM_res(""), DESCRIPTION_res(""), TYPE_res(""), LOCALISATION_res(""), QUANTITE_res(0),
    ETAT_res(""), TELEPHONE_res(""), FOURNISSEUR_res(""),
    decodingCount(0), totalProcessingTime(0)
{
}

// Constructeur avec paramètres
ressource::ressource(QString nom, QString description, QString type, QString localisation, int quantite,
                     QString etat, QString telephone, QString fournisseur)
    : NOM_res(nom), DESCRIPTION_res(description), TYPE_res(type), LOCALISATION_res(localisation),
    QUANTITE_res(quantite), ETAT_res(etat), TELEPHONE_res(telephone), FOURNISSEUR_res(fournisseur),
    decodingCount(0), totalProcessingTime(0)
{
}

// Ajouter une ressource
bool ressource::ajouter_res() {
    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCE (NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR) "
                  "VALUES (:NOM, :DESCRIPTION, :TYPE, :LOCALISATION, :QUANTITE, :ETAT, :TELEPHONE, :FOURNISSEUR)");

    query.bindValue(":NOM", NOM_res);
    query.bindValue(":DESCRIPTION", DESCRIPTION_res);
    query.bindValue(":TYPE", TYPE_res);
    query.bindValue(":LOCALISATION", LOCALISATION_res);
    query.bindValue(":QUANTITE", QUANTITE_res);
    query.bindValue(":ETAT", ETAT_res);
    //query.bindValue(":IDPROJET", IDPROJET);
    query.bindValue(":TELEPHONE", TELEPHONE_res);
    query.bindValue(":FOURNISSEUR", FOURNISSEUR_res);

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError();
        return false;
    }
    return true;
}

// Afficher toutes les ressources
QSqlQueryModel* ressource::afficher_res() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID, NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR FROM RESSOURCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Etat"));
    //model->setHeaderData(7, Qt::Horizontal, QObject::tr("IdProjet"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Fournisseur"));
    return model;
}

// Supprimer une ressource
bool ressource::supprimer_res(int ID) {
    QSqlQuery query;
    query.prepare("DELETE FROM RESSOURCE WHERE ID = :ID");
    query.bindValue(":ID", ID);
    return query.exec();
}

// Trouver une ressource par ID
ressource ressource::trouver_res(int ID) {
    QSqlQuery query;
    query.prepare("SELECT NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR FROM RESSOURCE WHERE ID = ?");
    query.addBindValue(ID);

    // Exécution de la requête
    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL : " << query.lastError().text();
        return ressource(); // Retourne une ressource vide en cas d'erreur
    }

    // Vérifie si la requête retourne une ligne
    if (query.next()) {
        // Les indices des colonnes commencent à 0
        return ressource(query.value(0).toString(), query.value(1).toString(),
                         query.value(2).toString(), query.value(3).toString(),
                         query.value(4).toInt(), query.value(5).toString(),
                         query.value(6).toString(), query.value(7).toString());
    }

    // Si aucune ressource n'a été trouvée, retourne une ressource vide
    return ressource();
}


// Modifier une ressource
bool ressource::modifier_res(int ID) {
    QSqlQuery query;
    query.prepare("UPDATE RESSOURCE SET NOM = ?, DESCRIPTION = ?, TYPE = ?, LOCALISATION = ?, QUANTITE = ?, ETAT = ?, TELEPHONE = ?, FOURNISSEUR = ? WHERE ID = ?");
    query.addBindValue(NOM_res);
    query.addBindValue(DESCRIPTION_res);
    query.addBindValue(TYPE_res);
    query.addBindValue(LOCALISATION_res);
    query.addBindValue(QUANTITE_res);
    query.addBindValue(ETAT_res);
    //query.addBindValue(IDPROJET);
    query.addBindValue(TELEPHONE_res);
    query.addBindValue(FOURNISSEUR_res);
    query.addBindValue(ID);
    return query.exec();
}

// Vérification de validité
bool ressource::isValid() {
    return !NOM_res.isEmpty();
}

// Ajouter sans QR code
bool ressource::ajouter1_res() {
    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCE (NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR) "
                  "VALUES (:NOM, :DESCRIPTION, :TYPE, :LOCALISATION, :QUANTITE, :ETAT, :TELEPHONE, :FOURNISSEUR)");

    query.bindValue(":NOM", NOM_res);
    query.bindValue(":DESCRIPTION", DESCRIPTION_res);
    query.bindValue(":TYPE", TYPE_res);
    query.bindValue(":LOCALISATION", LOCALISATION_res);
    query.bindValue(":QUANTITE", QUANTITE_res);
    query.bindValue(":ETAT", ETAT_res);
    //query.bindValue(":IDPROJET", IDPROJET);
    query.bindValue(":TELEPHONE", TELEPHONE_res);
    query.bindValue(":FOURNISSEUR", FOURNISSEUR_res);

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError();
        return false;
    }
    return true;
}

// Génération de PDF
void ressource::generatePDF_res(const QString &nom, const QString &description, const QString &type,
                                const QString &localisation, int quantite, const QString &etat, const QString &telephone, const QString &fournisseur)
{
    QPdfWriter writer("ressource.pdf");
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);

    QPainter painter(&writer);
    if (!painter.isActive()) {
        qWarning() << "Painter not active.";
        return;
    }

    QFont font("Arial", 12);
    painter.setFont(font);
    painter.setPen(Qt::black);

    int yOffset = 100;
    int lineSpacing = 100;

    painter.drawText(50, yOffset, "Nom: " + nom); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Description: " + description); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Type: " + type); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Localisation: " + localisation); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Quantité: " + QString::number(quantite)); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "État: " + etat); yOffset += lineSpacing;
    //painter.drawText(50, yOffset, "IdProjet: " + QString::number(idprojet)); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Téléphone: " + telephone); yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Fournisseur: " + fournisseur);

    painter.end();
}

// Statistiques
int ressource::getTotalResources_res() {
    QSqlQuery query("SELECT COUNT(*) FROM RESSOURCE");
    return query.next() ? query.value(0).toInt() : 0;
}

int ressource::getTotalQuantity_res() {
    QSqlQuery query("SELECT SUM(QUANTITE) FROM RESSOURCE");
    return query.next() ? query.value(0).toInt() : 0;
}

QMap<QString, int> ressource::getResourcesByState_res() {
    QMap<QString, int> stateCount;
    QSqlQuery query("SELECT ETAT, COUNT(*) FROM RESSOURCE GROUP BY ETAT");
    while (query.next()) {
        stateCount[query.value(0).toString()] = query.value(1).toInt();
    }
    return stateCount;
}

// Recherche simple
//QSqlQueryModel* ressource::search(const QString& searchQuery) {
//QSqlQueryModel* model = new QSqlQueryModel();
//QSqlQuery query;
//query.prepare("SELECT ID, NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR FROM RESSOURCE WHERE NOM LIKE :search OR DESCRIPTION LIKE :search");
//query.bindValue(":search", "%" + searchQuery + "%");
//model->setQuery(std::move(query));
//return model;
//}

// Recherche avancée
QSqlQueryModel* ressource::recherche_res(const QString& searchQuery) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    QString val = "%" + searchQuery + "%";
    query.prepare("SELECT ID, NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, TELEPHONE, FOURNISSEUR "
                  "FROM RESSOURCE WHERE LOWER(NOM) LIKE LOWER(:val)");

    query.bindValue(":val", val);

    // Vérifie si la requête a été exécutée correctement
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return nullptr;
    }

    // Utilisation de std::move pour transférer query sans la copier
    model->setQuery(std::move(query));

    if (model->rowCount() == 0) {
        qDebug() << "Aucune ressource trouvée pour la requête : " << searchQuery;
    } else {
        qDebug() << "Nombre de résultats trouvés : " << model->rowCount();
    }

    return model;
}



// Tri des ressources
QSqlQueryModel* ressource::Trier_Ressources_res(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString;

    if (critere == "TYPE")
        queryString = "SELECT * FROM RESSOURCE ORDER BY TYPE ASC";
    else if (critere == "QUANTITE")
        queryString = "SELECT * FROM RESSOURCE ORDER BY QUANTITE DESC";
    else
        return afficher_res();

    query.prepare(queryString);
    if (query.exec()) {
        model->setQuery(std::move(query));
        return model;
    } else {
        delete model;
        return nullptr;
    }
}


//moataz
//akram
Projets::Projets(int id_p,QString p,QString d,QString deb,QString fin,QString stat,int id_c,QString s) {
    this->id_projet=id_p;
    this->nom_projet=p;
    this->description_projet=d;
    this->date_debut_projet=deb;
    this->date_fin_projet=fin;
    this->statue_projet=stat;
    this->id_client_projet=id_c;
    this->smoke_detected=s;
}


bool Projets::ajouter_projet() {
    QSqlQuery query;

    // Convert dates to proper SQL format
    QDate debutDate = QDate::fromString(date_debut_projet, "dd/MM/yyyy");
    QDate finDate = QDate::fromString(date_fin_projet, "dd/MM/yyyy");

    if (!debutDate.isValid() || !finDate.isValid()) {
        qDebug() << "Invalid date format";
        return false;
    }

    if (finDate < debutDate) {
        qDebug() << "End date cannot be before start date";
        return false;
    }

    query.prepare("INSERT INTO PROJET (nom_projet, description, date_debut, date_fin, statut, id_client, SMOKE_STATUS) "
                  "VALUES (:nom_projet, :description, :date_debut, :date_fin, :statut, :id_client, :smoke_detected)");

    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description_projet);
    query.bindValue(":date_debut", debutDate.toString("yyyy-MM-dd")); // SQL date format
    query.bindValue(":date_fin", finDate.toString("yyyy-MM-dd"));     // SQL date format
    query.bindValue(":statut", statue_projet);
    query.bindValue(":id_client", id_client_projet);
    query.bindValue(":smoke_detected", smoke_detected);

    return query.exec();
}



QSqlQueryModel * Projets::afficher_projet()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, STATUT, SMOKE_STATUS FROM PROJET");

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));

    // Add empty columns for buttons (now columns 6 and 7)
    model->insertColumn(6); // Column 6: Supprimer
    model->insertColumn(7); // Column 7: Modifier

    // Set headers for the new columns
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Modifier"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Buzzer Sonne"));

    return model;
}


bool Projets::supprimer_projet(int IDEMPLOYE)
{
    QSqlQuery query;
    QString res=QString::number(IDEMPLOYE);
    query.prepare("Delete FROM PROJET where ID_PROJET= :ID_PROJET");
    query.bindValue(":ID_PROJET",res);


    return query.exec();
}

bool Projets::modifier_projet(int id_projet, QString nom_projet, QString description, QString date_debut, QString statue, QString date_fin) {
    QSqlQuery query;

    // Convert dates to proper format
    QDate debutDate = QDate::fromString(date_debut, "dd/MM/yyyy");
    QDate finDate = QDate::fromString(date_fin, "dd/MM/yyyy");

    if (!debutDate.isValid() || !finDate.isValid()) {
        qDebug() << "Invalid date format";
        return false;
    }

    if (finDate < debutDate) {
        qDebug() << "End date cannot be before start date";
        return false;
    }

    query.prepare("UPDATE PROJET SET NOM_PROJET=:nom_projet, DESCRIPTION=:description, "
                  "DATE_DEBUT=:date_debut, DATE_FIN=:date_fin, STATUT=:statut "
                  "WHERE ID_PROJET=:id_projet");

    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":date_debut", debutDate.toString("yyyy-MM-dd"));
    query.bindValue(":date_fin", finDate.toString("yyyy-MM-dd"));
    query.bindValue(":statut", statue);

    return query.exec();
}

QSqlQueryModel* Projets::recherche_projet(const QString &keyword)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Prepare a query to search in multiple columns (name, description, etc.)
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, STATUT "
                  "FROM PROJET "
                  "WHERE NOM_PROJET LIKE :keyword OR DESCRIPTION LIKE :keyword OR STATUT LIKE :keyword");

    query.bindValue(":keyword", "%" + keyword + "%");

    if (!query.exec()) {
        qDebug() << "Query error: " << query.lastError().text();  // Debug the query error
        return nullptr;
    }

    model->setQuery(query);

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}

QMap<QString, int> Projets::getStatusCounts_projet() {
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

QSqlQueryModel * Projets::afficherSortedAsc_projet()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, STATUT FROM PROJET ORDER BY ID_PROJET ASC");

    // Set column headers (same as afficher())
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));

    // Add empty columns for buttons
    model->insertColumn(6);
    model->insertColumn(7);
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Modifier"));

    return model;
}

QSqlQueryModel * Projets::afficherSortedDesc_projet()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, STATUT FROM PROJET ORDER BY ID_PROJET DESC");

    // Set column headers (same as afficher())
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));

    // Add empty columns for buttons
    model->insertColumn(6);
    model->insertColumn(7);
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Modifier"));

    return model;
}


//akram
