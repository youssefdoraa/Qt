#include "depot1.h"
#include "ui_depot1.h"
#include"connexion.h"
#include"class_client.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QSqlError>
#include<iostream>
#include"produit1.h"
//#include"statclient.h"
#include <QMessageBox>
depot1::depot1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::depot1)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    class_client c;
    QSqlQueryModel * model=new QSqlQueryModel();
    model=c.afficher();
    ui->tableView->setModel(model);
    if(model->lastError().isValid())
    {
        qDebug()<<model->lastError();
        ui->tableView->show();
    }


}

depot1::~depot1()
{
    delete ui;
}

void depot1::on_ajouter_clicked()
{
    if(legalInput()==""){
   class_client c;
     c.set_cin(ui->cin->text());
     c.set_nomclient(ui->nomclient->text());
     c.set_adresse(ui->adresse->text());
     c.set_telephone(ui->telephone->text());
     c.set_email(ui->email->text());
     c.set_profession(ui->profession->text());
     c.set_age(ui->age->text().toInt());
     c.set_dateN(ui->dateEdit->text());
     c.ajouter();

     QSqlQueryModel * model=new QSqlQueryModel();
     model=c.afficher();
     ui->tableView->setModel(model);
     if(model->lastError().isValid())
     {
         qDebug()<<model->lastError();
         ui->tableView->show();
     }
     ui->cin->clear();
     ui->nomclient->clear();
     ui->adresse->clear();
     ui->telephone->clear();
     ui->email->clear();
     ui->profession->clear();
     ui->age->clear();
     ui->point->clear();
     ui->dateEdit->clear();


}else {
        QMessageBox::critical(this,"erreur",legalInput());
    }
}

void depot1::on_modifier_clicked()
{
     class_client  c;
     c.set_cin(ui->cin->text());
     c.set_nomclient(ui->nomclient->text());
     c.set_adresse(ui->adresse->text());
     c.set_telephone(ui->telephone->text());
     c.set_profession(ui->profession->text());
     c.set_email(ui->email->text());
     c.set_point(ui->point->text().toInt());
     c.set_age(ui->age->text().toInt());
     c.set_dateN(ui->dateEdit->text());
     c.modifier();
     QSqlQueryModel * model=new QSqlQueryModel();
     model=c.afficher();
     ui->tableView->setModel(model);
     if(model->lastError().isValid())
     {
         qDebug()<<model->lastError();
         ui->tableView->show();
     }
     ui->cin->clear();
     ui->nomclient->clear();
     ui->adresse->clear();
     ui->telephone->clear();
     ui->email->clear();
     ui->profession->clear();
     ui->age->clear();
     ui->point->clear();
     ui->dateEdit->clear();
}

void depot1::on_supprimer_clicked()
{
    class_client c;
    c.set_cin(ui->cin->text());
    c.supprimer();
    QSqlQueryModel * model=new QSqlQueryModel();
    model=c.afficher();
    ui->tableView->setModel(model);
    if(model->lastError().isValid())
    {
        qDebug()<<model->lastError();
        ui->tableView->show();
    }
    ui->cin->clear();
    ui->nomclient->clear();
    ui->adresse->clear();
    ui->telephone->clear();
    ui->email->clear();
    ui->profession->clear();
    ui->age->clear();
    ui->point->clear();
    ui->dateEdit->clear();
}


void depot1::on_pushButton_clicked()
{
    class_client  c;
    QSqlQueryModel * model=new QSqlQueryModel();
    model=c.afficher();
    ui->tableView->setModel(model);
    if(model->lastError().isValid())
    {
        qDebug()<<model->lastError();
        ui->tableView->show();
    }
}

void depot1::on_fideliser_clicked()
{
    QSqlQuery q;
    QString f;
    q.prepare("select nomclient from client where nbpoint > 80");
    q.exec();
    while(q.next())
    {
         f=q.value(0).toString();
    }




    this->close();
    QString message;
    message="le client " +f+ " a depassé 80pt. veuillez l'envoyer un mail pour informer de transformation des points";
   if(f!="")
   {
    QMessageBox::information( 0, tr( "notification" ), message  );
   }



}

void depot1::on_tableView_clicked(const QModelIndex &index)
{
        QString v=ui->tableView->selectionModel()->selectedIndexes().at(0).data().toString();
        ui->nomclient->setText(v);
         v=ui->tableView->selectionModel()->selectedIndexes().at(1).data().toString();
          ui->cin->setText(v);
          v=ui->tableView->selectionModel()->selectedIndexes().at(2).data().toString();
         ui->adresse->setText(v);
         v=ui->tableView->selectionModel()->selectedIndexes().at(3).data().toString();
          ui->email->setText(v);
          v=ui->tableView->selectionModel()->selectedIndexes().at(4).data().toString();
           ui->telephone->setText(v);
           v=ui->tableView->selectionModel()->selectedIndexes().at(5).data().toString();
            ui->profession->setText(v);
          v=ui->tableView->selectionModel()->selectedIndexes().at(6).data().toString();
            ui->age->setText(v);
            v=ui->tableView->selectionModel()->selectedIndexes().at(7).data().toString();
             ui->point->setText(v);
             QDate k=ui->tableView->selectionModel()->selectedIndexes().at(8).data().toDate();
              ui->dateEdit->setDate(k);

}

/*void depot1::on_tableView_activated(const QModelIndex &index)
{
    QString v=ui->tableView->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from client where cin2='"+v+"'or nomclient='"+v+"' or adresse='"+v+"' or email='"+v+"' or telephone='"+v+"' or profession='"+v+"' or age='"+v+"' or nbpoint='"+v+"' or date_n='"+v+"' ");
    if(q.exec())
    {
        while(q.next())
        {

          ui->nomclient->setText(q.value(0).toString());
          ui->cin->setText(q.value(1).toString());
          ui->adresse->setText(q.value(2).toString());
          ui->email->setText(q.value(3).toString());
          ui->telephone->setText(q.value(4).toString());
          ui->profession->setText(q.value(5).toString());
          ui->age->setText(q.value(6).toString());
          ui->point->setText(q.value(7).toString());
          ui->dateEdit->setDate(q.value(8).toDate());
        }
    }
}*/

void depot1::on_rechercher_clicked()
{
    class_client c;

        QSqlQueryModel * model=new QSqlQueryModel();
        c.set_nomclient(ui->rech1->text());
        c.set_age(ui->rech->text().toInt());
        model=c.rechercher();
        ui->tableView->setModel(model);
        if(model->lastError().isValid())
        {
          qDebug()<<model->lastError();
          ui->tableView->show();
        }
}

QString depot1::legalInput(){
    QString s="";
    if(!legalNom()) s+="le nom non valide";
    if(!legalAddress())s+="\n l'addresse non valide";
    if(!legalCin())s+="\n la cin incorrect";
    if(!legalTel())s+="\n telephone incorrect";
    if(!legalWork())s+="\n profession incorrect\n";
    if(!legalEmail())s+="\n email incorrect\n"  ;
    return s;
}



bool depot1::legalNom(){
    QString s=ui->nomclient->text();
    QRegExp re("^[a-zA-Z ]+$");
return re.exactMatch(s);

}
bool depot1::legalCin(){
    QRegExp re("\\d+");
   return ( re.exactMatch(ui->cin->text()) && ui->cin->text().length()==8 );

}

bool depot1::legalTel(){
    QRegExp re("\\d+");
   return  (re.exactMatch(ui->telephone->text()) && ui->telephone->text().length()>=8);

}

bool depot1::legalAddress(){
    QRegExp adrex("[0-9]{1,4}\\-[a-zA-Z]{3,20}\\.[a-zA-Z]{3,20}");
    return adrex.exactMatch(ui->adresse->text());
}

bool depot1::legalWork(){
    QString s=ui->profession->text();
    QRegExp re("^[a-zA-Z ]+$");
return re.exactMatch(s);

}
bool depot1::legalEmail(){
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);
    return mailREX.exactMatch(ui->email->text());
}

void depot1::on_radioButton_clicked()
{
    depot1* m=new depot1;
    m->show();
    this->close();
}

void depot1::on_statistiques_clicked()
{
    /*
 statclient *d=new statclient;

 d->show();
 //this->close();
 */
}
