#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_Projet2A");//inserer le nom de la source de données
    db.setUserName("uso");//inserer nom de l'utilisateur
    db.setPassword("uso");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
