<<<<<<< HEAD
#include "loginwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
=======

#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

<<<<<<< HEAD
    // Set organization and application name for settings
    QCoreApplication::setOrganizationName("YourCompany");
    QCoreApplication::setApplicationName("EmployeeSystem");

    // Initialize database connection
    connection c;
    if(!c.createconnect()) {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to connect to database.\nClick Cancel to exit.",
                              QMessageBox::Cancel);
        return -1;
=======
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1
    }

    qDebug() << "Application starting...";

<<<<<<< HEAD
    // Show login window
    LoginWindow login;
    login.show();

    qDebug() << "Login window shown, entering event loop...";
=======
>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1
    return a.exec();

}
