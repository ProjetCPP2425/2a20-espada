#include "ressource.h"
#include <QSqlError>  // Ajouter cette ligne
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>

// Constructeur avec paramètres
ressource ::ressource (QString nom, QString description, QString type, QString localisation, int quantite, QString etat)
{
    //this->id = id;
    this->NOM = nom;
    this->DESCRIPTION = description;
    this->TYPE = type;
    this->LOCALISATION = localisation;
    this->QUANTITE = quantite;
    this->ETAT = etat;
}


// Méthode pour ajouter une ressource dans la base de données
bool ressource::ajouter() {
    QSqlQuery query;


    query.prepare("INSERT INTO RESSOURCE (NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT) "
                  "VALUES (:NOM, :DESCRIPTION, :TYPE, :LOCALISATION, :QUANTITE, :ETAT)");

    query.bindValue(":NOM", NOM);
    query.bindValue(":DESCRIPTION", DESCRIPTION);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":LOCALISATION", LOCALISATION);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT);


    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError();
        qDebug() << "Query executed:" << query.lastQuery(); // Print the executed query
        return false;
    }
    return true;
}

// Méthode pour afficher toutes les ressources de la base de données
QSqlQueryModel* ressource::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Localisation"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Etat"));



    return model;
}

// Méthode pour supprimer une ressource en fonction de l'id
bool ressource::supprimer(int ID)
{
    QSqlQuery query;
    QString res=QString::number(ID);

    // Préparer la requête de suppression
    query.prepare("DELETE FROM RESSOURCE WHERE ID = :ID");
    query.bindValue(":ID", res);

    // Exécuter la requête
    return query.exec();
}
ressource ressource::trouver(int ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RESSOURCE WHERE ID = ?");
    query.addBindValue(ID);
    query.exec();
    if (query.next()) {
        return ressource(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),
                         query.value(4).toString(), query.value(5).toInt(), query.value(6).toString());
    }
    return ressource();  // Retourner une ressource vide si non trouvée
}

bool ressource::modifier(int ID)
{
    QSqlQuery query;
    query.prepare("UPDATE RESSOURCE SET NOM = ?, DESCRIPTION = ?, TYPE = ?, LOCALISATION = ?, QUANTITE = ?, ETAT = ? WHERE ID = ?");
    query.addBindValue(NOM);
    query.addBindValue(DESCRIPTION);
    query.addBindValue(TYPE);
    query.addBindValue(LOCALISATION);
    query.addBindValue(QUANTITE);
    query.addBindValue(ETAT);
    query.addBindValue(ID);

    return query.exec();
}



bool ressource::isValid()
{
    return !NOM.isEmpty();  // Si le nom est vide, la ressource est considérée comme invalide
}
