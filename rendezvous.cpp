#include "rendezvous.h"
#include <QSqlQuery>
#include <QSqlError>

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
bool RendezVous::ajouter() {
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
QSqlQueryModel* RendezVous::afficher() {
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
bool RendezVous::modifier(int idRdv) {
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
bool RendezVous::supprimer(int idRdv) {
    QSqlQuery query;
    query.prepare("DELETE FROM RENDEZ_VOUS WHERE ID_RDV=:id_rdv");
    query.bindValue(":id_rdv", idRdv);

    return query.exec();
}
QSqlQueryModel* RendezVous::recherche(const QString &searchQuery)
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
        return afficher(); // retourne tous les RDV
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
        return afficher();  // Affichage sans tri si critère invalide
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

