#ifndef CLASS_depot1c_H
#define CLASS_depot1c_H
#include <QSqlQuery>
#include <QString>
#include<QSqlQueryModel>

class class_depot1c
{
public:
    class_depot1c();
    void set_nomclient(QString nomclient){this->nomclient=nomclient;}
    void set_reference(QString reference){this->reference=reference;}
    void set_adresse(QString adresse){this->adresse=adresse;}
    void set_telephone(QString telephone){this->telephone=telephone;}
    void set_email(QString email){this->email=email;}
    void set_domaine(QString domaine){this->domaine=domaine;}
    void set_point(int point){this->point=point;}

    QString get_nomclient(){return nomclient;}
    QString get_reference(){return reference;}
    QString get_adresse(){return adresse;}
    QString get_telephone(){return telephone;}
    QString get_email(){return email;}
    QString get_domaine(){return domaine;}
    int get_point(){return point;}
    void ajouter();
    void modifier();
    void supprimer();
    QSqlQueryModel*afficher();
    QSqlQueryModel*rechercher();
private:
QString nomclient;
QString reference;
QString adresse;
QString telephone;
QString email;
QString domaine;
int point;
};

#endif // CLASS_depot1c_H
