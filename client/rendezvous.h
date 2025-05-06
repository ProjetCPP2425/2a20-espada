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

//ferreessssssssss
class Clients
{
    QString nom_client,prenom_client,email_client,tel_client,type_client,adresse_client,date_inscri_client,specialite_client,nom_emp;
    int id_emp,id_client;
    QString smoke_detected;
public:
    //constracteurs
    Clients(){}
    Clients(int id_e, QString n, QString p, QString e, QString t, QString y, QString a, QString d, QString s);
    //getters
    QString getNom_client(){return nom_client;}
    QString getPrenom_client(){return prenom_client;}
    QString getEmail_client(){return email_client;}
    QString getTel_client(){return tel_client;}
    QString getType_client(){return type_client;}
    QString getAdresse_client(){return adresse_client;}
    QString getDate_client(){return date_inscri_client;}
    QString getSpecialite_client(){return specialite_client;}
    int getId_emp(){return id_emp;}
    QString getNom_emp(){return nom_emp;}
    //setters
    void setNom_client(QString n){nom_client=n;}
    void setPrenom_client(QString p){prenom_client=p;}
    void setEmail_client(QString e){email_client=e;}
    void setTel_client(QString t){tel_client=t;}
    void setType_client(QString y){type_client=y;}
    void setAdresse_client(QString a){adresse_client=a;}
    void setDate_client(QString d){date_inscri_client=d;}
    void setSpecialite_client(QString s){specialite_client=s;}
    void setId_emp(int id_e){id_emp=id_e;}
    void setNom_emp(QString n){nom_emp=n;}

    QString getSmokeDetected() { return smoke_detected; }
    void setSmokeDetected(QString s) { smoke_detected = s; }

    QSqlQueryModel * afficher_client();
    bool supprimer_client(int);
    bool ajouter_client();
    bool modifier_client(int id_client, QString nom_client, QString prenom_client, QString email_client, QString tel_client, QString type_client, QString adresse_client, QString date_inscri_client, QString specialite_client, int original_id_emp);
    bool employeeExists_client(int id_emp);
    bool clientExists_client(int id_c);

    // metiers simples
    QSqlQueryModel* recherche_client(const QString &searchQuery);
    QSqlQueryModel* Trier_client(QString critere);
};
//fereessssss
#endif // RENDEZVOUS_H
