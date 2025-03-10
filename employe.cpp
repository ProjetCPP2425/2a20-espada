#include "employe.h"
#include "ui_employe.h"
#include "em.h"
#include "buttondelegate.h"
#include "editemployeedialog.h"

#include <QMessageBox>
#include <QSqlError>  // Include to check for SQL errors
#include <QDebug>

Employe::Employe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Employe)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
    // Hide the IDEMPLOYE column (column 0)
    ui->tableView->setColumnHidden(0, true);

    // Set the custom delegate for the buttons
    ButtonDelegate *buttonDelegate = new ButtonDelegate(this);
    ui->tableView->setItemDelegateForColumn(10, buttonDelegate); // Column 10: Supprimer
    ui->tableView->setItemDelegateForColumn(11, buttonDelegate); // Column 11: Modifier

    // Connect button signals to slots
    connect(buttonDelegate, &ButtonDelegate::deleteButtonClicked, this, &Employe::onDeleteButtonClicked);
    connect(buttonDelegate, &ButtonDelegate::editButtonClicked, this, &Employe::onEditButtonClicked);
    ui->tableView->resizeColumnsToContents();
}

Employe::~Employe()
{
    delete ui;
}

// Validation function for name (only alphabets)
bool Employe::isValidName(const QString& name) const {
    QRegularExpression regex("^[A-Za-z]+$");
    return regex.match(name).hasMatch();
}

// Validation function for email (must follow a valid email format)
bool Employe::isValidEmail(const QString& email) const {
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex.match(email).hasMatch();
}

// Validation function for phone (must be exactly 8 digits)
bool Employe::isValidPhone(int phone) const {
    QString phoneStr = QString::number(phone);
    QRegularExpression regex("^\\d{8}$");
    return regex.match(phoneStr).hasMatch();
}

// Validation function for experience (must be between 0 and 50)
bool Employe::isValidExperience(int experience) const {
    return experience >= 0 && experience <= 50;
}

// Validation function for password (must contain at least 1 uppercase, 3 digits, 1 special character, and be at least 8 characters long)
bool Employe::isValidPassword(const QString& password) const {
    QRegularExpression regex("^(?=.*[A-Z])(?=.*\\d{3,})(?=.*[!@#$%^&*])(?=.*[a-z]).{8,}$");
    return regex.match(password).hasMatch();
}

void Employe::on_pushButton_ajouter_clicked()
{
    QString NOM = ui->lineEdit_nom->text();
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

    // Check if all fields are filled
    if (NOM.isEmpty() || PRENOM.isEmpty() || EMAIL.isEmpty() || SPECIALITE.isEmpty() ||
        !ok1 || !ok2 || DISPONIBILITE.isEmpty() || LOGIN.isEmpty() || MDP.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Validate name and surname
    if (!isValidName(NOM) || !isValidName(PRENOM)) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }

    // Validate email
    if (!isValidEmail(EMAIL)) {
        QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
        return;
    }

    // Validate phone
    if (!isValidPhone(TELEPHONE)) {
        QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // Validate experience
    if (!isValidExperience(EXPERIENCE)) {
        QMessageBox::warning(this, "Erreur", "L'expérience ne doit pas dépasser 50.");
        return;
    }

    // Validate password
    if (!isValidPassword(MDP)) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une majuscule, trois chiffres, un caractère spécial, et avoir une longueur minimale de 8 caractères.");
        return;
    }

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

void Employe::onDeleteButtonClicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the IDEMPLOYE value from the hidden column (column 0)
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    // Call the supprimer method
    bool success = Etmp.supprimer(id);

    if (success) {
        // Refresh the table view
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}

void Employe::onEditButtonClicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the employee data from the model
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    QString nom = ui->tableView->model()->index(row, 1).data().toString();
    QString prenom = ui->tableView->model()->index(row, 2).data().toString();
    QString email = ui->tableView->model()->index(row, 3).data().toString();
    int telephone = ui->tableView->model()->index(row, 4).data().toInt();
    QString specialite = ui->tableView->model()->index(row, 5).data().toString();
    int experience = ui->tableView->model()->index(row, 6).data().toInt();
    QString disponibilite = ui->tableView->model()->index(row, 7).data().toString();
    QString login = ui->tableView->model()->index(row, 8).data().toString();
    QString mdp = ui->tableView->model()->index(row, 9).data().toString();

    // Open the edit dialog
    EditEmployeeDialog dialog(this);
    dialog.setID(id); // Set the ID internally
    dialog.setEmployeeData(nom, prenom, email, telephone, specialite, experience, disponibilite, login, mdp);

    if (dialog.exec() == QDialog::Accepted) {
        // Retrieve the updated data from the dialog
        QString newNom = dialog.getNom();
        QString newPrenom = dialog.getPrenom();
        QString newEmail = dialog.getEmail();
        int newTelephone = dialog.getTelephone();
        QString newSpecialite = dialog.getSpecialite();
        int newExperience = dialog.getExperience();
        QString newDisponibilite = dialog.getDisponibilite();
        QString newLogin = dialog.getLogin();
        QString newMdp = dialog.getMdp();

        // Validate the updated fields
        if (newNom.isEmpty() || newPrenom.isEmpty() || newEmail.isEmpty() || newSpecialite.isEmpty() ||
            newDisponibilite.isEmpty() || newLogin.isEmpty() || newMdp.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
            return;
        }

        if (!isValidName(newNom) || !isValidName(newPrenom)) {
            QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
            return;
        }

        if (!isValidEmail(newEmail)) {
            QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
            return;
        }

        if (!isValidPhone(newTelephone)) {
            QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir exactement 8 chiffres.");
            return;
        }

        if (!isValidExperience(newExperience)) {
            QMessageBox::warning(this, "Erreur", "L'expérience ne doit pas dépasser 50.");
            return;
        }

        if (!isValidPassword(newMdp)) {
            QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une majuscule, trois chiffres, un caractère spécial, et avoir une longueur minimale de 8 caractères.");
            return;
        }

        // If all validations pass, proceed to update the employee
        bool success = Etmp.modifier(dialog.getID(), newNom, newPrenom, newEmail, newTelephone, newSpecialite, newExperience, newDisponibilite, newLogin, newMdp);

        if (success) {
            // Refresh the table view
            ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(this, "Succès", "Employé modifié avec succès.");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification.");
        }
    }
}
