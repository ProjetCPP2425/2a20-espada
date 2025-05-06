#include "arduino.h"
#include <QDebug>
#include <QSerialPortInfo>  // Add this line

Arduino::Arduino(QObject *parent) : QObject(parent),
    currentSmokeState(false)
{
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &Arduino::readSerialData);
}

Arduino::~Arduino()
{
    closeConnection();
}

bool Arduino::connectToArduino()
{
    arduino_is_available = false;

    // Use range-based for loop instead of foreach macro
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : ports) {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id &&
                serialPortInfo.productIdentifier() == arduino_uno_product_id) {
                arduino_port_name = serialPortInfo.portName();
                arduino_is_available = true;
                break;
            }
        }
    }

    if(arduino_is_available) {
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        return true;
    }

    emit arduinoError("Couldn't find the Arduino!");
    return false;
}

void Arduino::closeConnection()
{
    if(arduino->isOpen()) {
        arduino->close();
    }
}

void Arduino::readSerialData()
{
    while(arduino->canReadLine()) {
        QString serialData = QString::fromStdString(arduino->readLine().toStdString());
        serialData = serialData.trimmed();

        bool ok;
        int sensorValue = serialData.toInt(&ok);
        bool smokeDetected = false;

        if(ok) {
            smokeDetected = (sensorValue > 300);
        } else if (serialData == "SMOKE_DETECTED") {
            smokeDetected = true;
        } else if (serialData == "SMOKE_CLEAR") {
            smokeDetected = false;
        }

        // Only emit if state changed
        if(smokeDetected != currentSmokeState) {
            currentSmokeState = smokeDetected;
            emit smokeStateChanged(currentSmokeState);
        }
    }
}
