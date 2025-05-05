/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_12;
    QLabel *label_3;
    QFrame *frame_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *btnRdvJour;
    QGroupBox *groupBox;
    QWidget *widget_14;
    QWidget *widget_15;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QWidget *widget_16;
    QLineEdit *lineEdit_4;
    QFrame *frame_7;
    QLineEdit *clientRDV;
    QLineEdit *objectifRDV;
    QDateEdit *dateRDV;
    QTimeEdit *heureRDV;
    QComboBox *modeRDV;
    QWidget *widget_21;
    QPushButton *suppRDV;
    QPushButton *updateRDV;
    QPushButton *addRDV;
    QWidget *widget_18;
    QWidget *widget_19;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_6;
    QLabel *label_7;
    QLineEdit *rechercherRDV;
    QWidget *widget_20;
    QPushButton *calenderierRDV;
    QPushButton *statbuttonRDV;
    QPushButton *pdfRDV;
    QWidget *widget_23;
    QLabel *label_35;
    QTableView *tab_affichage;
    QPushButton *modeRDV_2;
    QPushButton *dateRDV_2;
    QCalendarWidget *calander_rdv;
    QLabel *label_36;
    QLabel *label_4;
    QPushButton *pushButton_10;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1482, 674);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QTableView#tab_affichage {\n"
"    background-color: transparent;\n"
"    /*border: 2px solid #137C8B;\n"
"    border-radius: 10px;*/\n"
"    gridline-color: #709CA7;\n"
"    font: bold 13px \"Segoe UI\";\n"
"    selection-background-color: #B8CBD0;\n"
"    selection-color: white;\n"
"    color: black;\n"
"}\n"
"\n"
"/* En-t\303\252te du tableau */\n"
"QHeaderView::section {\n"
"    background-color: #344D59;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid black;\n"
"    font: bold 13px \"Segoe UI\";\n"
"}\n"
"\n"
"/* Style des lignes impaires */\n"
"QTableView#tab_affichage::item:alternate {\n"
"    background-color: #B8CBD0;\n"
"}\n"
"\n"
"/* Scrollbar verticale */\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #137C8B;\n"
"    background: #7A90A4;\n"
"    width: 12px;\n"
"    margin: 2px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #709CA7;\n"
"    min-height: 30px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:ver"
                        "tical, \n"
"QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"/* Scrollbar horizontale */\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #137C8B;\n"
"    background: #7A90A4;\n"
"    height: 12px;\n"
"    margin: 2px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #709CA7;\n"
"    min-width: 30px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, \n"
"QScrollBar::sub-line:horizontal {\n"
"    background: none;\n"
"}\n"
""));
        widget_12 = new QWidget(centralwidget);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(0, 0, 1571, 71));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        widget_12->setFont(font);
        widget_12->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        label_3 = new QLabel(widget_12);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(430, 20, 271, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic")});
        font1.setPointSize(16);
        font1.setBold(true);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        frame_3 = new QFrame(widget_12);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(1140, 0, 160, 71));
        frame_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Downloads/uso.jfif);"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_3 = new QPushButton(widget_12);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1380, 0, 91, 71));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("color:black;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/log-out (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon);
        pushButton_4 = new QPushButton(widget_12);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 0, 101, 61));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Downloads/home.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon1);
        btnRdvJour = new QPushButton(widget_12);
        btnRdvJour->setObjectName("btnRdvJour");
        btnRdvJour->setGeometry(QRect(110, 0, 71, 61));
        btnRdvJour->setFont(font2);
        btnRdvJour->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Downloads/bell.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRdvJour->setIcon(icon2);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(140, 70, 1441, 661));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Perpetua")});
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(true);
        groupBox->setFont(font3);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_14 = new QWidget(groupBox);
        widget_14->setObjectName("widget_14");
        widget_14->setGeometry(QRect(10, 70, 261, 481));
        widget_14->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:30px;\n"
"background-color:none;"));
        widget_15 = new QWidget(widget_14);
        widget_15->setObjectName("widget_15");
        widget_15->setGeometry(QRect(10, 40, 81, 341));
        widget_15->setStyleSheet(QString::fromUtf8("border:none;"));
        verticalLayout_2 = new QVBoxLayout(widget_15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_42 = new QLabel(widget_15);
        label_42->setObjectName("label_42");
        label_42->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_42);

        label_43 = new QLabel(widget_15);
        label_43->setObjectName("label_43");
        label_43->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_43);

        label_44 = new QLabel(widget_15);
        label_44->setObjectName("label_44");
        label_44->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_44);

        label_45 = new QLabel(widget_15);
        label_45->setObjectName("label_45");
        label_45->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_45);

        label_46 = new QLabel(widget_15);
        label_46->setObjectName("label_46");
        label_46->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_46);

        widget_16 = new QWidget(widget_14);
        widget_16->setObjectName("widget_16");
        widget_16->setGeometry(QRect(99, 40, 151, 341));
        widget_16->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        lineEdit_4 = new QLineEdit(widget_16);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(9, 45, 106, 18));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border:1px;"));
        frame_7 = new QFrame(widget_16);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(9, 10, 121, 321));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        clientRDV = new QLineEdit(frame_7);
        clientRDV->setObjectName("clientRDV");
        clientRDV->setGeometry(QRect(10, 20, 101, 24));
        clientRDV->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        objectifRDV = new QLineEdit(frame_7);
        objectifRDV->setObjectName("objectifRDV");
        objectifRDV->setGeometry(QRect(10, 215, 101, 24));
        objectifRDV->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        dateRDV = new QDateEdit(frame_7);
        dateRDV->setObjectName("dateRDV");
        dateRDV->setGeometry(QRect(10, 82, 101, 25));
        dateRDV->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        heureRDV = new QTimeEdit(frame_7);
        heureRDV->setObjectName("heureRDV");
        heureRDV->setGeometry(QRect(10, 150, 101, 25));
        heureRDV->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        modeRDV = new QComboBox(frame_7);
        modeRDV->addItem(QString());
        modeRDV->addItem(QString());
        modeRDV->setObjectName("modeRDV");
        modeRDV->setGeometry(QRect(10, 279, 101, 24));
        modeRDV->setStyleSheet(QString::fromUtf8("background-color:rgba(225, 225,225,225);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;"));
        widget_21 = new QWidget(widget_14);
        widget_21->setObjectName("widget_21");
        widget_21->setGeometry(QRect(20, 390, 231, 71));
        widget_21->setStyleSheet(QString::fromUtf8("border:none;"));
        suppRDV = new QPushButton(widget_21);
        suppRDV->setObjectName("suppRDV");
        suppRDV->setGeometry(QRect(150, 10, 81, 51));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        suppRDV->setFont(font4);
        suppRDV->setStyleSheet(QString::fromUtf8("QPushButton#suppRDV {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#suppRDV:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#suppRDV:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Downloads/trash-2.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        suppRDV->setIcon(icon3);
        updateRDV = new QPushButton(widget_21);
        updateRDV->setObjectName("updateRDV");
        updateRDV->setGeometry(QRect(70, 10, 71, 51));
        updateRDV->setFont(font4);
        updateRDV->setStyleSheet(QString::fromUtf8("QPushButton#updateRDV {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#updateRDV:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#updateRDV:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Downloads/settings.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        updateRDV->setIcon(icon4);
        addRDV = new QPushButton(widget_21);
        addRDV->setObjectName("addRDV");
        addRDV->setGeometry(QRect(0, 10, 61, 51));
        addRDV->setFont(font4);
        addRDV->setStyleSheet(QString::fromUtf8("QPushButton#addRDV {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#addRDV:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#addRDV:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Downloads/check-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addRDV->setIcon(icon5);
        widget_18 = new QWidget(groupBox);
        widget_18->setObjectName("widget_18");
        widget_18->setGeometry(QRect(310, 80, 1051, 491));
        widget_19 = new QWidget(widget_18);
        widget_19->setObjectName("widget_19");
        widget_19->setGeometry(QRect(40, 10, 301, 61));
        horizontalLayout_3 = new QHBoxLayout(widget_19);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        frame_6 = new QFrame(widget_19);
        frame_6->setObjectName("frame_6");
        frame_6->setStyleSheet(QString::fromUtf8("border :2px solid black;\n"
"border-radius:20px;"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(11, 11, 28, 22));
        label_7->setStyleSheet(QString::fromUtf8("border:none;"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/search (1).svg")));
        rechercherRDV = new QLineEdit(frame_6);
        rechercherRDV->setObjectName("rechercherRDV");
        rechercherRDV->setGeometry(QRect(45, 11, 211, 22));
        rechercherRDV->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;\n"
"\n"
"color: #505050;"));

        horizontalLayout_3->addWidget(frame_6);

        widget_20 = new QWidget(widget_18);
        widget_20->setObjectName("widget_20");
        widget_20->setGeometry(QRect(40, 80, 391, 71));
        calenderierRDV = new QPushButton(widget_20);
        calenderierRDV->setObjectName("calenderierRDV");
        calenderierRDV->setGeometry(QRect(9, 14, 110, 50));
        calenderierRDV->setFont(font2);
        calenderierRDV->setStyleSheet(QString::fromUtf8("QPushButton#calenderierRDV {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#calenderierRDV:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#calenderierRDV:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Downloads/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calenderierRDV->setIcon(icon6);
        statbuttonRDV = new QPushButton(widget_20);
        statbuttonRDV->setObjectName("statbuttonRDV");
        statbuttonRDV->setGeometry(QRect(135, 13, 111, 51));
        statbuttonRDV->setFont(font2);
        statbuttonRDV->setStyleSheet(QString::fromUtf8("QPushButton#statbuttonRDV {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#statbuttonRDV:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#statbuttonRDV:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Downloads/pie-chart (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        statbuttonRDV->setIcon(icon7);
        pdfRDV = new QPushButton(widget_20);
        pdfRDV->setObjectName("pdfRDV");
        pdfRDV->setGeometry(QRect(262, 15, 110, 46));
        pdfRDV->setFont(font2);
        pdfRDV->setStyleSheet(QString::fromUtf8("QPushButton#pdfRDV {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#pdfRDV:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#pdfRDV:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Downloads/file-text (2).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdfRDV->setIcon(icon8);
        widget_23 = new QWidget(widget_18);
        widget_23->setObjectName("widget_23");
        widget_23->setGeometry(QRect(40, 160, 631, 321));
        label_35 = new QLabel(widget_23);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(10, 10, 111, 21));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        label_35->setFont(font5);
        label_35->setStyleSheet(QString::fromUtf8("color:black;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:px;\n"
""));
        tab_affichage = new QTableView(widget_23);
        tab_affichage->setObjectName("tab_affichage");
        tab_affichage->setGeometry(QRect(10, 40, 611, 261));
        modeRDV_2 = new QPushButton(widget_18);
        modeRDV_2->setObjectName("modeRDV_2");
        modeRDV_2->setGeometry(QRect(370, 30, 80, 31));
        QFont font6;
        font6.setBold(true);
        modeRDV_2->setFont(font6);
        modeRDV_2->setStyleSheet(QString::fromUtf8("QPushButton#modeRDV_2{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#modeRDV_2:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#modeRDV_2:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Downloads/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modeRDV_2->setIcon(icon9);
        dateRDV_2 = new QPushButton(widget_18);
        dateRDV_2->setObjectName("dateRDV_2");
        dateRDV_2->setGeometry(QRect(460, 30, 80, 31));
        dateRDV_2->setFont(font6);
        dateRDV_2->setStyleSheet(QString::fromUtf8("QPushButton#dateRDV_2{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"    color: rgba(255, 255, 255, 210);\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton#dateRDV_2:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#dateRDV_2:pressed {\n"
"    padding-left: 3px;\n"
"    padding-top: 3px;\n"
"    background-color: rgba(150, 123, 111, 255);\n"
"}"));
        dateRDV_2->setIcon(icon9);
        calander_rdv = new QCalendarWidget(widget_18);
        calander_rdv->setObjectName("calander_rdv");
        calander_rdv->setGeometry(QRect(690, 210, 311, 261));
        calander_rdv->setStyleSheet(QString::fromUtf8("textcolor:black;"));
        label_36 = new QLabel(widget_18);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(690, 170, 111, 21));
        label_36->setFont(font5);
        label_36->setStyleSheet(QString::fromUtf8("color:black;\n"
"border-bottom:2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:px;\n"
""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 70, 141, 701));
        label_4->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(30, 160, 91, 21));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color:#709CA7;\n"
"border radius:10px"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "rdv", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Gestion Des Rendez-vous", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        btnRdvJour->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Gestion Des Rendez-Vous", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Nom client :", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Date :", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Heure :", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Objectif :", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Mode de rdv :", nullptr));
        clientRDV->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper le nom...", nullptr));
        objectifRDV->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper l'objectif..", nullptr));
        modeRDV->setItemText(0, QCoreApplication::translate("MainWindow", "Presentiel", nullptr));
        modeRDV->setItemText(1, QCoreApplication::translate("MainWindow", "En ligne", nullptr));

        suppRDV->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        updateRDV->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        addRDV->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_7->setText(QString());
        rechercherRDV->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Rechercher...", nullptr));
        calenderierRDV->setText(QCoreApplication::translate("MainWindow", "Calenderier", nullptr));
        statbuttonRDV->setText(QCoreApplication::translate("MainWindow", "Statestiques", nullptr));
        pdfRDV->setText(QCoreApplication::translate("MainWindow", "Pdf", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Rendez-vous", nullptr));
        modeRDV_2->setText(QCoreApplication::translate("MainWindow", "mode", nullptr));
        dateRDV_2->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "calenderier", nullptr));
        label_4->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
