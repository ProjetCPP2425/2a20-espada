#include "arduino_employe.h"
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QDebug>

Arduino_EMPLOYE::Arduino_EMPLOYE()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString Arduino_EMPLOYE::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort* Arduino_EMPLOYE::getserial()
{
    return serial;
}

int Arduino_EMPLOYE::connect_arduino()
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

int Arduino_EMPLOYE::close_arduino()
{
    if (serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino_EMPLOYE::read_from_arduino()
{
    if (serial->isReadable()){
        data = serial->readAll();
        return data;
    }
    return QByteArray();
}

/*void Arduino_EMPLOYE::handleSerialData()
{
    QByteArray sensorData = read_from_arduino();
    QString uid = QString(sensorData).trimmed();
    qDebug() << "UID vide reçu, aucune action."<< uid;
    if (uid.isEmpty()) {
        qDebug() << "UID vide reçu, aucune action.";
        return;
    }

    qDebug() << "UID détecté nettoyé:" << uid;

    verifierCarte(uid);
}
void Arduino_EMPLOYE::handleSerialData()
{

    QByteArray sensorData = read_from_arduino();
    QString uid = QString(sensorData).trimmed();



    qDebug() << "UID détecté nettoyé:" << uid;

    verifierCarte(uid);
}


void Arduino_EMPLOYE::verifierCarte(QString uid)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE CARD_UID = :CARD_UID");
    query.bindValue(":CARD_UID", uid);

    query.prepare("SELECT * FROM EMPLOYE WHERE CARD_UID = '105874064'");
    query.bindValue(":CARD_UID", uid);

    if (query.exec()) {
        if (query.next()) {

            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();

            qDebug() << "Accès autorisé pour:" << nom << prenom;

            write_to_arduino("1"); // Signal Arduino pour ouvrir

        } else {
            qDebug() << "UID non reconnu - accès refusé";
        }
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    }
}*/



   /* void Arduino_EMPLOYE::handleSerialData()
{
    QByteArray sensorData = read_from_arduino();
    qDebug() << "Brut (hex):" << sensorData.toHex();

    QString uid = QString::fromUtf8(sensorData).trimmed();
    qDebug() << "UID nettoyé:" << uid;

    if (uid.isEmpty()) {
        qDebug() << "UID vide reçu";
        return;
    }

    verifierCarte(uid);
}

void Arduino_EMPLOYE::verifierCarte(QString uid)
{
    qDebug() << "UID à vérifier:" << uid;

    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM, CARD_UID FROM EMPLOYE WHERE CARD_UID = :CARD_UID");
    query.bindValue(":CARD_UID", uid);

    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        write_to_arduino("0"); // envoyer échec à Arduino
        return;
    }

    if (query.next()) {
        QString nom = query.value("NOM").toString();
        QString prenom = query.value("PRENOM").toString();
        QString uidFromDB = query.value("CARD_UID").toString();

        qDebug() << "UID trouvé:" << uidFromDB;
        qDebug() << "Accès autorisé pour:" << nom << prenom;

        write_to_arduino("1"); // autoriser
    } else {
        qDebug() << "Accès refusé pour UID:" << uid;
        write_to_arduino("0"); // refuser
    }
}
*/



void Arduino_EMPLOYE::handleSerialData()
{
    QByteArray sensorData = read_from_arduino();
    QString data = QString::fromUtf8(sensorData).trimmed();
    qDebug() << "Données brutes reçues:" << data;

    // Si Arduino envoie un message ("Access Denied!" ou autre), on ignore
    if (data.contains("Access Denied") || data.isEmpty()) {
        qDebug() << "Message système ignoré";
        return;
    }

    qDebug() << "UID détecté:" << data;

    verifierCarte(data);
}

void Arduino_EMPLOYE::verifierCarte(QString uid)
{
    qDebug() << "Vérification UID:" << uid;

    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM FROM EMPLOYE WHERE CARD_UID = :CARD_UID");
    query.bindValue(":CARD_UID", uid);

    if (!query.exec()) {
        qDebug() << "Erreur requête:" << query.lastError().text();
        write_to_arduino("0"); // échec
        return;
    }

    if (query.next()) {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();

        qDebug() << "Accès autorisé pour:" << nom << prenom;

        write_to_arduino("1"); // ouvrir
    } else {
        qDebug() << "UID inconnu:" << uid;
        write_to_arduino("0"); // refuser
    }
}


void Arduino_EMPLOYE::write_to_arduino(QByteArray data)
{
    if (serial->isWritable()) {
        serial->write(data);
    } else {
        qDebug() << "Impossible d'écrire sur Arduino.";
    }
}
