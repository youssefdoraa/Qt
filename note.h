#ifndef NOTE_H
#define NOTE_H

#include <QWidget>

namespace Ui {
class Note ;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    void modifier();
    explicit Note(QWidget *parent = 0,QString ref="");

    ~Note();



private slots:

void on_ok_clicked();





void on_pushButton_2_clicked();

private:
    Ui::Note *ui;
    QString ref;

};

#endif // NOTE_H
