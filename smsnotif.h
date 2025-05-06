#ifndef SMSNOTIF_H
#define SMSNOTIF_H

#include <QString>
#include <QWidget>

class SmsNotif {
public:
    SmsNotif();
    bool envoyerDepuisUI(QWidget* ui);
    bool sendSMS(const QString& to, const QString& message);

    static const QString ACCOUNT_SID;
    static const QString AUTH_TOKEN;
    static const QString TWILIO_NUMBER;
};

#endif // SMSNOTIF_H
