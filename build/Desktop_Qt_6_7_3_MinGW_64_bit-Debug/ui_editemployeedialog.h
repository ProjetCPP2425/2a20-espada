/********************************************************************************
** Form generated from reading UI file 'editemployeedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITEMPLOYEEDIALOG_H
#define UI_EDITEMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditEmployeeDialog
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
    QLabel *label_33;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_telephone;
    QComboBox *comboBox_specialite;
    QLineEdit *lineEdit_experience;
    QComboBox *comboBox_disponibilite;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_mdp;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *EditEmployeeDialog)
    {
        if (EditEmployeeDialog->objectName().isEmpty())
            EditEmployeeDialog->setObjectName("EditEmployeeDialog");
        EditEmployeeDialog->resize(786, 508);
        widget = new QWidget(EditEmployeeDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 771, 471));
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

        lineEdit_nom = new QLineEdit(widget_3);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(200, 30, 151, 28));
        lineEdit_prenom = new QLineEdit(widget_3);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(200, 70, 151, 28));
        lineEdit_email = new QLineEdit(widget_3);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(200, 110, 151, 28));
        lineEdit_telephone = new QLineEdit(widget_3);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(200, 150, 151, 28));
        comboBox_specialite = new QComboBox(widget_3);
        comboBox_specialite->setObjectName("comboBox_specialite");
        comboBox_specialite->setGeometry(QRect(200, 190, 151, 41));
        comboBox_specialite->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_experience = new QLineEdit(widget_3);
        lineEdit_experience->setObjectName("lineEdit_experience");
        lineEdit_experience->setGeometry(QRect(200, 240, 151, 28));
        comboBox_disponibilite = new QComboBox(widget_3);
        comboBox_disponibilite->setObjectName("comboBox_disponibilite");
        comboBox_disponibilite->setGeometry(QRect(200, 280, 151, 31));
        comboBox_disponibilite->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_login = new QLineEdit(widget_3);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(200, 320, 151, 28));
        lineEdit_mdp = new QLineEdit(widget_3);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(200, 360, 151, 28));
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

        retranslateUi(EditEmployeeDialog);

        QMetaObject::connectSlotsByName(EditEmployeeDialog);
    } // setupUi

    void retranslateUi(QDialog *EditEmployeeDialog)
    {
        EditEmployeeDialog->setWindowTitle(QCoreApplication::translate("EditEmployeeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditEmployeeDialog", "Modifier Un Employe :", nullptr));
        label_28->setText(QCoreApplication::translate("EditEmployeeDialog", "Nom :", nullptr));
        label_29->setText(QCoreApplication::translate("EditEmployeeDialog", "Prenom :", nullptr));
        label_30->setText(QCoreApplication::translate("EditEmployeeDialog", "Email :", nullptr));
        label_31->setText(QCoreApplication::translate("EditEmployeeDialog", "Telephone :", nullptr));
        label_32->setText(QCoreApplication::translate("EditEmployeeDialog", "specialite :", nullptr));
        label_33->setText(QCoreApplication::translate("EditEmployeeDialog", "Experience :", nullptr));
        label_48->setText(QCoreApplication::translate("EditEmployeeDialog", "Disponibilt\303\251:", nullptr));
        label_49->setText(QCoreApplication::translate("EditEmployeeDialog", "login:", nullptr));
        label_50->setText(QCoreApplication::translate("EditEmployeeDialog", "Mdp:", nullptr));
        saveButton->setText(QCoreApplication::translate("EditEmployeeDialog", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditEmployeeDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditEmployeeDialog: public Ui_EditEmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITEMPLOYEEDIALOG_H
