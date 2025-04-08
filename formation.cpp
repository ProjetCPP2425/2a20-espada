#include "formation.h"
#include <QSqlError>
#include <QDebug>

Formation::Formation(QString titre, QString description, QString date_debut, QString date_fin, int duree, float prix, int client)
{
    this->TITRE = titre;
    this->DESCRIPTION = description;
    this->DATE_DEBUT = date_debut;
    this->DATE_FIN = date_fin;
    this->DUREE = duree;
    this->PRIX = prix;
    this->IDC = client;
}

bool Formation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FORMATION (TITRE, DESCRIPTION, DATE_DEBUT, DATE_FIN, DUREE, PRIX, IDC) "
                  "VALUES (:TITRE, :DESCRIPTION, :DATE_DEBUT, :DATE_FIN, :DUREE, :PRIX, :IDC)");

    query.bindValue(":TITRE", TITRE);
    query.bindValue(":DESCRIPTION", DESCRIPTION);
    query.bindValue(":DATE_DEBUT", DATE_DEBUT);
    query.bindValue(":DATE_FIN", DATE_FIN);
    query.bindValue(":DUREE", DUREE);
    query.bindValue(":PRIX", PRIX);
    query.bindValue(":IDC", IDC);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel * Formation::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_FORMATION, TITRE, DESCRIPTION, DATE_DEBUT, DATE_FIN, DUREE, PRIX FROM FORMATION");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FORMATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TITRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX"));

    model->insertColumn(7); // Column 7: Supprimer
    model->insertColumn(8); // Column 8: Modifier

    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Modifier"));



    return model;
}

bool Formation::supprimer(int ID_FORMATION)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FORMATION WHERE ID_FORMATION = :ID_FORMATION");
    query.bindValue(":ID_FORMATION", ID_FORMATION);
    return query.exec();
}

bool Formation::modifier(int ID_FORMATION, QString titre, QString description, QString date_debut, QString date_fin, int duree, float prix)
{
    QSqlQuery query;
    query.prepare("UPDATE FORMATION SET TITRE = :TITRE, DESCRIPTION = :DESCRIPTION, DATE_DEBUT = :DATE_DEBUT, "
                  "DATE_FIN = :DATE_FIN, DUREE = :DUREE, PRIX = :PRIX WHERE ID_FORMATION = :ID_FORMATION");

    query.bindValue(":TITRE", titre);
    query.bindValue(":DESCRIPTION", description);
    query.bindValue(":DATE_DEBUT", date_debut);
    query.bindValue(":DATE_FIN", date_fin);
    query.bindValue(":DUREE", duree);
    query.bindValue(":PRIX", prix);
    query.bindValue(":ID_FORMATION", ID_FORMATION);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        return false;
    }
    return true;
}
QSqlQueryModel* Formation::recherche(const QString &searchQuery)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_FORMATION, TITRE, DESCRIPTION, DATE_DEBUT, DATE_FIN, DUREE, PRIX "
                  "FROM FORMATION "
                  "WHERE LOWER(TITRE) LIKE LOWER(:keyword) OR LOWER(DESCRIPTION) LIKE LOWER(:keyword)");

    query.bindValue(":keyword", "%" + searchQuery + "%");

    if (query.exec())
    {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FORMATION"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Début"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Durée"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Prix"));

        return model;
    }
    else
    {
        qDebug() << "Erreur de recherche Formation :" << query.lastError().text();
        qDebug() << "Requête préparée :" << query.lastQuery();
        delete model;
        return afficher(); // Affiche toutes les formations si erreur
    }
}
