/********************************************************************************
** Form generated from reading UI file 'projet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJET_H
#define UI_PROJET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_projet
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
    QLabel *label_37;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_36;
    QWidget *widget_9;
    QLineEdit *lineEdit_3;
    QFrame *frame_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_14;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_34;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *projet)
    {
        if (projet->objectName().isEmpty())
            projet->setObjectName("projet");
        projet->resize(961, 545);
        centralwidget = new QWidget(projet);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 961, 501));
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
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
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
        widget_6->setGeometry(QRect(360, 90, 591, 391));
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
        icon2.addFile(QString::fromUtf8("../../Downloads/Downloads/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon2);
        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(40, 80, 281, 51));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Downloads/pie-chart (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Downloads/file-text (2).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_6);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(20, 160, 571, 231));
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
        tableView->setGeometry(QRect(10, 40, 541, 181));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        widget_7 = new QWidget(widget);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(30, 100, 291, 381));
        widget_7->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:30px;\n"
"background-color:none;"));
        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(10, 40, 111, 291));
        widget_8->setStyleSheet(QString::fromUtf8("border:none;"));
        verticalLayout = new QVBoxLayout(widget_8);
        verticalLayout->setObjectName("verticalLayout");
        label_28 = new QLabel(widget_8);
        label_28->setObjectName("label_28");
        label_28->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_28);

        label_37 = new QLabel(widget_8);
        label_37->setObjectName("label_37");
        label_37->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_37);

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

        label_36 = new QLabel(widget_8);
        label_36->setObjectName("label_36");
        label_36->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_36);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(129, 30, 151, 301));
        widget_9->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        lineEdit_3 = new QLineEdit(widget_9);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(9, 45, 106, 18));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border:1px;"));
        frame_4 = new QFrame(widget_9);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(9, 10, 131, 291));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_2 = new QLineEdit(frame_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 9, 113, 24));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_4 = new QLineEdit(frame_4);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(10, 46, 113, 24));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_5 = new QLineEdit(frame_4);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(10, 85, 113, 24));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_6 = new QLineEdit(frame_4);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(10, 120, 113, 24));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_7 = new QLineEdit(frame_4);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(10, 154, 113, 24));
        lineEdit_7->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_8 = new QLineEdit(frame_4);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(10, 222, 113, 24));
        lineEdit_8->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_9 = new QLineEdit(frame_4);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(10, 188, 113, 24));
        lineEdit_9->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        lineEdit_10 = new QLineEdit(frame_4);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(10, 256, 113, 24));
        lineEdit_10->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        pushButton_14 = new QPushButton(widget_7);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(150, 340, 101, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(115, 84, 111, 34));
        horizontalLayout_2 = new QHBoxLayout(widget_10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_34 = new QLabel(widget_10);
        label_34->setObjectName("label_34");
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_2->addWidget(label_34);

        projet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(projet);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 961, 21));
        projet->setMenuBar(menubar);
        statusbar = new QStatusBar(projet);
        statusbar->setObjectName("statusbar");
        projet->setStatusBar(statusbar);

        retranslateUi(projet);

        QMetaObject::connectSlotsByName(projet);
    } // setupUi

    void retranslateUi(QMainWindow *projet)
    {
        projet->setWindowTitle(QCoreApplication::translate("projet", "projet", nullptr));
        label->setText(QCoreApplication::translate("projet", "Gestion Des Projets", nullptr));
        pushButton->setText(QCoreApplication::translate("projet", "Log Out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("projet", "Home", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("projet", "  Rechercher...", nullptr));
        pushButton_4->setText(QCoreApplication::translate("projet", "filter", nullptr));
        pushButton_5->setText(QCoreApplication::translate("projet", "Statestiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("projet", "Pdf", nullptr));
        label_27->setText(QCoreApplication::translate("projet", "Projets", nullptr));
        label_28->setText(QCoreApplication::translate("projet", "Nom projet:", nullptr));
        label_37->setText(QCoreApplication::translate("projet", "Nom:", nullptr));
        label_29->setText(QCoreApplication::translate("projet", "Nom client :", nullptr));
        label_30->setText(QCoreApplication::translate("projet", "Date-debut :", nullptr));
        label_31->setText(QCoreApplication::translate("projet", "date-fin:", nullptr));
        label_32->setText(QCoreApplication::translate("projet", "statut:", nullptr));
        label_33->setText(QCoreApplication::translate("projet", "Nom roussouces:", nullptr));
        label_36->setText(QCoreApplication::translate("projet", "Description:", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("projet", " taper le nom... ", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("projet", "taper le nom...", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("projet", "taper le nom...", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("projet", "../../..", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("projet", "../../..", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("projet", "taper les ressources..", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("projet", "taper le statut...", nullptr));
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("projet", "description...", nullptr));
        pushButton_14->setText(QCoreApplication::translate("projet", "Confirmer", nullptr));
        label_34->setText(QCoreApplication::translate("projet", "     Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class projet: public Ui_projet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJET_H
