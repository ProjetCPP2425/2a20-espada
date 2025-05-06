#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QSqlError>
#include <QMessageBox>
#include <QInputDialog>
#include <QRegularExpression>
#include <QDebug>
#include <QApplication>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow),
    smtpSocket(new QSslSocket(this)),
    currentTask(""),
    smtpState(Disconnected)
{
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

    // Fill the rest with random characters
    for (int i = password.length(); i < length; ++i) {
        password.append(allChars.at(QRandomGenerator::global()->bounded(allChars.length())));
    }

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
                    "MIME-Version: 1.0\r\n"
                    "Content-Type: text/plain; charset=utf-8\r\n"
                    "\r\n"
                    "Dear %3,\r\n\n"
                    "Your temporary password is: %4\r\n\n"
                    "Please login and change it immediately.\r\n\n"
                    "This is an automated message.\r\n").arg(account.fromEmail, email, username, tempPassword);

    qDebug() << "Connecting to SMTP server:" << account.host << ":" << account.port;

    // Configure SSL
    smtpSocket->setProtocol(QSsl::TlsV1_2OrLater);
    smtpSocket->connectToHostEncrypted(account.host, account.port);

    if (!smtpSocket->waitForConnected(10000)) {
        QMessageBox::critical(this, "Connection Error",
                              QString("Failed to connect to SMTP server: %1").arg(smtpSocket->errorString()));
        return;
    }

    smtpState = Connected;
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
        qDebug() << "SMTP <<" << response.trimmed();

        if (response.startsWith("5")) {
            QMessageBox::critical(this, "SMTP Error",
                                  QString("Server rejected command: %1").arg(response.trimmed()));
            smtpSocket->disconnectFromHost();
            return;
        }

        SmtpAccount account = getSmtpAccountForEmail(emailRecipient);

        switch(smtpState) {
        case Connected:
            if (response.startsWith("220")) {
                sendSmtpCommand("EHLO client");
                smtpState = EhloSent;
            }
            break;

        case EhloSent:
            if (response.startsWith("250")) {
                sendSmtpCommand("AUTH LOGIN");
                smtpState = AuthSent;
            }
            break;

        case AuthSent:
            if (response.startsWith("334")) {
                sendSmtpCommand(QString(account.user).toUtf8().toBase64());
                smtpState = UserSent;
            }
            break;

        case UserSent:
            if (response.startsWith("334")) {
                sendSmtpCommand(QString(account.password).toUtf8().toBase64());
                smtpState = PassSent;
            }
            break;

        case PassSent:
            if (response.startsWith("235")) {
                sendSmtpCommand(QString("MAIL FROM:<%1>").arg(account.fromEmail));
                smtpState = MailFromSent;
            }
            break;

        case MailFromSent:
            if (response.startsWith("250")) {
                sendSmtpCommand(QString("RCPT TO:<%1>").arg(emailRecipient));
                smtpState = RcptToSent;
            }
            break;

        case RcptToSent:
            if (response.startsWith("250")) {
                sendSmtpCommand("DATA");
                smtpState = DataSent;
            }
            break;

        case DataSent:
            if (response.startsWith("354")) {
                sendSmtpCommand(emailData);
                smtpState = SendingData;
            }
            break;

        case SendingData:
            if (response.startsWith("250")) {
                sendSmtpCommand("QUIT");
                smtpState = QuitSent;
            }
            break;

        case QuitSent:
            if (response.startsWith("221")) {
                QMessageBox::information(this, "Success",
                                         "Password reset email sent to " + emailRecipient);
            }
            smtpSocket->disconnectFromHost();
            break;

        default:
            break;
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

        // Check password against all task passwords
        for (auto it = taskPasswords.begin(); it != taskPasswords.end(); ++it) {
            if (comparePasswords(it.value(), password)) {
                currentTask = it.key();
                break;
            }
        }

        if (currentTask.isEmpty()) {
            QMessageBox::warning(this, "Login Failed", "Invalid password!");
            return;
        }

        // Handle the specific task
        if (currentTask == "employe") {
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
            this->hide();
            mainWindow->setRdvBoxVisible(false);  // Hide RDV-related UI
            mainWindow->setEmpBoxVisible(true);   // Show employee-related UI          // Connect the destroyed signal to show login window again
            connect(mainWindow, &MainWindow::destroyed, this, [this]() {
                this->show();
                ui->lineEdit_username->clear();
                ui->lineEdit_password->clear();
                ui->lineEdit_username->setFocus();
            });
        }
        else if (currentTask == "task2") {
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
            this->hide();
            mainWindow->setRdvBoxVisible(true);   // Show RDV-related UI
            mainWindow->setEmpBoxVisible(false);  // Hide employee-related UI

            // Connect the destroyed signal to show login window again
            connect(mainWindow, &MainWindow::destroyed, this, [this]() {
                this->show();
                ui->lineEdit_username->clear();
                ui->lineEdit_password->clear();
                ui->lineEdit_username->setFocus();
            });
        }
        else if (currentTask == "task3") {
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
            this->hide();
            mainWindow->setRdvBoxVisible(false);    // Hide RDV-related UI
            mainWindow->setEmpBoxVisible(false);    // Hide employee-related UI
            mainWindow->setClientBoxVisible(true);  // Show client-related UI

            // Connect the destroyed signal to show login window again
            connect(mainWindow, &MainWindow::destroyed, this, [this]() {
                this->show();
                ui->lineEdit_username->clear();
                ui->lineEdit_password->clear();
                ui->lineEdit_username->setFocus();
            });
        }
        else if (currentTask == "task4") {
            QMessageBox::information(this, "Task 4", "Task 4 functionality would be implemented here");
        }
        else if (currentTask == "task5") {
            QMessageBox::information(this, "Task 5", "Task 5 functionality would be implemented here");
        }
        else if (currentTask == "task6") {
            QMessageBox::information(this, "Task 6", "Task 6 functionality would be implemented here");
        }
        else {
            QMessageBox::information(this, "Success",
                                     QString("Login successful for task: %1").arg(currentTask));
        }
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username!");
    }
}
