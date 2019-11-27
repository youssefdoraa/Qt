#include "commentaire.h"
#include "ui_commentaire.h"
#include"QSqlQuery"

void commentaire::modifier()
{
    QString q="";

    q=ui->textEdit->toPlainText();


        QSqlQuery qr;

         qr.prepare("update PRODUIT set commentaire=? where reference=?");
         qr.addBindValue(q);
         qr.addBindValue(this->ref);

         qr.exec();
}

commentaire::commentaire(QWidget *parent,QString ref) :
    QDialog(parent),
    ui(new Ui::commentaire)
{
    ui->setupUi(this);
    this->ref=ref;
}

commentaire::~commentaire()
{
    delete ui;
}

void commentaire::on_ok_clicked()
{
    modifier();
    this->close();
}

void commentaire::on_pushButton_2_clicked()
{
    this->close();
}
