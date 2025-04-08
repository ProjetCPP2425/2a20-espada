#include "editformationdialog.h"
#include "ui_editformationdialog.h"

EditFormationDialog::EditFormationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditFormationDialog)
{
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->saveButton, &QPushButton::clicked, this, &EditFormationDialog::on_saveButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &EditFormationDialog::on_cancelButton_clicked);
}

EditFormationDialog::~EditFormationDialog()
{
    delete ui;
}

void EditFormationDialog::setFormationData(QString titre, QString description, QString date_debut, QString date_fin, int duree, float prix)
{
    ui->lineEdit_titre->setText(titre);
    ui->lineEdit_description->setText(description);
    ui->dateEdit_debut->setDate(QDate::fromString(date_debut, "yyyy-MM-dd"));
    ui->dateEdit_fin->setDate(QDate::fromString(date_fin, "yyyy-MM-dd"));
    ui->lineEdit_duree->setText(QString::number(duree));
    ui->lineEdit_prix->setText(QString::number(prix));
}

QString EditFormationDialog::getTitre() const { return ui->lineEdit_titre->text(); }
QString EditFormationDialog::getDescription() const { return ui->lineEdit_description->text(); }
QString EditFormationDialog::getDateDebut() const { return ui->dateEdit_debut->date().toString("yyyy-MM-dd"); }
QString EditFormationDialog::getDateFin() const { return ui->dateEdit_fin->date().toString("yyyy-MM-dd"); }
int EditFormationDialog::getDuree() const { return ui->lineEdit_duree->text().toInt(); }
float EditFormationDialog::getPrix() const { return ui->lineEdit_prix->text().toFloat(); }

void EditFormationDialog::setID(int id) { formationID = id; }
int EditFormationDialog::getID() const { return formationID; }

void EditFormationDialog::on_saveButton_clicked()
{
    accept();
}

void EditFormationDialog::on_cancelButton_clicked()
{
    reject();
}
