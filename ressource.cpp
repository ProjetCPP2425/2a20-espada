#include "ressource.h"
#include <QMap>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QBuffer>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>  // Ajout de QPageSize pour définir la taille A4
#include <QElapsedTimer>  // Pour mesurer le temps de traitement

// Constructeur par défaut
ressource::ressource()
    : NOM(""), DESCRIPTION(""), TYPE(""), LOCALISATION(""),  QUANTITE(0), ETAT(""),decodingCount(0), totalProcessingTime(0)
{
}

// Constructeur avec paramètres
ressource::ressource(QString nom, QString description, QString type, QString localisation, int quantite, QString etat)
{
    this->NOM = nom;
    this->DESCRIPTION = description;
    this->TYPE = type;
    this->LOCALISATION = localisation;
    this->QUANTITE = quantite;
    this->ETAT = etat;
    this->decodingCount = 0;
    this->totalProcessingTime = 0;
}

// Méthode pour ajouter une ressource dans la base de données
bool ressource::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO RESSOURCE (NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT) "
                  "VALUES (:NOM, :DESCRIPTION, :TYPE, :LOCALISATION, :QUANTITE, :ETAT)");

    query.bindValue(":NOM", NOM);
    query.bindValue(":DESCRIPTION", DESCRIPTION);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":LOCALISATION", LOCALISATION);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT);

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError();
        qDebug() << "Query executed:" << query.lastQuery(); // Afficher la requête exécutée
        return false;
    }
    return true;
}

// Méthode pour afficher toutes les ressources de la base de données
QSqlQueryModel* ressource::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Etat"));

    return model;
}

// Méthode pour supprimer une ressource en fonction de l'id
bool ressource::supprimer(int ID)
{
    QSqlQuery query;
    QString res = QString::number(ID);

    // Préparer la requête de suppression
    query.prepare("DELETE FROM RESSOURCE WHERE ID = :ID");
    query.bindValue(":ID", res);

    // Exécuter la requête
    return query.exec();
}

// Trouver une ressource en fonction de son ID
ressource ressource::trouver(int ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RESSOURCE WHERE ID = ?");
    query.addBindValue(ID);
    query.exec();
    if (query.next()) {
        return ressource(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),
                         query.value(4).toString(), query.value(5).toInt(), query.value(6).toString());
    }
    return ressource();  // Retourner une ressource vide si non trouvée
}

// Méthode pour modifier une ressource dans la base de données
bool ressource::modifier(int ID)
{
    QSqlQuery query;
    query.prepare("UPDATE RESSOURCE SET NOM = ?, DESCRIPTION = ?, TYPE = ?, LOCALISATION = ?, QUANTITE = ?, ETAT = ? WHERE ID = ?");
    query.addBindValue(NOM);
    query.addBindValue(DESCRIPTION);
    query.addBindValue(TYPE);
    query.addBindValue(LOCALISATION);
    query.addBindValue(QUANTITE);
    query.addBindValue(ETAT);
    query.addBindValue(ID);

    return query.exec();
}

// Méthode pour vérifier si la ressource est valide
bool ressource::isValid()
{
    return !NOM.isEmpty();  // Si le nom est vide, la ressource est considérée comme invalide
}

// Méthode pour ajouter une ressource sans QR code
bool ressource::ajouter1() {
    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCE (NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT) "
                  "VALUES (:NOM, :DESCRIPTION, :TYPE, :LOCALISATION, :QUANTITE, :ETAT)");

    query.bindValue(":NOM", NOM);
    query.bindValue(":DESCRIPTION", DESCRIPTION);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":LOCALISATION", LOCALISATION);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT);

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError();
        qDebug() << "Query executed:" << query.lastQuery();
        return false;
    }

    return true;
}

// Méthode pour générer un fichier PDF avec du contenu (par exemple, le contenu d'une ressource)
void ressource::generatePDF(const QString &nom, const QString &description, const QString &type,
                            const QString &localisation, int quantite, const QString &etat)
{
    // Créer un document PDF
    QPdfWriter writer("ressource.pdf");
    writer.setPageSize(QPageSize::A4);

    writer.setResolution(300);

    QPainter painter(&writer);

    // Vérifier que l'objet QPainter est bien initialisé
    if (!painter.isActive()) {
        qWarning() << "Le painter n'a pas pu être initialisé.";
        return;
    }

    // Définir la police et la taille
    QFont font("Arial", 12);  // Utiliser une police claire et une taille suffisante
    painter.setFont(font);

    // Définir la couleur du texte
    painter.setPen(Qt::black);

    // Ajouter des marges et des espacements entre les lignes
    int yOffset = 100;  // Définir un décalage pour commencer à écrire
    int lineSpacing = 100;  // Espacement entre les lignes

    // Dessiner chaque ligne de texte
    painter.drawText(50, yOffset, "Nom: " + nom);
    yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Description: " + description);
    yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Type: " + type);
    yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Localisation: " + localisation);
    yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Quantité: " + QString::number(quantite));
    yOffset += lineSpacing;
    painter.drawText(50, yOffset, "Etat: " + etat);

    // Finaliser le dessin et fermer le fichier
    painter.end();
}
// Exemple de méthode pour calculer le nombre total de ressources
int ressource::getTotalResources() {
    QSqlQuery query("SELECT COUNT(*) FROM RESSOURCE");  // Remplace "ressources" par le nom de ta table
    if (query.next()) {
        return query.value(0).toInt();  // Retourne le nombre total de ressources
    }
    return 0;  // Retourne 0 si aucune ressource n'est trouvée
}


// Exemple de méthode pour calculer la quantité totale des ressources
int ressource::getTotalQuantity() {
    QSqlQuery query("SELECT SUM(QUANTITE) FROM RESSOURCE");  // Remplace "ressources" par le nom de ta table
    if (query.next()) {
        return query.value(0).toInt();  // Retourne la somme des quantités
    }
    return 0;  // Retourne 0 si aucune quantité n'est trouvée
}


// Exemple de méthode pour calculer la répartition des ressources par état
QMap<QString, int> ressource::getResourcesByState() {
    QMap<QString, int> stateCount;
    QSqlQuery query("SELECT ETAT, COUNT(*) FROM RESSOURCE GROUP BY ETAT");  // Remplacez "ressources" par le nom exact de votre table

    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return stateCount;  // Retourne un QMap vide en cas d'erreur
    }

    while (query.next()) {
        QString etat = query.value(0).toString();
        int count = query.value(1).toInt();
        stateCount[etat] = count;
        qDebug() << "Etat:" << etat << "Count:" << count;  // Débogage : affiche chaque état et son comptage
    }

    return stateCount;
}
#include "ressource.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

QSqlQueryModel* ressource::search(const QString& searchQuery) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM ressources WHERE NOM LIKE :searchQuery OR DESCRIPTION LIKE :searchQuery");
    query.bindValue(":searchQuery", "%" + searchQuery + "%");

    // Déplacer l'objet query plutôt que de le copier
    model->setQuery(std::move(query));  // Utilisation de std::move() ici

    return model;
}

QSqlQueryModel* ressource::Trier_Ressources(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString;

    // Tri selon le critère (TYPE ou QUANTITE)
    if (critere == "TYPE") {
        queryString = "SELECT * FROM RESSOURCE ORDER BY TYPE ASC";
    } else if (critere == "QUANTITE") {
        queryString = "SELECT * FROM RESSOURCE ORDER BY QUANTITE DESC";
    } else {
        return afficher();  // Affichage sans tri si critère invalide
    }

    query.prepare(queryString);

    if (query.exec()) {
        model->setQuery(std::move(query));  // éviter le warning de copie
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("LOCALISATION"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("IDPROJET"));
        return model;
    } else {
        delete model;
        return nullptr;
    }
}
QSqlQueryModel* ressource::recherche(const QString &searchQuery)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString searchValue = "%" + searchQuery + "%";

    query.prepare("SELECT ID, NOM, DESCRIPTION, TYPE, LOCALISATION, QUANTITE, ETAT, IDPROJET "
                  "FROM RESSOURCE "
                  "WHERE TO_CHAR(ID) LIKE :val "
                  "OR LOWER(NOM) LIKE LOWER(:val) "
                  "OR LOWER(DESCRIPTION) LIKE LOWER(:val) "
                  "OR LOWER(TYPE) LIKE LOWER(:val) "
                  "OR LOWER(LOCALISATION) LIKE LOWER(:val) "
                  "OR TO_CHAR(QUANTITE) LIKE :val "
                  "OR LOWER(ETAT) LIKE LOWER(:val) "
                  "OR TO_CHAR(IDPROJET) LIKE :val");

    query.bindValue(":val", searchValue);

    if (query.exec())
    {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Localisation"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Quantité"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID Projet"));

        return model;
    }
    else
    {
        qDebug() << "Erreur de recherche RESSOURCE :" << query.lastError().text();
        delete model;
        return afficher(); // fallback
    }
}




