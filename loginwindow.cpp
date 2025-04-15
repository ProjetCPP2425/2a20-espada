#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "employe.h"
#include <QSqlError>
#include <QMessageBox>
#include <QInputDialog>
#include <QRegularExpression>
#include <QDebug>

LoginWindow *LoginWindow::instance = nullptr;
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow),
    smtpSocket(new QSslSocket(this)),
    currentTask("")
{
    instance = this;
    ui->setupUi(this);
    setWindowTitle("Login");
    setFixedSize(size());

    // Password field setup
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    // SMTP connections
    connect(smtpSocket, &QSslSocket::readyRead, this, &LoginWindow::smtpReadyRead);
    connect(smtpSocket, &QSslSocket::connected, this, &LoginWindow::smtpConnected);
    connect(smtpSocket, QOverload<QAbstractSocket::SocketError>::of(&QSslSocket::errorOccurred),
            this, &LoginWindow::smtpError);
}
void LoginWindow::showMainWindow()
{
    this->hide();
    Employe *mainWindow = new Employe();
    connect(mainWindow, &Employe::destroyed, this, [this]() {
        this->show();
    });
    mainWindow->show();
}
LoginWindow::~LoginWindow()
{
    delete smtpSocket;
    delete ui;
}

LoginWindow::SmtpAccount LoginWindow::getSmtpAccountForEmail(const QString &email)
{
    QMap<QString, SmtpAccount> accounts;

    // Gmail configuration
    accounts["@gmail.com"] = {
        "smtp.gmail.com",
        465,
        "mbenlakhal1@gmail.com",
        "ichiaoonypnngxhd",
        "mbenlakhal1@gmail.com"
    };

    // Outlook configuration
    accounts["@outlook.com"] = {
        "smtp.office365.com",
        587,
        "your_email@outlook.com",
        "your_password",
        "your_email@outlook.com"
    };

    // Default configuration
    SmtpAccount defaultAccount = {
        "smtp.yourdomain.com",
        465,
        "noreply@yourdomain.com",
        "your_password",
        "noreply@yourdomain.com"
    };

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (email.contains(it.key())) {
            return it.value();
        }
    }

    return defaultAccount;
}

bool LoginWindow::comparePasswords(const QString &dbPassword, const QString &inputPassword)
{
    QString normalizedDb = dbPassword.normalized(QString::NormalizationForm_C);
    QString normalizedInput = inputPassword.normalized(QString::NormalizationForm_C);
    return normalizedDb == normalizedInput;
}

QString LoginWindow::generateRandomPassword(int length)
{
    const QString upper = "ABCDEFGHJKLMNPQRSTUVWXYZ";
    const QString lower = "abcdefghijkmnpqrstuvwxyz";
    const QString digits = "23456789";
    const QString special = "!@#$%&*";

    QString allChars = upper + lower + digits + special;
    QString password;
    password.reserve(length);

    // Ensure at least one character from each category
    password.append(upper.at(QRandomGenerator::global()->bounded(upper.length())));
    password.append(lower.at(QRandomGenerator::global()->bounded(lower.length())));
    password.append(digits.at(QRandomGenerator::global()->bounded(digits.length())));
    password.append(special.at(QRandomGenerator::global()->bounded(special.length())));

    // Shuffle the password
    std::random_shuffle(password.begin(), password.end());

    return password;
}

bool LoginWindow::validateEmail(const QString &email)
{
    QRegularExpression regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex.match(email).hasMatch();
}

void LoginWindow::sendSmtpCommand(const QString &command)
{
    lastCommand = command;
    qDebug() << "SMTP >>" << command;
    smtpSocket->write(command.toUtf8() + "\r\n");
    smtpSocket->waitForBytesWritten(1000);
}

void LoginWindow::sendPasswordResetEmail(const QString &email, const QString &username, const QString &tempPassword)
{
    SmtpAccount account = getSmtpAccountForEmail(email);

    this->emailRecipient = email;
    this->tempPassword = tempPassword;
    this->emailUsername = username;

    emailData = QString(
                    "From: \"Password Reset\" <%1>\r\n"
                    "To: <%2>\r\n"
                    "Subject: Password Reset\r\n"
                    "\r\n"
                    "Dear %3,\r\n\n"
                    "Your temporary password is: %4\r\n\n"
                    "Please login and change it immediately.\r\n\n"
                    "This is an automated message.\r\n"
                    ".\r\n").arg(account.fromEmail, email, username, tempPassword);

    qDebug() << "Connecting to SMTP server:" << account.host << ":" << account.port;
    smtpSocket->connectToHostEncrypted(account.host, account.port);

    if (!smtpSocket->waitForConnected(10000)) {
        QMessageBox::critical(this, "Connection Error",
                              QString("Failed to connect to SMTP server: %1").arg(smtpSocket->errorString()));
        return;
    }
}

void LoginWindow::smtpConnected()
{
    qDebug() << "SMTP Connected";
}

void LoginWindow::smtpReadyRead()
{
    QString response;
    while (smtpSocket->canReadLine()) {
        response = smtpSocket->readLine();
        qDebug() << "SMTP:" << response.trimmed();

        if (response.startsWith("5")) {
            QMessageBox::critical(this, "SMTP Error",
                                  QString("Server rejected command: %1").arg(response.trimmed()));
            smtpSocket->disconnectFromHost();
            return;
        }

        if (response.startsWith("220")) {
            sendSmtpCommand("EHLO client");
        }
        else if (response.startsWith("250")) {
            if (response.contains("EHLO")) {
                sendSmtpCommand("AUTH LOGIN");
            }
            else if (lastCommand == "AUTH LOGIN") {
                SmtpAccount account = getSmtpAccountForEmail(emailRecipient);
                sendSmtpCommand(QString(account.user).toUtf8().toBase64());
            }
            else if (lastCommand == getSmtpAccountForEmail(emailRecipient).user.toUtf8().toBase64()) {
                SmtpAccount account = getSmtpAccountForEmail(emailRecipient);
                sendSmtpCommand(QString(account.password).toUtf8().toBase64());
            }
            else if (lastCommand == getSmtpAccountForEmail(emailRecipient).password.toUtf8().toBase64()) {
                SmtpAccount account = getSmtpAccountForEmail(emailRecipient);
                sendSmtpCommand(QString("MAIL FROM:<%1>").arg(account.fromEmail));
            }
            else if (lastCommand.startsWith("MAIL FROM")) {
                sendSmtpCommand(QString("RCPT TO:<%1>").arg(emailRecipient));
            }
            else if (lastCommand.startsWith("RCPT TO")) {
                sendSmtpCommand("DATA");
            }
            else if (lastCommand == "DATA") {
                sendSmtpCommand(emailData);
            }
            else if (lastCommand == emailData) {
                sendSmtpCommand("QUIT");
            }
        }
        else if (response.startsWith("334")) {
            if (lastCommand == "AUTH LOGIN") {
                SmtpAccount account = getSmtpAccountForEmail(emailRecipient);
                sendSmtpCommand(QString(account.user).toUtf8().toBase64());
            }
            else {
                SmtpAccount account = getSmtpAccountForEmail(emailRecipient);
                sendSmtpCommand(QString(account.password).toUtf8().toBase64());
            }
        }
        else if (response.startsWith("235")) {
            SmtpAccount account = getSmtpAccountForEmail(emailRecipient);
            sendSmtpCommand(QString("MAIL FROM:<%1>").arg(account.fromEmail));
        }
        else if (response.startsWith("354")) {
            sendSmtpCommand(emailData);
        }
        else if (response.startsWith("221")) {
            QMessageBox::information(this, "Success",
                                     "Password reset email sent to " + emailRecipient);
        }
    }
}

void LoginWindow::smtpError(QAbstractSocket::SocketError error)
{
    QString errorMsg;

    switch(error) {
    case QAbstractSocket::HostNotFoundError:
        errorMsg = "SMTP server not found. Please check your network connection and server address.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        errorMsg = "Connection refused - server may be down or port blocked";
        break;
    case QAbstractSocket::SocketTimeoutError:
        errorMsg = "Connection timed out - server may be busy or network slow";
        break;
    case QAbstractSocket::SslHandshakeFailedError:
        errorMsg = "SSL handshake failed - check encryption settings";
        break;
    default:
        errorMsg = smtpSocket->errorString();
    }

    QMessageBox::critical(this, "SMTP Error",
                          QString("Cannot send email: %1").arg(errorMsg));
}

bool LoginWindow::updatePasswordInDatabase(const QString &email, const QString &newPassword)
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET MDP = :password WHERE EMAIL = :email");
    query.bindValue(":password", newPassword);
    query.bindValue(":email", email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error",
                              QString("Failed to update password: %1").arg(query.lastError().text()));
        return false;
    }

    return query.numRowsAffected() > 0;
}

QString LoginWindow::getUsernameFromEmail(const QString &email)
{
    QSqlQuery query;
    query.prepare("SELECT LOGIN FROM EMPLOYE WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error",
                              QString("Failed to query database: %1").arg(query.lastError().text()));
        return QString();
    }

    if (query.next()) {
        return query.value("LOGIN").toString();
    }

    return QString();
}

void LoginWindow::on_forgotPasswordButton_clicked()
{
    bool ok;
    QString email = QInputDialog::getText(this, "Password Reset",
                                          "Enter your email:",
                                          QLineEdit::Normal, "", &ok).trimmed();

    if (!ok || email.isEmpty()) return;

    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address (e.g., user@example.com)");
        return;
    }

    QString username = getUsernameFromEmail(email);
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Email Not Found", "This email address is not registered in our system.");
        return;
    }

    QString tempPassword = generateRandomPassword(10);
    if (!updatePasswordInDatabase(email, tempPassword)) {
        QMessageBox::critical(this, "Error", "Failed to reset password. Please try again later.");
        return;
    }

    sendPasswordResetEmail(email, username, tempPassword);
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->lineEdit_username->text().trimmed();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Username and password cannot be empty!");
        return;
    }
    if (currentTask == "employe") {
        mainWindow = new Employe();  // Store the pointer
        mainWindow->show();
        this->close();
    }
    QSqlQuery query;
    if (!query.prepare("SELECT LOGIN, MDP FROM EMPLOYE WHERE LOGIN = :username")) {
        QMessageBox::critical(this, "Error", "Database preparation failed: " + query.lastError().text());
        return;
    }

    query.bindValue(":username", username);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        QString dbPassword = query.value("MDP").toString();
        currentTask = "";

        for (auto it = taskPasswords.begin(); it != taskPasswords.end(); ++it) {
            if (comparePasswords(it.value(), dbPassword)) {
                currentTask = it.key();
                break;
            }
        }

        if (currentTask.isEmpty()) {
            QMessageBox::warning(this, "Login Failed", "Invalid password!");
            return;
        }

        if (currentTask == "employe") {
            Employe *mainWindow = new Employe();
            mainWindow->show();
            this->close();
        } else {
            QMessageBox::information(this, "Success",
                                     QString("Login successful for task: %1").arg(currentTask));
        }
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username!");
    }
}
