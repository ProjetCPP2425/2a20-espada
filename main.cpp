#include "mainwindow.h"


#include <QApplication>
#include <QMessageBox>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
        w.show();
        // Afficher un message de réussite pour la connexion
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        // Afficher un message d'erreur si la connexion échoue
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();  // Lancer l'application
    }

