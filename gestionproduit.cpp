#include "gestionproduit.h"
#include "ui_gestionproduit.h"
//#include"gestionfournisseur.h"
//#include"ffarah.h"
//#include"note.h"
//#include"ui_note.h"
#include<QPixmap>
#include<iostream>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include"connexion.h"
#include<QSqlQueryModel>
#include<QObject>
#include<QMessageBox>
gestionp::gestionp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestionp)


{
  ui->setupUi(this);


             Produit p;
             ui->fournisseur->setModel(p.affFourniss());
             ui->categorie->setModel(p.affCategorie());

             ui->fo->setModel(p.affFourniss());
             ui->ca->setModel(p.affCategorie());


              QSqlQueryModel *model=new QSqlQueryModel();
              model=p.afficher();
              ui->tableView->setModel(model);

}
gestionp::~gestionp()
{
    delete ui;
}

bool Produit::ajouterProduit()
{



QSqlQuery q;

        q.prepare("INSERT INTO PRODUIT (reference,nom,categorie,fournisseur,quantite,prix,remise) VALUES (?,?,?,?,?,?,?)");
        q.addBindValue(get_reference());
       q.addBindValue(get_nom());
       q.addBindValue(get_categorie());
       q.addBindValue(get_fournisseur());
       q.addBindValue(get_quantite());
       q.addBindValue(get_prix());
       q.addBindValue(get_remise());
      // q.addBindValue(get_note());
       //q.addBindValue(get_commentaire());
       q.exec();



        if(q.exec())
        {
            qDebug()<<"Bravo"<<endl;
            return true;
        }
        else
        {
            return false;
        }
}
void Produit::supprimerProduit()
{
QSqlQuery q;


q.prepare("Delete from PRODUIT where reference=(?)");
q.addBindValue(get_reference());
q.exec();

}
void Produit::modifier()
{

    QSqlQuery q;




     q.prepare("update PRODUIT set nom=(?),categorie=(?),fournisseur=(?),quantite=(?),prix=(?),remise=(?) where reference=(?)");
     q.addBindValue(get_nom());
     q.addBindValue(get_categorie());
     q.addBindValue(get_fournisseur());
     q.addBindValue(get_quantite());
     q.addBindValue(get_prix());
     q.addBindValue(get_remise());
    // q.addBindValue(get_note());
    // q.addBindValue(get_commentaire());
     q.addBindValue(get_reference());
     q.exec();

}

/*void Produit::rechercherRef()
{
    QSqlQuery q;


    q.prepare("select * from PRODUIT where reference=(?)");
    q.addBindValue(get_reference());
    q.exec();

}
void Produit::rechercherCat()
{
    QSqlQuery q;


    q.prepare("select * from PRODUIT where categorie=(?)");
    q.addBindValue(get_categorie());
    q.exec();

}
void Produit::rechercherFour()
{
    QSqlQuery q;


    q.prepare("select * from PRODUIT where fournisseur=(?)");
    q.addBindValue(get_fournisseur());
    q.exec();

}*/

QSqlQueryModel*Produit::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from PRODUIT");
return(model);
}

QSqlQueryModel *Produit::afficherRef(QString ref)
{
    this->reference=ref;

    QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from PRODUIT where reference='"+this->reference+"'");

  return(model);
}

QSqlQueryModel*Produit::afficherFour(QString ref)
{
    this->fournisseur=ref;
  QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from PRODUIT where fournisseur ='"+this->fournisseur+"'");
return(model);
}

QSqlQueryModel*Produit::afficherCat(QString ref)
{
    this->categorie=ref;

  QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from PRODUIT where categorie='"+this->categorie+"'");
return(model);
}
QSqlQueryModel*Produit::afficherCatFour(QString ref,QString ref1)
{
    this->categorie=ref;
    this->fournisseur=ref1;

  QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from PRODUIT where categorie='"+this->categorie+"' and fournisseur='"+this->fournisseur+"'");
return(model);
}

QSqlQueryModel *Produit::affCategorie()
{
    QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select nom from categorie");
  return(model);
}

QSqlQueryModel *Produit::affFourniss()
{
    QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select nom from fournisseur");
  return(model);
}



void gestionp::on_pushButton_clicked()
{
  Produit p;
 // QString x="oui ";

p.set_reference(ui->ref->text());
p.set_nom(ui->nom->text());
p.set_categorie(ui->categorie->currentText());
p.set_fournisseur(ui->fournisseur->currentText());
p.set_quantite(ui->quantite->text());
p.set_prix(ui->prix->text());


//x+=ui->remise->text()+"%";

if (ui->non->isChecked()){p.set_remise("non");}
else if (ui->oui->isChecked()){p.set_remise("oui    "+ui->remise->text()+"%");}



//p.set_remise(ui->remise->text());
//p.set_note(ui->note->text());
//p.set_commentaire(ui->commentaire->text());
p.ajouterProduit();

QSqlQueryModel *model=new QSqlQueryModel();
model=p.afficher();
ui->tableView->setModel(model);
}


void gestionp::on_pushButton_3_clicked()
{    Produit p;
    p.set_reference(ui->refe->text());
    p.set_nom(ui->nom1->text());
    p.set_categorie(ui->cat->text());
    p.set_fournisseur(ui->four->text());
    p.set_quantite(ui->qu->text());
    p.set_prix(ui->pri->text());

     if (ui->non_2->isChecked()){p.set_remise("non");}
     else if (ui->oui_2->isChecked()){p.set_remise("oui    "+ui->rem->text()+"%");}


     //  p.set_remise(ui->rem->text());

    p.set_note(ui->notee->text());
    p.set_commentaire(ui->com->text());

     p.modifier();


      QSqlQueryModel *model=new QSqlQueryModel();
      model=p.afficher();
      ui->tableView->setModel(model);
}

void gestionp::on_pushButton_4_clicked()
{
    Produit p;
    p.set_reference(ui->refe->text());
    p.supprimerProduit();

    QSqlQueryModel *model=new QSqlQueryModel();
    model=p.afficher();
    ui->tableView->setModel(model);
}



void gestionp::on_tableView_activated(const QModelIndex &index)
{

    QString val=ui->tableView->model()->data(index).toString();

    QString remise;


    QSqlQuery q;
    q.prepare("select * from PRODUIT where reference='"+val+"' or nom='"+val+"' or categorie='"+val+"' or fournisseur='"+val+"' or quantite='"+val+"' or prix='"+val+"' or remise='"+val+"' or note='"+val+"' or commentaire='"+val+"'");

    if (q.exec())
    {
        while (q.next())
        {
            ui->refe->setText(q.value(0).toString());
            ui->nom1->setText(q.value(1).toString());
            ui->cat->setText(q.value(2).toString());
            ui->four->setText(q.value(3).toString());
            ui->qu->setValue(q.value(4).toInt());
            ui->pri->setText(q.value(5).toString());

            remise=q.value(6).toString();
            QString r = remise.section("    ",0,0);
            QString re=remise.section("    ",1,1);
            if (r=="oui")
            {
                ui->oui_2->setChecked(true);
                ui->rem->setText(re);
            }

            if (r=="non")
            {
                ui->non_2->setChecked(true);
                ui->rem->setText(re);
            }

            //ui->rem->setText(q.value(6).toString());


            ui->notee->setText(q.value(7).toString());
            ui->com->setText(q.value(8).toString());


        }
     }


}



void gestionp::on_pushButton_5_clicked()
{

    m2=new Note(this,ui->refe->text());
    m2->show();





}

void gestionp::on_refrech_clicked()
{

    Produit p;
     QSqlQueryModel *model=new QSqlQueryModel();
     model=p.afficher();
     ui->tableView->setModel(model);

}

void gestionp::on_pushButton_6_clicked()
{
    m3=new commentaire(this,ui->refe->text());
    m3->show();

}





void gestionp::on_tabWidget_tabBarClicked()
{
    int l=ui->tableView->verticalHeader()->count();
        QString s="";
        for(int i=0;i<l;i++){
            ui->tableView->selectRow(i);
            if((ui->tableView->selectionModel()->selectedIndexes().at(4).data().toInt()<=5))
            {
                s+="le produit "+ui->tableView->selectionModel()->selectedIndexes().at(1).data().toString()+" est en rupture de stock\n";
            }
        }
        QMessageBox::critical(this,"rupture",s);
}



void gestionp::on_recherche_clicked()
{
    Produit p;



    if (ui->rech->isModified())
    {
        QSqlQueryModel *model=new QSqlQueryModel();
         model=p.afficherRef(ui->rech->text());
         ui->tableView->setModel(model);
    }

    if (ui->foo->isChecked())
    {

        QSqlQueryModel *model=new QSqlQueryModel();
         model=p.afficherFour(ui->fo->currentText());
         ui->tableView->setModel(model);

    }


    if(ui->caa->isChecked())
    {


        QSqlQueryModel *model=new QSqlQueryModel();
         model=p.afficherCat(ui->ca->currentText());
         ui->tableView->setModel(model);
    }


    if((ui->foo->isChecked())&&(ui->caa->isChecked()))
    {


        QSqlQueryModel *modele=new QSqlQueryModel();
         modele=p.afficherCatFour(ui->ca->currentText(),ui->fo->currentText());
         ui->tableView->setModel(modele);



    }


    else if ((ui->rech->text()=="")&&(ui->foo->isChecked()==false)&&(ui->caa->isChecked()==false))
    {
        QSqlQueryModel *modele=new QSqlQueryModel();
         modele=p.afficher();
         ui->tableView->setModel(modele);

    }
}


