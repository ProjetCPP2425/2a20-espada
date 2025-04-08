/********************************************************************************
** Form generated from reading UI file 'formationmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATIONMAINWINDOW_H
#define UI_FORMATIONMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormationMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QLabel *label;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_6;
    QWidget *widget_4;
    QFrame *frame_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *widget_10;
    QLabel *label_27;
    QTableView *tableView;
    QWidget *widget_11;
    QPushButton *pushButton_ajouter;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_34;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QWidget *widget_13;
    QLineEdit *lineEdit_6;
    QFrame *frame_5;
    QLineEdit *lineEdit_titre;
    QLineEdit *lineEdit_description;
    QDateEdit *dateEdit_debut;
    QDateEdit *dateEdit_fin;
    QSpinBox *spinBox_duree;
    QDoubleSpinBox *doubleSpinBox_prix;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_42;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormationMainWindow)
    {
        if (FormationMainWindow->objectName().isEmpty())
            FormationMainWindow->setObjectName("FormationMainWindow");
        FormationMainWindow->resize(1274, 686);
        centralwidget = new QWidget(FormationMainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 0, 1101, 631));
        widget->setStyleSheet(QString::fromUtf8("background-color:#ECF8F6;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(30, 20, 1081, 601));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:#ECF8F6;"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 1031, 81));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 20, 361, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        frame = new QFrame(widget_3);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(650, 10, 120, 71));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/Downloads/uso.jfif);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(840, 10, 80, 51));
        pushButton->setStyleSheet(QString::fromUtf8("color:black;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/log-out (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 10, 80, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 11pt \"Segoe UI\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Downloads/home.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(350, 90, 641, 461));
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(40, 20, 391, 51));
        frame_2 = new QFrame(widget_4);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 0, 281, 41));
        frame_2->setStyleSheet(QString::fromUtf8("border :2px solid black;\n"
"border-radius:20px;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
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
        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(300, 10, 80, 24));
        QFont font1;
        font1.setBold(true);
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Downloads/Downloads/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon3.addFile(QString::fromUtf8("../../../Downloads/Downloads/pie-chart (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Downloads/Downloads/file-text (2).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_6);

        widget_10 = new QWidget(widget_6);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(0, 160, 631, 301));
        label_27 = new QLabel(widget_10);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 10, 151, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label_27->setFont(font2);
        label_27->setStyleSheet(QString::fromUtf8("color:black;"));
        tableView = new QTableView(widget_10);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 60, 611, 231));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        widget_11 = new QWidget(widget_2);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(20, 130, 291, 431));
        widget_11->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:30px;\n"
"background-color:none;"));
        pushButton_ajouter = new QPushButton(widget_11);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(140, 400, 131, 24));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        pushButton_ajouter->setFont(font3);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Downloads/Downloads/check-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_ajouter->setIcon(icon5);
        widget_12 = new QWidget(widget_11);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(10, 50, 131, 321));
        widget_12->setStyleSheet(QString::fromUtf8("border:none;"));
        verticalLayout_2 = new QVBoxLayout(widget_12);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_34 = new QLabel(widget_12);
        label_34->setObjectName("label_34");
        label_34->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_34);

        label_37 = new QLabel(widget_12);
        label_37->setObjectName("label_37");
        label_37->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_37);

        label_38 = new QLabel(widget_12);
        label_38->setObjectName("label_38");
        label_38->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_38);

        label_39 = new QLabel(widget_12);
        label_39->setObjectName("label_39");
        label_39->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_39);

        label_40 = new QLabel(widget_12);
        label_40->setObjectName("label_40");
        label_40->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_40);

        label_41 = new QLabel(widget_12);
        label_41->setObjectName("label_41");
        label_41->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_41);

        widget_13 = new QWidget(widget_11);
        widget_13->setObjectName("widget_13");
        widget_13->setGeometry(QRect(130, 50, 151, 341));
        widget_13->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        lineEdit_6 = new QLineEdit(widget_13);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(9, 45, 106, 18));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border:1px;"));
        frame_5 = new QFrame(widget_13);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(10, 10, 131, 311));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_titre = new QLineEdit(frame_5);
        lineEdit_titre->setObjectName("lineEdit_titre");
        lineEdit_titre->setGeometry(QRect(10, 9, 113, 24));
        lineEdit_titre->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_description = new QLineEdit(frame_5);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setGeometry(QRect(10, 60, 113, 24));
        lineEdit_description->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        dateEdit_debut = new QDateEdit(frame_5);
        dateEdit_debut->setObjectName("dateEdit_debut");
        dateEdit_debut->setGeometry(QRect(10, 110, 110, 26));
        dateEdit_fin = new QDateEdit(frame_5);
        dateEdit_fin->setObjectName("dateEdit_fin");
        dateEdit_fin->setGeometry(QRect(10, 160, 110, 26));
        spinBox_duree = new QSpinBox(frame_5);
        spinBox_duree->setObjectName("spinBox_duree");
        spinBox_duree->setGeometry(QRect(40, 220, 42, 26));
        doubleSpinBox_prix = new QDoubleSpinBox(frame_5);
        doubleSpinBox_prix->setObjectName("doubleSpinBox_prix");
        doubleSpinBox_prix->setGeometry(QRect(20, 270, 62, 26));
        widget_14 = new QWidget(widget_2);
        widget_14->setObjectName("widget_14");
        widget_14->setGeometry(QRect(115, 84, 111, 41));
        horizontalLayout_2 = new QHBoxLayout(widget_14);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_42 = new QLabel(widget_14);
        label_42->setObjectName("label_42");
        label_42->setFont(font2);
        label_42->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_2->addWidget(label_42);

        FormationMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormationMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1274, 26));
        FormationMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FormationMainWindow);
        statusbar->setObjectName("statusbar");
        FormationMainWindow->setStatusBar(statusbar);

        retranslateUi(FormationMainWindow);

        QMetaObject::connectSlotsByName(FormationMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FormationMainWindow)
    {
        FormationMainWindow->setWindowTitle(QCoreApplication::translate("FormationMainWindow", "FormationMainWindow", nullptr));
        label->setText(QCoreApplication::translate("FormationMainWindow", "Gestion Des formations", nullptr));
        pushButton->setText(QCoreApplication::translate("FormationMainWindow", "Log Out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormationMainWindow", "Home", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("FormationMainWindow", "  Rechercher...", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FormationMainWindow", "filter", nullptr));
        pushButton_5->setText(QCoreApplication::translate("FormationMainWindow", "Statestiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("FormationMainWindow", "Pdf", nullptr));
        label_27->setText(QCoreApplication::translate("FormationMainWindow", "formation", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("FormationMainWindow", "Confirmer", nullptr));
        label_34->setText(QCoreApplication::translate("FormationMainWindow", "titre:", nullptr));
        label_37->setText(QCoreApplication::translate("FormationMainWindow", "description:", nullptr));
        label_38->setText(QCoreApplication::translate("FormationMainWindow", "Date d\303\251but :", nullptr));
        label_39->setText(QCoreApplication::translate("FormationMainWindow", "date fin:", nullptr));
        label_40->setText(QCoreApplication::translate("FormationMainWindow", "dur\303\251e", nullptr));
        label_41->setText(QCoreApplication::translate("FormationMainWindow", "prix", nullptr));
        lineEdit_titre->setPlaceholderText(QCoreApplication::translate("FormationMainWindow", " taper le titre... ", nullptr));
        lineEdit_description->setPlaceholderText(QCoreApplication::translate("FormationMainWindow", "taper la description...", nullptr));
        label_42->setText(QCoreApplication::translate("FormationMainWindow", "  Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormationMainWindow: public Ui_FormationMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATIONMAINWINDOW_H
