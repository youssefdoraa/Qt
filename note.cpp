#include "note.h"
#include "ui_note.h"
#include<QDebug>
#include <QSqlQuery>
#include"gestionproduit.h"

Note::Note(QWidget *parent,QString ref) :
    QWidget(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
    this->ref=ref;
}

void Note::modifier()
{ QString q="";
    if (ui->bon->isChecked())
        {
            q="bon";
        }
    else if (ui->moyen->isChecked())
        {
            q="moyen";
        }
    else if (ui->mauvais->isChecked())
        {
            q="mauvais";
        }


    QSqlQuery qr;

     qr.prepare("update PRODUIT set note=? where reference=?");
     qr.addBindValue(q);
     qr.addBindValue(this->ref);

     qr.exec();


}

Note::~Note()
{
    delete ui;
}



void Note::on_ok_clicked()
{
    modifier();

    this->close();


}


void Note::on_pushButton_2_clicked()
{
    this->close();
}
