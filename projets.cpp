#include "projets.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


Projets::Projets(int id_p,QString p,QString d,QString deb,QString fin,QString stat,int id_c) {
    this->id_projet=id_p;
    this->nom_projet=p;
    this->description=d;
    this->date_debut=deb;
    this->date_fin=fin;
    this->statue=stat;
    this->id_client=id_c;
}


bool Projets::ajouter() {
    QSqlQuery query;

    // Convert dates to proper SQL format
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

    query.prepare("INSERT INTO PROJET (nom_projet, description, date_debut, date_fin, statut, id_client) "
                  "VALUES (:nom_projet, :description, :date_debut, :date_fin, :statut, :id_client)");

    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":date_debut", debutDate.toString("yyyy-MM-dd")); // SQL date format
    query.bindValue(":date_fin", finDate.toString("yyyy-MM-dd"));     // SQL date format
    query.bindValue(":statut", statue);
    query.bindValue(":id_client", id_client);

    return query.exec();
}



QSqlQueryModel * Projets::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, STATUT FROM PROJET");

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

    return model;
}


bool Projets::supprimer(int IDEMPLOYE)
{
    QSqlQuery query;
    QString res=QString::number(IDEMPLOYE);
    query.prepare("Delete FROM PROJET where ID_PROJET= :ID_PROJET");
    query.bindValue(":ID_PROJET",res);


    return query.exec();
}

bool Projets::modifier(int id_projet, QString nom_projet, QString description, QString date_debut, QString statue, QString date_fin) {
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

QSqlQueryModel* Projets::recherche(const QString &keyword)
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

QMap<QString, int> Projets::getStatusCounts() {
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

QSqlQueryModel * Projets::afficherSortedAsc()
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

QSqlQueryModel * Projets::afficherSortedDesc()
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

