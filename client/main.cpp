#include "loginwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set organization and application name for settings
    QCoreApplication::setOrganizationName("YourCompany");
    QCoreApplication::setApplicationName("EmployeeSystem");

    // Initialize database connection
    Connection c;
    if(!c.createconnect()) {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to connect to database.\nClick Cancel to exit.",
                              QMessageBox::Cancel);
        return -1;
    }

    qDebug() << "Application starting...";

    // Create and show login window
    LoginWindow loginWindow;
    loginWindow.show();

    qDebug() << "Login window shown, entering event loop...";
    return a.exec();
}
