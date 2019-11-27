#ifndef GESTIONPRODUIT_H
#define GESTIONPRODUIT_H
#include<QWidget>
#include <QString>
#include"ui_gestionproduit.h"
#include"connexion.h"
#include<QSqlDatabase>
#include<QSql>
#include<QSqlQueryModel>
#include "note.h"
#include"commentaire.h"
namespace Ui {
class gestionp;
}
class gestionp : public QWidget
{
    Q_OBJECT

public:
    explicit gestionp(QWidget *parent = 0);
    ~gestionp();



private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_refrech_clicked();

    void on_pushButton_6_clicked();





    void on_tabWidget_tabBarClicked();

   // void on_tableView_clicked(const QModelIndex &index);

    void on_recherche_clicked();

  //  void on_fournisseur_activated(const QString &arg1);

private:
    Ui::gestionp *ui;
    Note *m2;
    commentaire *m3;
};


class Produit
{
private :
QString reference;
QString nom;
QString categorie;
QString fournisseur;
QString quantite;
QString prix;
QString remise;
QString note;
QString commentaire;

QString ref;
QString ref1;




public :
Produit(){}
bool ajouterProduit();
void supprimerProduit();
void modifier();
//void rechercherRef();
//void rechercherCat();
//void rechercherFour();

QSqlQueryModel * afficher();

QSqlQueryModel * afficherRef(QString ref="");
QSqlQueryModel * afficherFour(QString ref="");
QSqlQueryModel * afficherCat(QString ref="");
QSqlQueryModel * afficherCatFour(QString ref="",QString ref1="");


QSqlQueryModel *affCategorie();
QSqlQueryModel *affFourniss();

QString get_reference(){return reference;}
QString get_nom(){return nom;}
QString get_categorie(){return categorie;}
QString get_fournisseur(){return fournisseur;}
QString get_quantite(){return quantite;}
QString get_prix(){return prix;}
QString get_remise(){return remise;}
QString get_note(){return note;}
QString get_commentaire(){return commentaire;}

void set_reference(QString reference){this->reference=reference;}
void set_nom(QString nom){this->nom=nom;}
void set_categorie(QString categorie){this->categorie=categorie;}
void set_fournisseur(QString fournisseur){this->fournisseur=fournisseur;}
void set_quantite(QString quantite){this->quantite=quantite;}
void set_prix(QString prix){this->prix=prix;}
void set_remise(QString remise){this->remise=remise;}
void set_note(QString note){this->note=note;}
void set_commentaire(QString commentaire){this->commentaire=commentaire;}

};
#endif // GESTIONPRODUIT_H
