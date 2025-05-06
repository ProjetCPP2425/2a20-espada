#include "Arduino_RDV.h"
#include <QtSql/QSqlQuery>
#include <QSqlError>

Arduino_RDV::Arduino_RDV()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString Arduino_RDV::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort* Arduino_RDV::getserial()
{
    return serial;
}

int Arduino_RDV::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_product_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name;

    if (arduino_is_available){
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino_RDV::close_arduino()
{
    if (serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino_RDV::read_from_arduino()
{
    if (serial->isReadable()){
        data = serial->readAll(); // récupérer les données lues depuis le capteur
        return data;
    }
    return QByteArray();
}

void Arduino_RDV::handleSerialData()
{
    QByteArray sensorData = read_from_arduino();

    // Nettoyer les données lues en supprimant les espaces et les caractères de fin de ligne
    QString color = QString(sensorData).trimmed();

    // Afficher la couleur détectée après nettoyage
    qDebug() << "Cleaned Color detected: " << color;

    // Manipuler la base de données en fonction de la couleur détectée
    updateDatabaseWithColor(color);
}


void Arduino_RDV::updateDatabaseWithColor(QString color)
{
    color = color.trimmed();
    qDebug() << "Couleur détectée:" << color;

    QSqlQuery query;
    QString lcdMsg;

    if (color == "Whit") {
        query.prepare("UPDATE RESSOURCE SET QUANTITE = QUANTITE + 1 WHERE NOM = 'Projecteur'");
        lcdMsg = "Ajout Projecteur";
    }
    else if (color == "Blue") {
        query.prepare("UPDATE RESSOURCE SET QUANTITE = QUANTITE - 1 WHERE NOM = 'Projecteur'");
        lcdMsg = "Supp Projecteur";
    }
    else {
        return;
    }

    if (!query.exec()) {
        qDebug() << "Erreur de mise à jour:" << query.lastError();
    } else {
        qDebug() << "Mise à jour réussie pour couleur:" << color;
        afficherMessageLCD(lcdMsg);  // Affiche le message sur le LCD via Arduino
    }
}
void Arduino_RDV::afficherMessageLCD(QString message)
{
    if (serial->isWritable()) {
        // Préfixe spécial pour l'Arduino (ex: '@') pour distinguer un message à afficher
        QString lcdMessage = "@"+message+"\n";
        serial->write(lcdMessage.toUtf8());
        qDebug() << "Message envoyé à l'Arduino pour LCD:" << lcdMessage;
    }
}



