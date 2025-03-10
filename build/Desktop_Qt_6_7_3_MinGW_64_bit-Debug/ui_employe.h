/********************************************************************************
** Form generated from reading UI file 'employe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE_H
#define UI_EMPLOYE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Employe
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
    QWidget *widget_4;
    QLabel *label_27;
    QTableView *tableView;
    QWidget *widget_7;
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
    QWidget *widget_9;
    QLineEdit *lineEdit_3;
    QFrame *frame_4;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_telephone;
    QLineEdit *lineEdit_experience;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_mdp;
    QComboBox *specialite;
    QComboBox *dispo;
    QPushButton *pushButton_ajouter;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_34;
    QMenuBar *menubar;
    QMenu *menu1;
    QMenu *menu2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Employe)
    {
        if (Employe->objectName().isEmpty())
            Employe->setObjectName("Employe");
        Employe->resize(1187, 600);
        centralwidget = new QWidget(Employe);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, -10, 1131, 601));
        widget->setStyleSheet(QString::fromUtf8("background-color:#ECF8F6;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 10, 1141, 71));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 20, 281, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        frame = new QFrame(widget_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(850, 0, 120, 71));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/Pictures/Screenshots/Screenshot 2025-02-03 203759.png);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1040, 10, 80, 51));
        pushButton->setStyleSheet(QString::fromUtf8("color:black;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/logout.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 10, 80, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 11pt \"Segoe UI\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Downloads/home (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(310, 90, 831, 451));
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(40, 20, 391, 51));
        frame_2 = new QFrame(widget_3);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 0, 281, 41));
        frame_2->setStyleSheet(QString::fromUtf8("border :2px solid black;\n"
"border-radius:20px;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(11, 11, 28, 22));
        label_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image: url(:/Downloads/search (2).svg);"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/search.svg")));
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
        icon2.addFile(QString::fromUtf8(":/Downloads/align-justify.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon2);
        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(40, 80, 281, 61));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Downloads/pie-chart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Downloads/file-text.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_6);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 160, 821, 271));
        label_27 = new QLabel(widget_4);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 10, 151, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label_27->setFont(font2);
        label_27->setStyleSheet(QString::fromUtf8("color:black;"));
        tableView = new QTableView(widget_4);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 50, 801, 211));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        widget_7 = new QWidget(widget);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(10, 100, 281, 451));
        widget_7->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:30px;\n"
"background-color:none;"));
        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(10, 20, 111, 391));
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

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(130, 20, 151, 391));
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
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_nom = new QLineEdit(frame_4);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(10, 9, 113, 24));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"color: rgb(0, 0, 0);"));
        lineEdit_prenom = new QLineEdit(frame_4);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(10, 53, 113, 24));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_email = new QLineEdit(frame_4);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(10, 92, 113, 24));
        lineEdit_email->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_telephone = new QLineEdit(frame_4);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(10, 133, 113, 24));
        lineEdit_telephone->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_experience = new QLineEdit(frame_4);
        lineEdit_experience->setObjectName("lineEdit_experience");
        lineEdit_experience->setGeometry(QRect(10, 216, 113, 24));
        lineEdit_experience->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_login = new QLineEdit(frame_4);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(10, 300, 113, 24));
        lineEdit_login->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_mdp = new QLineEdit(frame_4);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(10, 340, 113, 24));
        lineEdit_mdp->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        specialite = new QComboBox(frame_4);
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->addItem(QString());
        specialite->setObjectName("specialite");
        specialite->setGeometry(QRect(10, 170, 111, 28));
        specialite->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        dispo = new QComboBox(frame_4);
        dispo->addItem(QString());
        dispo->addItem(QString());
        dispo->setObjectName("dispo");
        dispo->setGeometry(QRect(10, 260, 111, 28));
        dispo->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        pushButton_ajouter = new QPushButton(widget_7);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(160, 420, 83, 29));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        pushButton_ajouter->setFont(font3);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(90, 86, 111, 41));
        horizontalLayout_2 = new QHBoxLayout(widget_10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_34 = new QLabel(widget_10);
        label_34->setObjectName("label_34");
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_2->addWidget(label_34);

        Employe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Employe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1187, 25));
        menu1 = new QMenu(menubar);
        menu1->setObjectName("menu1");
        menu2 = new QMenu(menubar);
        menu2->setObjectName("menu2");
        Employe->setMenuBar(menubar);
        statusbar = new QStatusBar(Employe);
        statusbar->setObjectName("statusbar");
        Employe->setStatusBar(statusbar);

        menubar->addAction(menu1->menuAction());
        menubar->addAction(menu2->menuAction());

        retranslateUi(Employe);

        QMetaObject::connectSlotsByName(Employe);
    } // setupUi

    void retranslateUi(QMainWindow *Employe)
    {
        Employe->setWindowTitle(QCoreApplication::translate("Employe", "Employe", nullptr));
        label->setText(QCoreApplication::translate("Employe", "Gestion D'employees", nullptr));
        pushButton->setText(QCoreApplication::translate("Employe", "Log Out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Employe", "Home", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Employe", "  Rechercher...", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Employe", "filter", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Employe", "Statestiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Employe", "Pdf", nullptr));
        label_27->setText(QCoreApplication::translate("Employe", "Employees", nullptr));
        label_28->setText(QCoreApplication::translate("Employe", "Nom :", nullptr));
        label_29->setText(QCoreApplication::translate("Employe", "Prenom :", nullptr));
        label_30->setText(QCoreApplication::translate("Employe", "Email :", nullptr));
        label_31->setText(QCoreApplication::translate("Employe", "Telephone :", nullptr));
        label_32->setText(QCoreApplication::translate("Employe", "specialite :", nullptr));
        label_33->setText(QCoreApplication::translate("Employe", "Experience :", nullptr));
        label_48->setText(QCoreApplication::translate("Employe", "Disponibilt\303\251:", nullptr));
        label_49->setText(QCoreApplication::translate("Employe", "login:", nullptr));
        label_50->setText(QCoreApplication::translate("Employe", "Mdp:", nullptr));
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("Employe", " taper le nom... ", nullptr));
        lineEdit_prenom->setPlaceholderText(QCoreApplication::translate("Employe", "taper le prenom...", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("Employe", "email.....", nullptr));
        lineEdit_telephone->setPlaceholderText(QCoreApplication::translate("Employe", "+216....", nullptr));
        lineEdit_experience->setPlaceholderText(QCoreApplication::translate("Employe", "experience....", nullptr));
        lineEdit_login->setPlaceholderText(QCoreApplication::translate("Employe", "user name....", nullptr));
        lineEdit_mdp->setPlaceholderText(QCoreApplication::translate("Employe", "taper le mdp...", nullptr));
        specialite->setItemText(0, QCoreApplication::translate("Employe", "Chef de projet ", nullptr));
        specialite->setItemText(1, QCoreApplication::translate("Employe", "Responsable Service Client", nullptr));
        specialite->setItemText(2, QCoreApplication::translate("Employe", "Responsable Ressources Humaines", nullptr));
        specialite->setItemText(3, QCoreApplication::translate("Employe", "Responsable Commercial", nullptr));
        specialite->setItemText(4, QCoreApplication::translate("Employe", "\n"
"Responsable Formation\n"
"", nullptr));

        dispo->setItemText(0, QCoreApplication::translate("Employe", "Disponible", nullptr));
        dispo->setItemText(1, QCoreApplication::translate("Employe", "Occupe", nullptr));

        pushButton_ajouter->setText(QCoreApplication::translate("Employe", "Confirmer", nullptr));
        label_34->setText(QCoreApplication::translate("Employe", "   Ajouter", nullptr));
        menu1->setTitle(QCoreApplication::translate("Employe", "1", nullptr));
        menu2->setTitle(QCoreApplication::translate("Employe", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Employe: public Ui_Employe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_H
