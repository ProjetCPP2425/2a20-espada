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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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

class Ui_MainWindow
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
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *widget_4;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QPushButton *modifier;
    QLabel *label_35;
    QPushButton *supprimerr;
    QLabel *label_27;
    QTableView *table;
    QWidget *confirmer_modification;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QWidget *widget_9;
    QLineEdit *lineEdit_3;
    QFrame *frame_4;
    QLineEdit *nom;
    QLineEdit *description;
    QLineEdit *type;
    QLineEdit *localisation;
    QLineEdit *quantite;
    QLineEdit *etat;
    QPushButton *confirmermodification;
    QPushButton *confirmer;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_34;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1087, 682);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 10, 961, 601));
        widget->setStyleSheet(QString::fromUtf8("background-color:#ECF8F6;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 10, 931, 71));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 20, 331, 20));
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
        widget_6->setGeometry(QRect(360, 90, 581, 391));
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
        icon2.addFile(QString::fromUtf8("../../../Downloads/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon2);
        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(40, 80, 331, 61));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_3 = new QPushButton(widget_5);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
"color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Downloads/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Downloads/pie-chart (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Downloads/file-text (2).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon5);

        horizontalLayout->addWidget(pushButton_6);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(-20, 160, 601, 231));
        frame_3 = new QFrame(widget_4);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(419, 41, 191, 181));
        frame_3->setStyleSheet(QString::fromUtf8("color:black;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName("gridLayout");
        modifier = new QPushButton(frame_3);
        modifier->setObjectName("modifier");
        modifier->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));

        gridLayout->addWidget(modifier, 1, 0, 1, 1);

        label_35 = new QLabel(frame_3);
        label_35->setObjectName("label_35");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        label_35->setFont(font2);

        gridLayout->addWidget(label_35, 0, 0, 1, 2);

        supprimerr = new QPushButton(frame_3);
        supprimerr->setObjectName("supprimerr");
        supprimerr->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));

        gridLayout->addWidget(supprimerr, 1, 1, 1, 1);

        label_27 = new QLabel(widget_4);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(50, 10, 201, 21));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label_27->setFont(font3);
        label_27->setStyleSheet(QString::fromUtf8("color:black;"));
        table = new QTableView(widget_4);
        table->setObjectName("table");
        table->setGeometry(QRect(50, 70, 351, 151));
        confirmer_modification = new QWidget(widget);
        confirmer_modification->setObjectName("confirmer_modification");
        confirmer_modification->setGeometry(QRect(40, 100, 291, 471));
        confirmer_modification->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:30px;\n"
"background-color:none;"));
        widget_8 = new QWidget(confirmer_modification);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(10, 40, 111, 291));
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

        widget_9 = new QWidget(confirmer_modification);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(130, 40, 151, 381));
        widget_9->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        lineEdit_3 = new QLineEdit(widget_9);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(9, 45, 106, 18));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border:1px;"));
        frame_4 = new QFrame(widget_9);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(9, 10, 131, 271));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        nom = new QLineEdit(frame_4);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(10, 9, 113, 24));
        nom->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        description = new QLineEdit(frame_4);
        description->setObjectName("description");
        description->setGeometry(QRect(10, 53, 113, 24));
        description->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        type = new QLineEdit(frame_4);
        type->setObjectName("type");
        type->setGeometry(QRect(10, 102, 113, 24));
        type->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        localisation = new QLineEdit(frame_4);
        localisation->setObjectName("localisation");
        localisation->setGeometry(QRect(10, 149, 113, 24));
        localisation->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        quantite = new QLineEdit(frame_4);
        quantite->setObjectName("quantite");
        quantite->setGeometry(QRect(10, 195, 113, 24));
        quantite->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        etat = new QLineEdit(frame_4);
        etat->setObjectName("etat");
        etat->setGeometry(QRect(10, 240, 113, 24));
        etat->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        confirmermodification = new QPushButton(widget_9);
        confirmermodification->setObjectName("confirmermodification");
        confirmermodification->setGeometry(QRect(10, 340, 131, 31));
        confirmermodification->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        confirmer = new QPushButton(confirmer_modification);
        confirmer->setObjectName("confirmer");
        confirmer->setGeometry(QRect(20, 380, 80, 29));
        confirmer->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:#B8CBD0"));
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(115, 84, 131, 41));
        horizontalLayout_2 = new QHBoxLayout(widget_10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_34 = new QLabel(widget_10);
        label_34->setObjectName("label_34");
        label_34->setFont(font3);
        label_34->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_2->addWidget(label_34);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1087, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gestion Des Ressources", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Rechercher...", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "filter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "QR CODE", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Statestiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Pdf", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "  Autres Options", nullptr));
        supprimerr->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Ressources", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Description  :", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Qantit\303\251 :", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Etat :", nullptr));
        nom->setPlaceholderText(QCoreApplication::translate("MainWindow", " taper le nom... ", nullptr));
        description->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper la description...", nullptr));
        type->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper le type...", nullptr));
        localisation->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper la localisation", nullptr));
        quantite->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper la quantit\303\251 ...", nullptr));
        etat->setPlaceholderText(QCoreApplication::translate("MainWindow", "taper l'etat ...", nullptr));
        confirmermodification->setText(QCoreApplication::translate("MainWindow", "confirmer modification", nullptr));
        confirmer->setText(QCoreApplication::translate("MainWindow", "confirmer", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "     Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
