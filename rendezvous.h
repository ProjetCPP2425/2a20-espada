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
//hammmaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
class em
{

    QString NOMEM , PRENOMEM ;
    QString EMAILEM ;
    int TELEPHONEEM ;
    QString SPECIALITEEM ;
    int EXPERIENCEEM ;
    QString DISPONIBILITEEM ;
    QString LOGIN , MDP ;




public:
    //construct
    em(){}
    em(QString, QString, QString,int, QString,int, QString, QString, QString);
    //getters

    QString getNOMEM() {return NOMEM ;}
    QString getPRENOMEM() {return PRENOMEM ;}
    QString getEMAILEM() {return EMAILEM ;}
    int getTELEPHONEEM() {return TELEPHONEEM;}
    QString getSPECIALITEEM() {return SPECIALITEEM ;}
    int getEXPERIENCEEM() {return EXPERIENCEEM;}
    QString getDISPONIBILITEEM() {return DISPONIBILITEEM ;}
    QString getLOGIN() {return LOGIN ;}
    QString getMDP() {return MDP ;}
    //setters

    void setNOMEM(QString n){NOMEM=n;}
    void setPRENOMEM(QString p){PRENOMEM=p;}
    void setTELEPHONEEM(int tel){this->TELEPHONEEM=tel;}
    void setSPECIALITEEM(QString s){SPECIALITEEM=s;}
    void setEXPERIENCEEM(int exp){this->EXPERIENCEEM=exp;}
    void setDISPONIBILITEEM(QString d){DISPONIBILITEEM=d;}
    void setLOGIN(QString l){LOGIN=l;}
    void setMDP(QString mp){MDP=mp;}
    //fonctionnalites
    bool ajouterem();
    QSqlQueryModel * afficherem();
    bool supprimerem(int);
    bool modifierem(int IDEMPLOYE, QString NOMEM, QString preNOMEM, QString EMAILEM, int TELEPHONEEM, QString SPECIALITEEM, int exp, QString dispo, QString log, QString mdp);
    QSqlQueryModel* Trier_Employe(QString critere);



};
//hammmaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#endif // RENDEZVOUS_H
