#include "smsnotif.h"
#include <QLineEdit>
#include <QComboBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QEventLoop>

const QString SmsNotif::ACCOUNT_SID = "ACe23110ba6b11195fc42f3d3da701f852";  // Remplacer par vos informations
const QString SmsNotif::AUTH_TOKEN = "41debb04dc33abc4a5619a97afad0952";  // Remplacer par vos informations
const QString SmsNotif::TWILIO_NUMBER = "+15855012559";  // Remplacer par votre numéro Twilio

SmsNotif::SmsNotif() {}

bool SmsNotif::envoyerDepuisUI(QWidget* ui)
{
    // Recherche des champs téléphone et état dans l'interface
    QLineEdit* telInput = ui->findChild<QLineEdit*>("telephone");
    QComboBox* etatBox = ui->findChild<QComboBox*>("etat");

    if (!telInput || !etatBox) {
        qDebug() << "❌ Impossible de trouver les champs téléphone ou état dans l'UI.";
        return false;
    }

    QString telephone = telInput->text().trimmed();  // Récupère le numéro
    QString etat = etatBox->currentText();  // Récupère l'état

    if (telephone.isEmpty() || etat.isEmpty()) {
        qDebug() << "❌ Numéro ou état vide.";
        return false;
    }

    // Ajouter l'indicatif tunisien si nécessaire
    if (!telephone.startsWith("+")) {
        telephone = "+216" + telephone;
    }

    qDebug() << "📞 Numéro final:" << telephone;

    // Création du message
    QString message = "Votre ressource a été mise à jour. État: " + etat;
    return sendSMS(telephone, message);  // Appel de la méthode d'envoi SMS
}

bool SmsNotif::sendSMS(const QString& to, const QString& message)
{
    QNetworkAccessManager manager;
    QEventLoop loop;  // Boucle d'événement pour attendre la réponse

    // URL pour l'API Twilio
    QString url = QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(ACCOUNT_SID);
    QUrl serviceUrl(url);
    QNetworkRequest request(serviceUrl);

    // Authentification de base pour Twilio
    QString credentials = ACCOUNT_SID + ":" + AUTH_TOKEN;
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Paramètres du message
    QUrlQuery params;
    params.addQueryItem("To", to);  // Numéro de destination
    params.addQueryItem("From", TWILIO_NUMBER);  // Numéro Twilio
    params.addQueryItem("Body", message);  // Contenu du message

    // Envoi de la requête POST
    QNetworkReply* reply = manager.post(request, params.query(QUrl::FullyEncoded).toUtf8());

    // Connexion de la réponse à la boucle d'événements pour attendre sa fin
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();  // Exécution de la boucle d'événements

    // Traitement de la réponse
    QByteArray response = reply->readAll();
    qDebug() << "📩 Réponse Twilio:" << response;

    bool success = false;
    if (reply->error() == QNetworkReply::NoError) {
        // Si la requête a réussi, analyser la réponse JSON
        QJsonDocument json = QJsonDocument::fromJson(response);
        QString status = json.object()["status"].toString();
        success = (status == "queued" || status == "sent");  // Vérifier si le message est bien envoyé
    } else {
        // En cas d'erreur
        qDebug() << "❌ Erreur d'envoi:" << reply->errorString();
    }

    reply->deleteLater();  // Libérer la mémoire utilisée par la réponse
    return success;  // Retourner true si l'envoi a réussi
}
