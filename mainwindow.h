#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "depot1.h"
#include "class_produit1E.h"
#include "gestionproduit.h"
#include "note.h"
#include "commentaire.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
