#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Clients
{
    QString nom_client,prenom_client,email_client,tel_client,type_client,adresse_client,date_inscri_client,specialite_client;
    int id_emp,id_client;
public:
    //constracteurs
    Clients(){}
    Clients(int,QString,QString,QString,QString,QString,QString,QString,QString);
    //getters
    QString getNom_client(){return nom_client;}
    QString getPrenom_client(){return prenom_client;}
    QString getEmail_client(){return email_client;}
    QString getTel_client(){return tel_client;}
    QString getType_client(){return type_client;}
    QString getAdresse_client(){return adresse_client;}
    QString getDate_client(){return date_inscri_client;}
    QString getSpecialite_client(){return specialite_client;}
    int getId_client(){return id_client;}
    int getId_emp(){return id_emp;}
    //setters
    void setNom_client(QString n){nom_client=n;}
    void setPrenom_client(QString p){prenom_client=p;}
    void setEmail_client(QString e){email_client=e;}
    void setTel_client(QString t){tel_client=t;}
    void setType_client(QString y){type_client=y;}
    void setAdresse_client(QString a){adresse_client=a;}
    void setDate_client(QString d){date_inscri_client=d;}
    void setSpecialite_client(QString s){specialite_client=s;}
    void setId_client(int id_c){id_client=id_c;}
    void setId_emp(int id_e){id_emp=id_e;}


    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool ajouter();
    bool modifier(int id_client, QString prenom_client, QString nom_client, QString email_client,QString tel_client, QString type_client, QString adresse_client, QString date_inscri_client, QString specialite_client);
};

#endif // CLIENTS_H
