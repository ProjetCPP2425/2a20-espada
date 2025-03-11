#include "projets.h"
#include "projet.h"
#include "buttondelegate.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

Projets::Projets(int id_p,QString p,QString d,QString deb,QString fin,QString stat) {
    this->id_projet=id_p;
    this->nom_projet=p;
    this->describtion=d;
    this->date_debut=deb;
    this->date_fin=fin;
    this->statue=stat;
}


bool Projets::ajouter(){
    QSqlQuery query;


    query.prepare("INSERT INTO PROJET ( nom_projet, description, date_debut, date_fin, statut)""VALUES ( :nom_projet, :description, :date_debut, :date_fin, :statut) ");

    query.bindValue(":nom_projet",nom_projet);
    query.bindValue(":description",describtion);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":date_fin",date_fin);
    query.bindValue(":statut",statue);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text(); // Print the query error
        qDebug() << "Query executed:" << query.lastQuery(); // Print the executed query
        return false;
    }
    return true;
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
    // Add empty columns for buttons
    model->insertColumn(8); // Column 10: Supprimer
    model->insertColumn(9); // Column 11: Modifier

    // Set headers for the new columns
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Modifier"));



    return model;
}


bool Projets::supprimer(int IDEMPLOYE)
{
    QSqlQuery query;
    QString res=QString::number(IDEMPLOYE);
    query.prepare("Delete from EMPLOYE where IDEMPLOYE= :IDEMPLOYE");
    query.bindValue(":IDEMPLOYE",res);


    return query.exec();
}
