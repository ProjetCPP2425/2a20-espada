#ifndef EM_H
#define EM_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class em
{

    QString NOM , PRENOM ;
    QString EMAIL ;
    int TELEPHONE ;
    QString SPECIALITE ;
    int EXPERIENCE ;
    QString DISPONIBILITE ;
    QString LOGIN , MDP ;




public:
    //construct
    em(){}
    em(QString, QString, QString,int, QString,int, QString, QString, QString);
    //getters

    QString getNOM() {return NOM ;}
    QString getPRENOM() {return PRENOM ;}
    QString getEMAIL() {return EMAIL ;}
    int getTELEPHONE() {return TELEPHONE;}
    QString getSPECIALITE() {return SPECIALITE ;}
    int getEXPERIENCE() {return EXPERIENCE;}
    QString getDISPONIBILITE() {return DISPONIBILITE ;}
    QString getLOGIN() {return LOGIN ;}
    QString getMDP() {return MDP ;}
    //setters

    void setNOM(QString n){NOM=n;}
    void setPRENOM(QString p){PRENOM=p;}
    void setTELEPHONE(int tel){this->TELEPHONE=tel;}
    void setSPECIALITE(QString s){SPECIALITE=s;}
    void setEXPERIENCE(int exp){this->EXPERIENCE=exp;}
    void setDISPONIBILITE(QString d){DISPONIBILITE=d;}
    void setLOGIN(QString l){LOGIN=l;}
    void setMDP(QString mp){MDP=mp;}
    //fonctionnalites
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int IDEMPLOYE, QString nom, QString prenom, QString email, int telephone, QString specialite, int exp, QString dispo, QString log, QString mdp);
    QSqlQueryModel* Trier_Employe(QString critere);



};

#endif // EM_H
