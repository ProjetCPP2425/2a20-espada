#ifndef SMSSENDER_H
#define SMSSENDER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class SMSSender : public QObject
{
    Q_OBJECT
public:
    explicit SMSSender(QObject *parent = nullptr);
    bool sendSMS(const QString &phoneNumber, const QString &message);

private:
    // Twilio credentials
    const QString ACCOUNT_SID = "AC7ea2f4c6c354104cf2d346032f34cd02";
    const QString AUTH_TOKEN = "7fe536f971026350b65f3ec243cc7639";
    const QString TWILIO_NUMBER = "+19472172605";
};

#endif // SMSSENDER_H
