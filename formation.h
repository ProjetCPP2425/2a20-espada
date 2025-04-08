#ifndef FORMATION_H
#define FORMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Formation
{
    QString TITRE;
    QString DESCRIPTION;
    QString DATE_DEBUT;
    QString DATE_FIN;
    int DUREE;
    float PRIX;
    int IDC;

public:
    Formation(){}
    Formation(QString, QString, QString, QString, int, float, int);

    QString getTITRE() { return TITRE; }
    QString getDESCRIPTION() { return DESCRIPTION; }
    QString getDATE_DEBUT() { return DATE_DEBUT; }
    QString getDATE_FIN() { return DATE_FIN; }
    int getDUREE() { return DUREE; }
    float getPRIX() { return PRIX; }

    void setTITRE(QString t) { TITRE = t; }
    void setDESCRIPTION(QString d) { DESCRIPTION = d; }
    void setDATE_DEBUT(QString dd) { DATE_DEBUT = dd; }
    void setDATE_FIN(QString df) { DATE_FIN = df; }
    void setDUREE(int d) { DUREE = d; }
    void setPRIX(float p) { PRIX = p; }

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int ID_FORMATION, QString titre, QString description, QString date_debut, QString date_fin, int duree, float prix);
    QSqlQueryModel* recherche(const QString &searchQuery);
    QSqlQueryModel* trier(QString critere);
};

#endif // FORMATION_H
