#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ressource
{
    QString NOM, DESCRIPTION, TYPE, LOCALISATION, ETAT;
    int ID, QUANTITE;

public:
    // Constructeur par défaut
    ressource() {}

    // Constructeur avec paramètres
    ressource (QString nom, QString description,  QString type, QString localisation, int quantite, QString etat);

    // Getters
    int getID() { return ID; }
    QString getNOM() { return NOM; }
    QString getDESCRIPTION() { return DESCRIPTION; }
    QString getTYPE() { return TYPE; }
    QString getLOCALISATION() { return LOCALISATION; }
    int getQUANTITE() { return QUANTITE; }
    QString getETAT() { return ETAT; }

    // Setters
    void setID(int id) { this->ID = id; }
    void setNom(QString n) { NOM = n; }
    void setDescription(QString d) { DESCRIPTION = d; }
    void setType(QString t) { TYPE = t; }
    void setLocalisation(QString l) { LOCALISATION = l; }
    void setQuantite(int quantite) { this->QUANTITE = quantite; }
    void setEtat(QString e) { ETAT = e; }

    // Méthodes de gestion des ressources
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    ressource trouver(int id);
    bool modifier(int id);
    bool isValid();  // Vérifie si la ressource est valide

};

#endif // RESSOURCE_H
