#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test = c.createconnection();
    MainWindow w;

    if (test)
    {
        w.show();
        // Afficher un message de réussite pour la connexion
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        // Ici, nous n'utilisons plus QZXing, donc le bloc ci-dessous est supprimé
        // Exemple d'utilisation de QZXing
        // QZXing decoder;
        // QString result = decoder.decodeImage(QImage("path/to/your/image.png")); // Remplacez par le chemin de votre image

        // if (!result.isEmpty()) {
        //     qDebug() << "Decoded text:" << result;
        //     QMessageBox::information(nullptr, QObject::tr("QR Code Decoded"),
        //                              QObject::tr("Decoded text: %1").arg(result), QMessageBox::Ok);
        // } else {
        //     qDebug() << "No QR code found.";
        //     QMessageBox::warning(nullptr, QObject::tr("QR Code Not Found"),
        //                          QObject::tr("No QR code found in the image."), QMessageBox::Ok);
        // }
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
