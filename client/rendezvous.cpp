#include "rendezvous.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QTextCharFormat>

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
