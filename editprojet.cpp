#include "editprojet.h"
#include "ui_editProjet.h"

Editprojet::Editprojet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editprojet)
{
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->saveButton, &QPushButton::clicked, this, &Editprojet::on_saveButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &Editprojet::on_cancelButton_clicked);
}

Editprojet::~Editprojet()
{
    delete ui;
}

// Set employee data in the dialog
void Editprojet::setProjectData(QString nom_projet, QString description, QString date_debut, QString date_fin, QString statue)
{
    ui->lineEdit_nom->setText(nom_projet);
    ui->lineEdit_Desciption->setText(description);
}

// Get updated employee data from the dialog
QString Editprojet::getNom() const { return ui->lineEdit_nom->text(); }
QString Editprojet::getDescription() const { return ui->lineEdit_Describtion->text(); }

// Set and get the employee ID
void Editprojet::setID(int id) { projetID = id; }
int Editprojet::getID() const { return projetID; }

// Slot for the "Save" button
void Editprojet::on_saveButton_clicked()
{
    accept(); // Close the dialog and return QDialog::Accepted
}

// Slot for the "Cancel" button
void Editprojet::on_cancelButton_clicked()
{
    reject(); // Close the dialog and return QDialog::Rejected
}
