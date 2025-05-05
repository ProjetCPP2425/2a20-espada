#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QCalendarWidget>
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
    bool ajouter_RDV();
    QSqlQueryModel* afficher_RDV();
    bool modifier_RDV(int);
    bool supprimer_RDV(int);
    // metiers simples
    QSqlQueryModel* recherche_RDV(const QString &searchQuery);
    QSqlQueryModel* Trier_RDV(QString critere);
    QSqlQueryModel* Select_by_date_r_RDV(QDate date);

 QCalendarWidget* getAllRDV_RDV(QCalendarWidget* calendar);
    void on_calandar_rdv_clicked(const QDate &date);
 int nombre_RDV();
private:
    int id_rdv,fmt;
    QDate date_rdv;
    QString heure_rdv, mode_rdv, objectif, nom_client,text;
};

#endif // RENDEZVOUS_H
