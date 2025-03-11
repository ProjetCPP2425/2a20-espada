#include "client.h"
#include "ui_client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>


client::client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    ui->tableView->setModel(cli.afficher());
}

client::~client()
{
    delete ui;
}



void client::on_pushButton_ajouter_clicked()
{
    int id = ui->id_client->text().toInt();
    QString prenom = ui->prenom_client->text();
    QString nom = ui->nom_client->text();
    QString email = ui->email_client->text();
    QString tel = ui->tel_client->text();
    QString type = ui->type_client->text();
    QString adresse = ui->adresse_client->text();
    QString date = ui->date_inscri_client->text();
    QString specialite = ui->specialite_client->text();

    Clients C(id, prenom, nom, email, tel, type, adresse, date, specialite);
    bool test = C.ajouter();

    if (test)
    {
        ui->tableView->setModel(C.afficher());  // Utilisation de l'objet créé au lieu de 'C'
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Cliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Cliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
    }
}


void client::on_pushButton_supprimer_clicked()
{
    int id=ui->id_client->text().toInt();
    bool test=cli.supprimer(id);

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK")
                                 ,QObject::tr("supprmession effectue\n"
                                               "click cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                              QObject::tr("suppression non effectue.\n"
                                          "click cancel to exit ."),QMessageBox::Cancel);
    }
}
#include <QDebug>

void client::on_tableView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;  // Vérifier que l'index est valide

    // Récupérer la ligne sélectionnée
    int row = index.row();
    QAbstractItemModel *model = ui->tableView->model();  // Référence au modèle

    // Extraire les valeurs des colonnes
    QString id_client = model->data(model->index(row, 0)).toString().trimmed();
    QString prenom_client = model->data(model->index(row, 1)).toString().trimmed();
    QString nom_client = model->data(model->index(row, 2)).toString().trimmed();
    QString email_client = model->data(model->index(row, 3)).toString().trimmed();
    QString tel_client = model->data(model->index(row, 4)).toString().trimmed();
    QString type_client = model->data(model->index(row, 5)).toString().trimmed();
    QString adresse_client = model->data(model->index(row, 6)).toString().trimmed();
    QString date_inscri_client = model->data(model->index(row, 7)).toString().trimmed();
    QString specialite_client = model->data(model->index(row, 8)).toString().trimmed();


    // Affichage pour débogage
    qDebug() << "Date récupérée de la base : " << date_inscri_client;

    // Vérifier si la date est valide
    QString datePart = date_inscri_client.split("T")[0];  // Extraire la partie avant 'T'
    QDate date = QDate::fromString(datePart, "yyyy-MM-dd");  // Adapter au format réel de la base
    if (!date.isValid()) {
        qDebug() << "⚠ Erreur : La conversion de la date a échoué !";
    } else {
        ui->date_inscri_client->setDate(date);  // Si conversion réussie, mettre à jour le QDateEdit
    }

    // Vérification et affichage des valeurs dans les champs du formulaire
    ui->id_client->setText(id_client);
    ui->prenom_client->setText(prenom_client);
    ui->nom_client->setText(nom_client);
    ui->email_client->setText(email_client);
    ui->tel_client->setText(tel_client);
    ui->type_client->setText(type_client);
    ui->adresse_client->setText(adresse_client);
    ui->specialite_client->setText(specialite_client);  // Assurez-vous que ce champ existe

}


void client::on_pushButton_modifier_clicked()
{
    // Récupérer les valeurs depuis le formulaire
    bool ok;
    int id = ui->id_client->text().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Erreur", "ID invalide !");
        return;
    }


    QString prenom = ui->prenom_client->text();
    QString nom = ui->nom_client->text();
    QString email = ui->email_client->text();
    QString tel = ui->tel_client->text();
    QString type = ui->type_client->text();
    QString adresse = ui->adresse_client->text();
    QString date = ui->date_inscri_client->text();
    QString specialite = ui->specialite_client->text();

    // Vérifier que les champs nécessaires ne sont pas vides
    if (prenom.isEmpty() || nom.isEmpty() || email.isEmpty() || tel.isEmpty() || type.isEmpty() || adresse.isEmpty() || date.isEmpty() || specialite.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // Appeler la fonction de modification
    Clients cli;
    bool test = cli.modifier(id, prenom, nom, email, tel, type, adresse, date, specialite);

    // Vérifier si la modification a réussi
    if (test) {
        QMessageBox::information(this, "Modification réussie", "L'équipement a été modifié avec succès !");
        ui->tableView->setModel(cli.afficher()); // Rafraîchir l'affichage de la table
    } else {
        QMessageBox::critical(this, "Échec", "La modification a échoué !");
    }
}



