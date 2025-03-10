#include "em.h"
#include <QSqlError>
#include <QDebug>

em::em(QString nom,QString prenom,QString email,int telephone,QString specialite,int exp,QString dispo,QString log ,QString mdp)
{

    this->NOM=nom;
    this->PRENOM=prenom;
    this->EMAIL=email;
    this->TELEPHONE=telephone;
    this->SPECIALITE=specialite;
    this->EXPERIENCE=exp;
    this->DISPONIBILITE=dispo;
    this->LOGIN=log;
    this->MDP=mdp;

}

bool em::ajouter()
{


    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN, MDP) "
                  "VALUES (:NOM, :PRENOM, :EMAIL, :TELEPHONE, :SPECIALITE, :EXPERIENCE, :DISPONIBILITE, :LOGIN, :MDP)");

    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":SPECIALITE", SPECIALITE);
    query.bindValue(":EXPERIENCE", EXPERIENCE);
    query.bindValue(":DISPONIBILITE", DISPONIBILITE);
    query.bindValue(":LOGIN", LOGIN);
    query.bindValue(":MDP", MDP);


    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text(); // Print the query error
        qDebug() << "Query executed:" << query.lastQuery(); // Print the executed query
        return false;
    }
    return true;
}
QSqlQueryModel * em::afficher()
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
bool em::supprimer(int IDEMPLOYE)
{
    QSqlQuery query;
    QString res=QString::number(IDEMPLOYE);
    query.prepare("Delete from EMPLOYE where IDEMPLOYE= :IDEMPLOYE");
    query.bindValue(":IDEMPLOYE",res);


    return query.exec();
}
// Update employee record
bool em::modifier(int IDEMPLOYE, QString nom, QString prenom, QString email, int telephone, QString specialite, int exp, QString dispo, QString log, QString mdp)
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOM = :NOM, PRENOM = :PRENOM, EMAIL = :EMAIL, TELEPHONE = :TELEPHONE, "
                  "SPECIALITE = :SPECIALITE, EXPERIENCE = :EXPERIENCE, DISPONIBILITE = :DISPONIBILITE, "
                  "LOGIN = :LOGIN, MDP = :MDP WHERE IDEMPLOYE = :IDEMPLOYE");

    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":EMAIL", email);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":SPECIALITE", specialite);
    query.bindValue(":EXPERIENCE", exp);
    query.bindValue(":DISPONIBILITE", dispo);
    query.bindValue(":LOGIN", log);
    query.bindValue(":MDP", mdp);
    query.bindValue(":IDEMPLOYE", IDEMPLOYE);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        return false;
    }
    return true;
}
