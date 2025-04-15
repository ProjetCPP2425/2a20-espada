#include "projet.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSslSocket>

int main(int argc, char *argv[])
{
    qDebug() << "SSL supported:" << QSslSocket::supportsSsl();
    qDebug() << "SSL version:" << QSslSocket::sslLibraryVersionString();
    QApplication a(argc, argv);

    connection c;
    bool test = c.createconnect();  // Try to establish a database connection
    Projet w;  // Create the main window

    if (test) {
        w.show();  // Show the main window if the connection is successful
        QMessageBox::information(nullptr, QObject::tr("Database is Open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
    } else {
        // Show an error message if the connection fails
        w.show();
        QMessageBox::critical(nullptr, QObject::tr("Database is not Open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }

    return a.exec();  // Start the event loop
}
