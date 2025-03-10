#include "editemployeedialog.h"
#include "ui_editemployeedialog.h"

EditEmployeeDialog::EditEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEmployeeDialog)
{
    ui->setupUi(this);

    // Populate the combo boxes with options
    ui->comboBox_specialite->addItems({"Chef de projet", "Responsable Service Client", "Responsable Ressources Humaines", "Responsable Commercial", "Responsable Formation"});
    ui->comboBox_disponibilite->addItems({"Disponible", "Occupe"});

    // Connect buttons to slots
    connect(ui->saveButton, &QPushButton::clicked, this, &EditEmployeeDialog::on_saveButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &EditEmployeeDialog::on_cancelButton_clicked);
}

EditEmployeeDialog::~EditEmployeeDialog()
{
    delete ui;
}

// Set employee data in the dialog
void EditEmployeeDialog::setEmployeeData(QString nom, QString prenom, QString email, int telephone, QString specialite, int exp, QString dispo, QString log, QString mdp)
{
    ui->lineEdit_nom->setText(nom);
    ui->lineEdit_prenom->setText(prenom);
    ui->lineEdit_email->setText(email);
    ui->lineEdit_telephone->setText(QString::number(telephone));
    ui->comboBox_specialite->setCurrentText(specialite);
    ui->lineEdit_experience->setText(QString::number(exp));
    ui->comboBox_disponibilite->setCurrentText(dispo);
    ui->lineEdit_login->setText(log);
    ui->lineEdit_mdp->setText(mdp);
}

// Get updated employee data from the dialog
QString EditEmployeeDialog::getNom() const { return ui->lineEdit_nom->text(); }
QString EditEmployeeDialog::getPrenom() const { return ui->lineEdit_prenom->text(); }
QString EditEmployeeDialog::getEmail() const { return ui->lineEdit_email->text(); }
int EditEmployeeDialog::getTelephone() const { return ui->lineEdit_telephone->text().toInt(); }
QString EditEmployeeDialog::getSpecialite() const { return ui->comboBox_specialite->currentText(); }
int EditEmployeeDialog::getExperience() const { return ui->lineEdit_experience->text().toInt(); }
QString EditEmployeeDialog::getDisponibilite() const { return ui->comboBox_disponibilite->currentText(); }
QString EditEmployeeDialog::getLogin() const { return ui->lineEdit_login->text(); }
QString EditEmployeeDialog::getMdp() const { return ui->lineEdit_mdp->text(); }

// Set and get the employee ID
void EditEmployeeDialog::setID(int id) { employeeID = id; }
int EditEmployeeDialog::getID() const { return employeeID; }

// Slot for the "Save" button
void EditEmployeeDialog::on_saveButton_clicked()
{
    accept(); // Close the dialog and return QDialog::Accepted
}

// Slot for the "Cancel" button
void EditEmployeeDialog::on_cancelButton_clicked()
{
    reject(); // Close the dialog and return QDialog::Rejected
}
