#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QDate>

class RendezVous
{
public:
    RendezVous();
    RendezVous(int, QDate, QString, QString, QString, QString);

    // Getters
    int get_id_rdv();
    QDate get_date_rdv();
    QString get_heure_rdv();
    QString get_mode_rdv();
    QString get_objectif();
    QString get_nom_client();

    // Setters
    void set_id_rdv(int);
    void set_date_rdv(QDate);
    void set_heure_rdv(QString);
    void set_mode_rdv(QString);
    void set_objectif(QString);
    void set_nom_client(QString);

    // CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int);
    bool supprimer(int);

private:
    int id_rdv;
    QDate date_rdv;
    QString heure_rdv, mode_rdv, objectif, nom_client;
};

#endif // RENDEZVOUS_H
