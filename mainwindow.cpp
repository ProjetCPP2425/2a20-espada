#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ressource.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->confirmer, &QPushButton::clicked, this, &MainWindow::on_pushButton_confirmer_clicked);
    connect(ui->supprimerr, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimerr_clicked);
    // Connexion pour modifier une ressource
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->confirmermodification, &QPushButton::clicked, this, &MainWindow::on_pushButton_confirmermodification_clicked);
    ui->table->setModel(R.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::isValidInput()
{
    // Vérifier si tous les champs sont remplis
    if (ui->nom->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ NOM ne peut pas être vide.");
        return false;
    }

    if (ui->description->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ DESCRIPTION ne peut pas être vide.");
        return false;
    }

    if (ui->type->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ TYPE ne peut pas être vide.");
        return false;
    }

    if (ui->localisation->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ LOCALISATION ne peut pas être vide.");
        return false;
    }

    if (ui->etat->text().isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Le champ ETAT ne peut pas être vide.");
        return false;
    }

    bool ok;
    int quantite = ui->quantite->text().toInt(&ok); // Vérifier si QUANTITE est un nombre entier
    if (!ok) {
        QMessageBox::warning(this, "Quantité invalide", "Veuillez entrer un nombre valide pour QUANTITE.");
        return false;
    }

    // Si tout est valide
    return true;
}


void MainWindow::on_pushButton_confirmer_clicked()
{
    if (!isValidInput()) {
        return; // Si les données ne sont pas valides, ne rien faire
    }
    //int id=ui->lineEdit_ID->text().toInt();
    QString NOM=ui->nom->text();
    QString DESCRIPTION=ui->description->text();
    QString TYPE=ui->type->text();
    QString LOCALISATION=ui->localisation->text();
    int QUANTITE=ui->quantite->text().toInt();
    QString ETAT=ui->etat->text();
    ressource R(NOM,DESCRIPTION,TYPE,LOCALISATION,QUANTITE,ETAT);

    bool test=R.ajouter();
    ui->nom->clear();
    ui->description->clear();
    ui->type->clear();
    ui->localisation->clear();
    ui->quantite->clear();
    ui->etat->clear();


    if(test)
    {
        ui->table->setModel(R.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("ajout successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        // Afficher un message d'erreur si la connexion échoue
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("AJOUT failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }


}
void MainWindow::on_pushButton_supprimerr_clicked()
{
    // Récupérer la ligne sélectionnée dans la table
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        // Afficher un message si aucune ligne n'est sélectionnée
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner une ressource à supprimer."));
        return;
    }

    // Récupérer l'ID de la ressource à partir de la première colonne (supposons que l'ID est dans la première colonne)
    int id = selectedRows.first().data().toInt();

    // Supprimer la ressource
    bool test = R.supprimer(id);

    if (test) {
        // Mettre à jour la vue de la table après la suppression
        ui->table->setModel(R.afficher());

        // Afficher un message de succès
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression réussie.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
    else {
        // Afficher un message d'erreur si la suppression échoue
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("La suppression a échoué.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked()
{
    // Récupérer la ligne sélectionnée dans la table
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        // Afficher un message si aucune ligne n'est sélectionnée
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner une ressource à modifier."));
        return;
    }

    // Récupérer l'ID de la ressource à partir de la première colonne (supposons que l'ID est dans la première colonne)
    int id = selectedRows.first().data().toInt();

    // Récupérer la ressource à modifier
    ressource R = R.trouver(id);

    // Mettre les informations de la ressource dans les champs de texte
    ui->nom->setText(R.getNOM());
    ui->description->setText(R.getDESCRIPTION());
    ui->type->setText(R.getTYPE());
    ui->localisation->setText(R.getLOCALISATION());
    ui->quantite->setText(QString::number(R.getQUANTITE()));
    ui->etat->setText(R.getETAT());

    // Connexion du bouton "Confirmer" pour la modification
    connect(ui->confirmermodification, &QPushButton::clicked, [this, id]() {
        // Créer un objet ressource pour la modification
        ressource R = R.trouver(id);
        R.setNom(ui->nom->text());
        R.setDescription(ui->description->text());
        R.setType(ui->type->text());
        R.setLocalisation(ui->localisation->text());
        R.setQuantite(ui->quantite->text().toInt());
        R.setEtat(ui->etat->text());


    });
}
void MainWindow::on_pushButton_confirmermodification_clicked()
{
    // Récupérer la ligne sélectionnée dans le tableau
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        // Afficher un message d'erreur si aucune ligne n'est sélectionnée
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ressource à modifier.");
        return;
    }

    // Récupérer l'ID de la ressource à partir de la première colonne (supposons que l'ID est dans la première colonne)
    int id = selectedRows.first().data().toInt();

    // Trouver la ressource à modifier en fonction de l'ID
    ressource R = R.trouver(id);

    // Vérifier si la ressource existe
    if (R.getID() == 0) {
        QMessageBox::warning(this, "Erreur", "La ressource avec l'ID spécifié n'existe pas.");
        return;
    }
    if (!isValidInput()) {
        return; // Si les données ne sont pas valides, ne rien faire
    }

    // Récupérer les nouvelles valeurs des champs de texte
    QString NOM = ui->nom->text();
    QString DESCRIPTION = ui->description->text();
    QString TYPE = ui->type->text();
    QString LOCALISATION = ui->localisation->text();
    int QUANTITE = ui->quantite->text().toInt();
    QString ETAT = ui->etat->text();

    // Mise à jour des attributs de la ressource avec les nouvelles valeurs
    R.setNom(NOM);
    R.setDescription(DESCRIPTION);
    R.setType(TYPE);
    R.setLocalisation(LOCALISATION);
    R.setQuantite(QUANTITE);
    R.setEtat(ETAT);

    // Appeler la méthode modifier de la ressource pour effectuer la mise à jour dans la base de données
    bool test = R.modifier(id);

    if (test) {
        // Réactualiser le modèle de la table pour afficher les données modifiées
        ui->table->setModel(R.afficher());
        QMessageBox::information(this, "Modification réussie", "La ressource a été modifiée avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }

    // Vider les champs de texte après la modification
    ui->nom->clear();
    ui->description->clear();
    ui->type->clear();
    ui->localisation->clear();
    ui->quantite->clear();
    ui->etat->clear();
}
