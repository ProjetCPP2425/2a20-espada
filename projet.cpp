#include "projet.h"
#include "projets.h"
#include "ui_projet.h"
#include <QMessageBox>
#include <QSqlError>  // Include to check for SQL errors
#include <QDebug>
#include "buttondelegate.h"

Projet::Projet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::projet)
{
    ui->setupUi(this);
    ui->tableView->setModel(pro.afficher());
    // Hide the IDEMPLOYE column (column 0)
    ui->tableView->setColumnHidden(0, true);

    // Set the custom delegate for the buttons
    ButtonDelegate *buttonDelegate = new ButtonDelegate(this);
    ui->tableView->setItemDelegateForColumn(10, buttonDelegate); // Column 10: Supprimer
    ui->tableView->setItemDelegateForColumn(11, buttonDelegate); // Column 11: Modifier

    // Connect button signals to slots
    connect(buttonDelegate, &ButtonDelegate::deleteButtonClicked, this, &Projet::on_pushButton_supprimer_clicked);
    ui->tableView->resizeColumnsToContents();
}

Projet::~Projet()
{
    delete ui;
}

void Projet::on_pushButton_ajouter_clicked()
{
    QString NOM = ui->setNom_projet->text();
    QString PRENOM = ui->lineEdit_prenom->text();
    QString EMAIL = ui->lineEdit_email->text();
    QString SPECIALITE = ui->specialite->currentText();
    bool ok1, ok2;
    int TELEPHONE = ui->lineEdit_telephone->text().toInt(&ok1);
    int EXPERIENCE = ui->lineEdit_experience->text().toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer des nombres valides pour le téléphone et l'expérience.");
        return;
    }

    QString DISPONIBILITE = ui->dispo->currentText();
    QString LOGIN = ui->lineEdit_login->text();
    QString MDP = ui->lineEdit_mdp->text();

    em E(NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN, MDP);

    bool test = E.ajouter();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_telephone->clear();
    ui->specialite->setCurrentIndex(0);
    ui->lineEdit_experience->clear();
    ui->dispo->setCurrentIndex(0);
    ui->lineEdit_login->clear();
    ui->lineEdit_mdp->clear();
    if (test) {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."), QMessageBox::Cancel);

    }
}


void Projet::on_pushButton_supprimer_clicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the IDEMPLOYE value from the hidden column (column 0)
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    // Call the supprimer method
    bool success = pro.supprimer(id);

    if (success) {
        // Refresh the table view
        ui->tableView->setModel(pro.afficher());
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}



