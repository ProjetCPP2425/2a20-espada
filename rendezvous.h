#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QCalendarWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QMessageBox>
#include <QDebug>
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
//moataz
class ressource
{
public:
    ressource();
    ressource(QString nom, QString description, QString type, QString localisation, int quantite, QString etat, QString telephone, QString fournisseur);


    bool ajouter_res();
    bool supprimer_res(int ID);
    bool modifier_res(int ID);
    QSqlQueryModel* afficher_res();
    ressource trouver_res(int ID);
    bool ajouter1_res();
    int getTotalResources_res();
    int getTotalQuantity_res();
    QMap<QString, int> getResourcesByState_res();
    bool isValid();
    //QSqlQueryModel* search(const QString& searchQuery);
    QSqlQueryModel* recherche_res(const QString &searchQuery);
    QSqlQueryModel* Trier_Ressources_res(QString critere);


    // Getters
    int getID() const { return ID_res; }
    QString getNOM() const { return NOM_res; }
    QString getDESCRIPTION() const { return DESCRIPTION_res; }
    QString getTYPE() const { return TYPE_res; }
    QString getLOCALISATION() const { return LOCALISATION_res; }
    int getQUANTITE() const { return QUANTITE_res; }
    QString getETAT() const { return ETAT_res; }
    //int getIDPROJET() const { return IDPROJET; }
    QString getTELEPHONE() const { return TELEPHONE_res; }
    QString getFOURNISSEUR() const { return FOURNISSEUR_res; }

    // Setters
    void setNom(const QString &value) { NOM_res = value; }
    void setDescription(const QString &value) { DESCRIPTION_res = value; }
    void setType(const QString &value) { TYPE_res = value; }
    void setLocalisation(const QString &value) { LOCALISATION_res = value; }
    void setQuantite(int value) { QUANTITE_res = value; }
    void setEtat(const QString &value) { ETAT_res = value; }
    //void setIdprojet(int value) { IDPROJET = value; }
    void setTelephone(const QString &value) { TELEPHONE_res = value; }
    void setFournisseur(const QString &value) { FOURNISSEUR_res = value; }

    void generatePDF_res(const QString &nom, const QString &description, const QString &type,
                         const QString &localisation, int quantite, const QString &etat, const QString &telephone,const QString &fournisseur);

private:
    int ID_res;
    QString NOM_res;
    QString DESCRIPTION_res;
    QString TYPE_res, text;
    QString LOCALISATION_res;
    int QUANTITE_res;
    QString ETAT_res;
    //int IDPROJET;
    QString TELEPHONE_res;
    QString FOURNISSEUR_res;

    int decodingCount;
    int totalProcessingTime;
    QList<ressource> resourcesList;

};


//moataz
//akram
class Projets
{
    QString nom_projet,description_projet,date_debut_projet,date_fin_projet,statue_projet;
    int id_client_projet,id_projet;
    QString smoke_detected;
public:
    Projets(){};
    Projets(int,QString,QString,QString,QString,QString,int,QString);

    QString getNom_projet(){return nom_projet;}
    QString getDescription(){return description_projet;}
    QString getDate_Debut(){return date_debut_projet;}
    QString getStatue(){return statue_projet;}
    QString getDate_Fin(){return date_fin_projet;}
    int getId_client(){return id_client_projet;}
    int getId_projet(){return id_projet;}
    //setters
    void setNom_projet(QString p){nom_projet=p;}
    void setDescription(QString d){description_projet=d;}
    void setDate_Debut(QString deb){date_debut_projet=deb;}
    void setDate_Fin(QString fin){date_fin_projet=fin;}
    void setStatue(QString stat){statue_projet=stat;}
    void setId_client(int id_c){id_client_projet=id_c;}
    void setId_projet(int id_p){id_projet=id_p;}

    QString getSmokeDetected() { return smoke_detected; }
    void setSmokeDetected(QString s) { smoke_detected = s; }

    QSqlQueryModel * afficher_projet();
    bool supprimer_projet(int);
    bool ajouter_projet();
    bool modifier_projet(int id_projet, QString nom_projet, QString description, QString date_debut, QString statue, QString date_fin);
    QSqlQueryModel* recherche_projet(const QString &keyword);
    QMap<QString, int> getStatusCounts_projet();
    QSqlQueryModel * afficherSortedAsc_projet();
    QSqlQueryModel * afficherSortedDesc_projet();


};
//akram
#endif // RENDEZVOUS_H
