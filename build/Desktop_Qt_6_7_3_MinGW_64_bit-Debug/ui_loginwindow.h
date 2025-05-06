/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *widget;
    QFrame *frame;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_username;
    QLabel *label_7;
    QPushButton *loginButton;
    QLabel *label;
    QLabel *label_5;
    QWidget *widget_2;
    QPushButton *forgotPasswordButton;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1296, 731);
        widget = new QWidget(LoginWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 60, 1151, 571));
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(110, 20, 741, 511));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 80, 251, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color:rgba(255,255,255,210);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 70, 161, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:rgba(0,0,0,200);"));
        lineEdit_password = new QLineEdit(frame);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(420, 190, 211, 40));
        QFont font2;
        font2.setPointSize(10);
        lineEdit_password->setFont(font2);
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        lineEdit_username = new QLineEdit(frame);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(420, 130, 211, 40));
        lineEdit_username->setFont(font2);
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 150, 381, 51));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8(""));
        loginButton = new QPushButton(frame);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(420, 250, 221, 41));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        loginButton->setFont(font4);
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#pushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 0, 341, 511));
        QFont font5;
        font5.setPointSize(11);
        label->setFont(font5);
        label->setStyleSheet(QString::fromUtf8("background-color:rgba(225,225,225,255);\n"
"border-bottom-right-radius:50px;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 80, 391, 151));
        QFont font6;
        font6.setPointSize(22);
        font6.setBold(true);
        font6.setItalic(true);
        font6.setUnderline(false);
        font6.setStrikeOut(false);
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,75);"));
        widget_2 = new QWidget(frame);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 401, 511));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Downloads/aaaaaaaaaaa.jpg);"));
        forgotPasswordButton = new QPushButton(frame);
        forgotPasswordButton->setObjectName("forgotPasswordButton");
        forgotPasswordButton->setGeometry(QRect(440, 300, 161, 29));
        widget_2->raise();
        label_5->raise();
        label->raise();
        label_6->raise();
        label_2->raise();
        lineEdit_password->raise();
        lineEdit_username->raise();
        label_7->raise();
        loginButton->raise();
        forgotPasswordButton->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("LoginWindow", "USOconsulting", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Bienvenue", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Mot de passe ", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("LoginWindow", " Nom d'utilisateur", nullptr));
        label_7->setText(QCoreApplication::translate("LoginWindow", "Bienvenue sur l'application!\n"
"Saisissez vos identifiants pour acc\303\251der \303\240 votre compte\n"
" Connectez-vous pour continuer.", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Se Connecter", nullptr));
        label->setText(QString());
        label_5->setText(QString());
        forgotPasswordButton->setText(QCoreApplication::translate("LoginWindow", "mot de passe oubli\303\251 ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
