#include "clients.h"
#include<QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

Clients::Clients(int id_c,QString n,QString p,QString e,QString t,QString y,QString a,QString d,QString s){
    nom_client=n;
    prenom_client=p;
    email_client=e;
    tel_client=t;
    type_client=y;
    adresse_client=a;
    date_inscri_client=d;
    specialite_client=s;
    id_client=id_c;
}


bool Clients::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (IDCLIENT, NOM, PRENOM, EMAIL, TELEPHONE, TYPE_CLIENT, ADRESSE, DATE_INSCRIPTION, SPECIALITE, ID_EMP) "
                  "VALUES (:id_client, :nom_client, :prenom_client, :email_client, :tel_client, :type_client, :adresse_client, :date_inscri_client, :specialite_client, :id_emp)");

    query.bindValue(":id_client", id_client);
    query.bindValue(":nom_client", nom_client);
    query.bindValue(":prenom_client", prenom_client);
    query.bindValue(":email_client", email_client);
    query.bindValue(":tel_client", tel_client);
    query.bindValue(":type_client", type_client);
    query.bindValue(":adresse_client", adresse_client);
    query.bindValue(":date_inscri_client", date_inscri_client);
    query.bindValue(":specialite_client", specialite_client);
    query.bindValue(":id_emp", id_emp);

    return query.exec();
}
bool Clients::supprimer(int id_c){
    QSqlQuery query;
    QString res=QString::number(id_c);
    query.prepare("delete from SECURITE where IDCLIENT= :id_c");
    query.bindValue(":id_c",res);
    return query.exec();
}
QSqlQueryModel * Clients::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDCLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("TYPE_CLIENT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("DATE_INSCRIPTION"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("ID_EMP"));

    return model;
}

bool Clients::modifier(int id_client, QString prenom_client, QString nom_client, QString email_client,
                        QString tel_client, QString type_client, QString adresse_client, QString date_inscri_client, QString specialite_client)
{
    QSqlQuery query;

    if (!query.prepare("UPDATE CLIENT SET NOM = :nom_client, "
                       "PRENOM = :prenom_client, EMAIL = :email_client, TELEPHONE = :tel_client, "
                       "TYPE_CLIENT = :type_client, ADRESSE = :adresse_client, DATE_INSCRIPTION = :date_inscri_client, SPECIALITE = :specialite_client "
                       "WHERE IDCLIENT = :id_client"))
    {
        qDebug() << "Erreur de préparation de la requête:" << query.lastError().text();
        return false;
    }

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
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }

    return true;
}


