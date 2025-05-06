#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>

class Arduino : public QObject
{
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();

    bool connectToArduino();
    void closeConnection();
    bool isSmokeDetected() const { return currentSmokeState; }

signals:
    void smokeDetected();
    void smokeCleared();
    void arduinoError(const QString &message);
    void smokeStateChanged(bool detected);

private slots:
    void readSerialData();

private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    bool currentSmokeState;
};

#endif // ARDUINO_H
