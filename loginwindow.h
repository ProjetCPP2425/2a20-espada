#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "employe.h"
#include <QDialog>
#include <QSslSocket>
#include <QSqlQuery>
#include <QSqlError>  // Added for QSqlError
#include <QMessageBox>
#include <QInputDialog>
#include <QRegularExpression>
#include <QDebug>
#include <QRandomGenerator>  // Added for password generation

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();
    void on_forgotPasswordButton_clicked();
    void smtpReadyRead();
    void smtpConnected();
    void smtpError(QAbstractSocket::SocketError error);

private:
    Ui::LoginWindow *ui;
    Employe *mainWindow;  // Add this line
    QSslSocket *smtpSocket;
    QString currentTask;  // Added missing declaration
    static LoginWindow *instance;
    // Email state
    QString emailRecipient;
    QString tempPassword;
    QString emailUsername;
    QString lastCommand;
    QString emailData;

    // Password management
    const QMap<QString, QString> taskPasswords = {
        {"employe", "ak789A○#"},
        {"task2", "task2pass"},
        {"task3", "task3pass"}
    };

    // SMTP account management
    struct SmtpAccount {
        QString host;
        int port;
        QString user;
        QString password;
        QString fromEmail;
    };
   void showMainWindow();
    SmtpAccount getSmtpAccountForEmail(const QString &email);
    bool comparePasswords(const QString &dbPassword, const QString &inputPassword);
    QString generateRandomPassword(int length = 12);
    bool validateEmail(const QString &email);
    bool updatePasswordInDatabase(const QString &email, const QString &newPassword);
    QString getUsernameFromEmail(const QString &email);
    void sendSmtpCommand(const QString &command);
    void sendPasswordResetEmail(const QString &email, const QString &username, const QString &tempPassword);
    enum SmtpState {
        Disconnected,
        Connected,
        EhloSent,
        AuthSent,
        UserSent,
        PassSent,
        Authenticated,
        MailFromSent,
        RcptToSent,
        DataSent,
        SendingData,
        QuitSent
    };

    SmtpState smtpState;
};

#endif // LOGINWINDOW_H
