#include "smssender.h"
#include <QRegularExpression>

SMSSender::SMSSender(QObject *parent) : QObject(parent)
{
}

bool SMSSender::sendSMS(const QString &phoneNumber, const QString &message)
{
    QNetworkAccessManager manager;
    QEventLoop loop;

    // Format Tunisian number (remove any spaces, dashes, etc.)
    QString cleanNumber = phoneNumber;
    cleanNumber.remove(QRegularExpression("[^0-9]"));

    // Convert to international format (Twilio requires this)
    if (cleanNumber.startsWith("0")) {
        cleanNumber = "+216" + cleanNumber.mid(1); // Turns 01234567 into +2161234567
    } else if (cleanNumber.length() == 8) {
        cleanNumber = "+216" + cleanNumber; // Turns 12345678 into +21612345678
    }

    // Twilio API URL
    QString url = QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(ACCOUNT_SID);
    QUrl serviceUrl(url);
    QNetworkRequest request(serviceUrl);

    // Basic Authentication
    QString credentials = ACCOUNT_SID + ":" + AUTH_TOKEN;
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Message body
    QUrlQuery params;
    params.addQueryItem("To", cleanNumber);
    params.addQueryItem("From", TWILIO_NUMBER);
    params.addQueryItem("Body", message);

    // Send POST request
    QNetworkReply *reply = manager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Check response
    QByteArray response = reply->readAll();
    qDebug() << "Twilio response:" << response;

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        if (jsonResponse.isObject()) {
            QJsonObject obj = jsonResponse.object();
            QString status = obj["status"].toString();
            return status == "queued" || status == "sent";
        }
    } else {
        qDebug() << "Twilio network error:" << reply->errorString();
    }

    reply->deleteLater();
    return false;
}
