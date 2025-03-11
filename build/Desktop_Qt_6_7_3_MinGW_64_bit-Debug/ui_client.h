/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_6;
    QWidget *widget_3;
    QFrame *frame_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *widget_7;
    QPushButton *pushButton_supprimer;
    QWidget *widget_9;
    QLineEdit *lineEdit_3;
    QFrame *frame_4;
    QLineEdit *id_client;
    QLineEdit *nom_client;
    QLineEdit *prenom_client;
    QLineEdit *email_client;
    QLineEdit *type_client;
    QLineEdit *specialite_client;
    QLineEdit *tel_client;
    QLineEdit *adresse_client;
    QDateEdit *date_inscri_client;
    QLineEdit *id_emp;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_ajouter;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_34;
    QTableView *tableView;
    QLabel *label_35;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName("client");
        client->resize(1099, 717);
        centralwidget = new QWidget(client);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, -10, 951, 641));
        widget->setStyleSheet(QString::fromUtf8("background-color:#ECF8F6;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 10, 931, 71));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 20, 271, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        frame = new QFrame(widget_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(670, 0, 120, 71));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/Downloads/uso.jfif);"));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(840, 10, 80, 51));
        pushButton->setStyleSheet(QString::fromUtf8("color:black;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/log-out (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 10, 80, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 11pt \"Segoe UI\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Downloads/home.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(360, 90, 421, 121));
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(40, 20, 391, 51));
        frame_2 = new QFrame(widget_3);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 0, 281, 41));
        frame_2->setStyleSheet(QString::fromUtf8("border :2px solid black;\n"
"border-radius:20px;"));
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(11, 11, 28, 22));
        label_2->setStyleSheet(QString::fromUtf8("border:none;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/search (1).svg")));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(45, 11, 241, 22));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(300, 10, 80, 24));
        QFont font1;
        font1.setBold(true);
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon2);
        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(40, 80, 281, 42));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../../pie-chart (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../../file-text (2).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_6);

        widget_7 = new QWidget(widget);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(30, 100, 291, 511));
        widget_7->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:30px;\n"
"background-color:none;"));
        pushButton_supprimer = new QPushButton(widget_7);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(190, 470, 81, 24));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        pushButton_supprimer->setFont(font2);
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../../check-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_supprimer->setIcon(icon5);
        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(130, 30, 151, 391));
        widget_9->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        lineEdit_3 = new QLineEdit(widget_9);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(9, 45, 106, 18));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border:1px;"));
        frame_4 = new QFrame(widget_9);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(9, 10, 131, 371));
        frame_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame_4->setFrameShape(QFrame::Shape::NoFrame);
        id_client = new QLineEdit(frame_4);
        id_client->setObjectName("id_client");
        id_client->setGeometry(QRect(10, 9, 113, 24));
        id_client->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"color: rgb(0, 0, 0);"));
        nom_client = new QLineEdit(frame_4);
        nom_client->setObjectName("nom_client");
        nom_client->setGeometry(QRect(10, 53, 113, 24));
        nom_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        prenom_client = new QLineEdit(frame_4);
        prenom_client->setObjectName("prenom_client");
        prenom_client->setGeometry(QRect(10, 92, 113, 24));
        prenom_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        email_client = new QLineEdit(frame_4);
        email_client->setObjectName("email_client");
        email_client->setGeometry(QRect(10, 133, 113, 24));
        email_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        type_client = new QLineEdit(frame_4);
        type_client->setObjectName("type_client");
        type_client->setGeometry(QRect(10, 216, 113, 24));
        type_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        specialite_client = new QLineEdit(frame_4);
        specialite_client->setObjectName("specialite_client");
        specialite_client->setGeometry(QRect(10, 340, 113, 24));
        specialite_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        tel_client = new QLineEdit(frame_4);
        tel_client->setObjectName("tel_client");
        tel_client->setGeometry(QRect(10, 180, 113, 24));
        tel_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        adresse_client = new QLineEdit(frame_4);
        adresse_client->setObjectName("adresse_client");
        adresse_client->setGeometry(QRect(10, 260, 113, 24));
        adresse_client->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        date_inscri_client = new QDateEdit(frame_4);
        date_inscri_client->setObjectName("date_inscri_client");
        date_inscri_client->setGeometry(QRect(10, 300, 110, 25));
        id_emp = new QLineEdit(widget_7);
        id_emp->setObjectName("id_emp");
        id_emp->setGeometry(QRect(150, 420, 113, 24));
        id_emp->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(20, 30, 111, 391));
        widget_8->setStyleSheet(QString::fromUtf8("border:none;"));
        verticalLayout = new QVBoxLayout(widget_8);
        verticalLayout->setObjectName("verticalLayout");
        label_28 = new QLabel(widget_8);
        label_28->setObjectName("label_28");
        label_28->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_28);

        label_29 = new QLabel(widget_8);
        label_29->setObjectName("label_29");
        label_29->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_29);

        label_30 = new QLabel(widget_8);
        label_30->setObjectName("label_30");
        label_30->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_30);

        label_31 = new QLabel(widget_8);
        label_31->setObjectName("label_31");
        label_31->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_31);

        label_32 = new QLabel(widget_8);
        label_32->setObjectName("label_32");
        label_32->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_32);

        label_33 = new QLabel(widget_8);
        label_33->setObjectName("label_33");
        label_33->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_33);

        label_48 = new QLabel(widget_8);
        label_48->setObjectName("label_48");
        label_48->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_48);

        label_49 = new QLabel(widget_8);
        label_49->setObjectName("label_49");
        label_49->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_49);

        label_50 = new QLabel(widget_8);
        label_50->setObjectName("label_50");
        label_50->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_50);

        label_51 = new QLabel(widget_7);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(30, 420, 93, 36));
        label_51->setStyleSheet(QString::fromUtf8("color:black;"));
        pushButton_modifier = new QPushButton(widget_7);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(100, 470, 81, 24));
        pushButton_modifier->setFont(font2);
        pushButton_modifier->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0;"));
        pushButton_modifier->setIcon(icon5);
        pushButton_ajouter = new QPushButton(widget_7);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(10, 470, 81, 24));
        pushButton_ajouter->setFont(font2);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0;"));
        pushButton_ajouter->setIcon(icon5);
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(115, 84, 111, 34));
        horizontalLayout_2 = new QHBoxLayout(widget_10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_34 = new QLabel(widget_10);
        label_34->setObjectName("label_34");
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label_34->setFont(font3);
        label_34->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_2->addWidget(label_34);

        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(360, 250, 571, 281));
        label_35 = new QLabel(widget);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(360, 220, 93, 16));
        label_35->setFont(font3);
        label_35->setStyleSheet(QString::fromUtf8("color:black;"));
        client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(client);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1099, 21));
        client->setMenuBar(menubar);
        statusbar = new QStatusBar(client);
        statusbar->setObjectName("statusbar");
        client->setStatusBar(statusbar);

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QMainWindow *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "client", nullptr));
        label->setText(QCoreApplication::translate("client", "Gestion Des Clients", nullptr));
        pushButton->setText(QCoreApplication::translate("client", "Log Out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("client", "Home", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("client", "  Rechercher...", nullptr));
        pushButton_4->setText(QCoreApplication::translate("client", "filter", nullptr));
        pushButton_5->setText(QCoreApplication::translate("client", "Statestiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("client", "Pdf", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("client", "supprimer", nullptr));
        id_client->setPlaceholderText(QCoreApplication::translate("client", " taper l'id... ", nullptr));
        nom_client->setPlaceholderText(QCoreApplication::translate("client", "taper le nom...", nullptr));
        prenom_client->setPlaceholderText(QCoreApplication::translate("client", "taper le prenom...", nullptr));
        email_client->setPlaceholderText(QCoreApplication::translate("client", "email...", nullptr));
        type_client->setPlaceholderText(QCoreApplication::translate("client", "type...", nullptr));
        specialite_client->setPlaceholderText(QCoreApplication::translate("client", "specialite...", nullptr));
        tel_client->setPlaceholderText(QCoreApplication::translate("client", "+216 ...", nullptr));
        adresse_client->setPlaceholderText(QCoreApplication::translate("client", "adresse...", nullptr));
        id_emp->setPlaceholderText(QCoreApplication::translate("client", "id employe...", nullptr));
        label_28->setText(QCoreApplication::translate("client", "Id client :", nullptr));
        label_29->setText(QCoreApplication::translate("client", "Nom :", nullptr));
        label_30->setText(QCoreApplication::translate("client", "Prenom :", nullptr));
        label_31->setText(QCoreApplication::translate("client", "Email :", nullptr));
        label_32->setText(QCoreApplication::translate("client", "Numero :", nullptr));
        label_33->setText(QCoreApplication::translate("client", "Type :", nullptr));
        label_48->setText(QCoreApplication::translate("client", "Adresse:", nullptr));
        label_49->setText(QCoreApplication::translate("client", "Date inscription:", nullptr));
        label_50->setText(QCoreApplication::translate("client", "Specialite:", nullptr));
        label_51->setText(QCoreApplication::translate("client", "Id employe :", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("client", "modifier", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("client", "Confirmer", nullptr));
        label_34->setText(QCoreApplication::translate("client", "     Ajouter", nullptr));
        label_35->setText(QCoreApplication::translate("client", "Client:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
