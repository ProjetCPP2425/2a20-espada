/********************************************************************************
** Form generated from reading UI file 'editProjet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROJET_H
#define UI_EDITPROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_6
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_Des;
    QLineEdit *lineEdit_Deb;
    QLineEdit *lineEdit_Fin;
    QLineEdit *lineEdit_Stat;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *widget_6)
    {
        if (widget_6->objectName().isEmpty())
            widget_6->setObjectName("widget_6");
        widget_6->resize(772, 488);
        widget = new QWidget(widget_6);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 10, 771, 521));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 0, 761, 61));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:#709CA7;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 10, 321, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 60, 761, 411));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:#ECF8F6;\n"
"color: rgb(0, 0, 0);"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(10, 0, 171, 411));
        widget_4->setStyleSheet(QString::fromUtf8(""));
        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(40, 10, 121, 391));
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

        lineEdit_nom = new QLineEdit(widget_3);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(200, 40, 151, 28));
        lineEdit_Des = new QLineEdit(widget_3);
        lineEdit_Des->setObjectName("lineEdit_Des");
        lineEdit_Des->setGeometry(QRect(200, 120, 151, 28));
        lineEdit_Deb = new QLineEdit(widget_3);
        lineEdit_Deb->setObjectName("lineEdit_Deb");
        lineEdit_Deb->setGeometry(QRect(200, 190, 151, 28));
        lineEdit_Fin = new QLineEdit(widget_3);
        lineEdit_Fin->setObjectName("lineEdit_Fin");
        lineEdit_Fin->setGeometry(QRect(200, 270, 151, 28));
        lineEdit_Stat = new QLineEdit(widget_3);
        lineEdit_Stat->setObjectName("lineEdit_Stat");
        lineEdit_Stat->setGeometry(QRect(200, 350, 151, 28));
        saveButton = new QPushButton(widget_3);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(390, 350, 171, 29));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        saveButton->setFont(font1);
        saveButton->setStyleSheet(QString::fromUtf8("background-color:#B8CBD0"));
        cancelButton = new QPushButton(widget_3);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(570, 350, 171, 29));
        cancelButton->setFont(font1);
        cancelButton->setStyleSheet(QString::fromUtf8("background-color:#B8CBD0"));

        retranslateUi(widget_6);

        QMetaObject::connectSlotsByName(widget_6);
    } // setupUi

    void retranslateUi(QDialog *widget_6)
    {
        widget_6->setWindowTitle(QCoreApplication::translate("widget_6", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("widget_6", "Modifier Un Projet :", nullptr));
        label_28->setText(QCoreApplication::translate("widget_6", "Nom Projet:", nullptr));
        label_29->setText(QCoreApplication::translate("widget_6", "Description:", nullptr));
        label_30->setText(QCoreApplication::translate("widget_6", "Date Debut:", nullptr));
        label_31->setText(QCoreApplication::translate("widget_6", "Date Fin:", nullptr));
        label_32->setText(QCoreApplication::translate("widget_6", "Statue:", nullptr));
        saveButton->setText(QCoreApplication::translate("widget_6", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("widget_6", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_6: public Ui_widget_6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROJET_H
