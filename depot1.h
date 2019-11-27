#ifndef depot1_H
#define depot1_H

#include <QMainWindow>
//#include "mail2.h"
namespace Ui {
class depot1;
}

class depot1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit depot1(QWidget *parent = 0);
    ~depot1();

private slots:
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_fideliser_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    //void on_tableView_activated(const QModelIndex &index);

    void on_rechercher_clicked();


    void on_radioButton_clicked();

    void on_statistiques_clicked();

private:
    Ui::depot1 *ui;
    bool legalNom();
    bool legalCin();
    bool legalTel();
    bool legalAddress();
    bool legalWork();
    bool legalEmail();
    QString legalInput();

};

#endif // depot1_H
