#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("uso");//inserer nom de l'utilisateur
    db.setPassword("uso");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}

void connection::closeconnect(){
    db.close();
}
