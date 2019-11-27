#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include <QDialog>

namespace Ui {
class commentaire;
}

class commentaire : public QDialog
{
    Q_OBJECT

public:
    void modifier();
    explicit commentaire(QWidget *parent = 0,QString ref="");
    ~commentaire();

private slots:
    void on_ok_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::commentaire *ui;
    QString ref;

};

#endif // COMMENTAIRE_H
