#ifndef ARDUINO_RDV_H
#define ARDUINO_RDV_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino_RDV
{
public:
    Arduino_RDV();  // Constructeur de la classe
    int connect_arduino();  // Permet de connecter le PC à Arduino
    int close_arduino();  // Permet de fermer la connexion
    QByteArray read_from_arduino();  // Permet de recevoir des données de la carte Arduino
    QSerialPort* getserial();  // Accesseur pour obtenir l'objet QSerialPort
    QString getarduino_port_name();  // Permet d'obtenir le nom du port Arduino
    void processSensorData() {
        handleSerialData();  // Appelle la méthode privée pour traiter les données
    }
private:
    void handleSerialData();  // Permet de traiter les données reçues du capteur
    void updateDatabaseWithColor(QString color);  // Met à jour la base de données selon la couleur lue
    void afficherMessageLCD(QString message);
    QSerialPort *serial;  // L'objet QSerialPort pour gérer la communication série
    static const quint16 arduino_uno_vendor_id = 9025;  // Identifiant du fournisseur de l'Arduino
    static const quint16 arduino_uno_product_id = 67;  // Identifiant du produit de l'Arduino
    QString arduino_port_name;  // Nom du port de l'Arduino
    bool arduino_is_available;  // Indique si l'Arduino est disponible
    QByteArray data;  // Contient les données lues à partir de l'Arduino
};

#endif // ARDUINO_RDV_H
