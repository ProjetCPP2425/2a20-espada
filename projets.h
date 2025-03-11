#ifndef PROJETS_H
#define PROJETS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projets
{
    QString nom_projet,describtion,date_debut,date_fin,statue;
    int id_client,id_projet;
public:
    Projets(){};
    Projets(int,QString,QString,QString,QString,QString);

    QString getNom_projet(){return nom_projet;}
    QString getDescribtion(){return describtion;}
    QString getDate_Debut(){return date_debut;}
    QString getStatue(){return statue;}
    QString getDate_Fin(){return date_fin;}
    int getId_client(){return id_client;}
    int getId_projet(){return id_projet;}
    //setters
    void setNom_projet(QString p){nom_projet=p;}
    void setDescribtion(QString d){describtion=d;}
    void setDate_Debut(QString deb){date_debut=deb;}
    void setDate_Fin(QString fin){date_fin=fin;}
    void setStatue(QString stat){statue=stat;}
    void setId_client(int id_c){id_client=id_c;}
    void setId_projet(int id_p){id_projet=id_p;}

    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool ajouter();
    bool modifier(int id_projet, QString nom_projet, QString describtion, QString date_debut, QString statue, QString date_fin);


};

#endif // PROJETS_H
