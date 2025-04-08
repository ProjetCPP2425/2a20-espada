#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>  // Ajoutez cette ligne pour inclure QMap

class ressource
{
public:
    ressource();
    ressource(QString nom, QString description, QString type, QString localisation, int quantite, QString etat);

    bool ajouter();
    bool supprimer(int ID);
    bool modifier(int ID);
    QSqlQueryModel* afficher();
    ressource trouver(int ID);
    bool ajouter1();
    int getTotalResources();
    int getTotalQuantity();
    QMap<QString, int> getResourcesByState();  // Déclarez la fonction ici
    bool isValid();  // Déclarez également la fonction isValid
    QSqlQueryModel* search(const QString& searchQuery);
    int getID() const { return ID; }

    QString getNOM() const { return NOM; }
    QString getDESCRIPTION() const { return DESCRIPTION; }
    QString getTYPE() const { return TYPE; }
    QString getLOCALISATION() const { return LOCALISATION; }
    int getQUANTITE() const { return QUANTITE; }
    QString getETAT() const { return ETAT; }

    void setNom(const QString &value) { NOM = value; }
    void setDescription(const QString &value) { DESCRIPTION = value; }
    void setType(const QString &value) { TYPE = value; }
    void setLocalisation(const QString &value) { LOCALISATION = value; }
    void setQuantite(int value) { QUANTITE = value; }
    void setEtat(const QString &value) { ETAT = value; }

    void generatePDF(const QString &nom, const QString &description, const QString &type,
                     const QString &localisation, int quantite, const QString &etat);

    QSqlQueryModel*Trier_Ressources(QString critere);
    QSqlQueryModel* recherche(const QString &searchQuery);

private:
    int ID;
    QString NOM;
    QString DESCRIPTION;
    QString TYPE,text;
    QString LOCALISATION;
    int QUANTITE;
    QString ETAT;

    int decodingCount;
    int totalProcessingTime;
    QList<ressource> resourcesList;
};

#endif // RESSOURCE_H
