/********************************************************************************
** Form generated from reading UI file 'editformationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFORMATIONDIALOG_H
#define UI_EDITFORMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditFormationDialog
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_34;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QWidget *widget_13;
    QFrame *frame_5;
    QLineEdit *lineEdit_titre;
    QLineEdit *lineEdit_description;
    QDateEdit *dateEdit_debut;
    QDateEdit *dateEdit_fin;
    QLineEdit *lineEdit_duree;
    QLineEdit *lineEdit_prix;

    void setupUi(QDialog *EditFormationDialog)
    {
        if (EditFormationDialog->objectName().isEmpty())
            EditFormationDialog->setObjectName("EditFormationDialog");
        EditFormationDialog->resize(941, 483);
        widget = new QWidget(EditFormationDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 0, 771, 471));
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
        widget_12 = new QWidget(widget_4);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(20, 50, 131, 321));
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
        widget_13 = new QWidget(widget_3);
        widget_13->setObjectName("widget_13");
        widget_13->setGeometry(QRect(200, 50, 151, 341));
        widget_13->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
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
        lineEdit_duree = new QLineEdit(frame_5);
        lineEdit_duree->setObjectName("lineEdit_duree");
        lineEdit_duree->setGeometry(QRect(10, 210, 113, 26));
        lineEdit_prix = new QLineEdit(frame_5);
        lineEdit_prix->setObjectName("lineEdit_prix");
        lineEdit_prix->setGeometry(QRect(0, 270, 113, 26));

        retranslateUi(EditFormationDialog);

        QMetaObject::connectSlotsByName(EditFormationDialog);
    } // setupUi

    void retranslateUi(QDialog *EditFormationDialog)
    {
        EditFormationDialog->setWindowTitle(QCoreApplication::translate("EditFormationDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditFormationDialog", "Modifier Une Formation :", nullptr));
        label_34->setText(QCoreApplication::translate("EditFormationDialog", "titre:", nullptr));
        label_37->setText(QCoreApplication::translate("EditFormationDialog", "description:", nullptr));
        label_38->setText(QCoreApplication::translate("EditFormationDialog", "Date d\303\251but :", nullptr));
        label_39->setText(QCoreApplication::translate("EditFormationDialog", "date fin:", nullptr));
        label_40->setText(QCoreApplication::translate("EditFormationDialog", "dur\303\251e", nullptr));
        label_41->setText(QCoreApplication::translate("EditFormationDialog", "prix", nullptr));
        saveButton->setText(QCoreApplication::translate("EditFormationDialog", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditFormationDialog", "Cancel", nullptr));
        lineEdit_titre->setPlaceholderText(QCoreApplication::translate("EditFormationDialog", " taper le titre... ", nullptr));
        lineEdit_description->setPlaceholderText(QCoreApplication::translate("EditFormationDialog", "taper la description...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditFormationDialog: public Ui_EditFormationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFORMATIONDIALOG_H
