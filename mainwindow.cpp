#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "gestionproduit.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
//ui->gestionproduit->setModel(tmpproduit.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Produit e/*(d,nom,prenom)*/;
  //bool test=Produit.ajouterProduit();

//{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


  /*else{
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}*/}

void MainWindow::on_pb_supprimer_clicked()
{ Produit e ;
int id = ui->lineEdit_id->text().toInt();
bool test=e.supprimerProduit();
if(test)
{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                QObject::tr("produit supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
