#ifndef ARDUINO_EMPLOYE_H
#define ARDUINO_EMPLOYE_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino_EMPLOYE
{
public:
    Arduino_EMPLOYE();  // Constructeur de la classe
    int connect_arduino();  // Connexion Arduino
    int close_arduino();  // Déconnexion Arduino
    QByteArray read_from_arduino();  // Lire depuis Arduino
    QSerialPort* getserial();  // Retourner objet QSerialPort
    QString getarduino_port_name();  // Retourner nom du port Arduino
    void processRFIDData() {
        handleSerialData();  // Traiter les données RFID
    }
private:
    void handleSerialData();  // Traiter données reçues
    void verifierCarte(QString uid);  // Vérifier UID dans base de données
    void write_to_arduino(QByteArray data);  // Envoyer commande à Arduino

    QSerialPort *serial;  // Objet communication série
    static const quint16 arduino_uno_vendor_id = 9025;  // ID Vendor Arduino
    static const quint16 arduino_uno_product_id = 67;  // ID Produit Arduino
    QString arduino_port_name;  // Nom du port Arduino
    bool arduino_is_available;  // Disponibilité Arduino
    QByteArray data;  // Données lues
};

#endif // ARDUINO_EMPLOYE_H
