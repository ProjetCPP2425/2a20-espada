#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

class connection
{
    QSqlDatabase db;

public:
    connection();  // Constructeur
    bool createconnection();  // Méthode pour créer une connexion
    void closeconnection();    // Méthode pour fermer la connexion
};

#endif // CONNECTION_H
