#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clients.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class client;
}
QT_END_NAMESPACE

class client : public QMainWindow
{


    Q_OBJECT

public:

    client(QWidget *parent = nullptr);
    ~client();

public slots :

    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();

private:
    Ui::client *ui;
    Clients cli ;

private slots:
    void on_tableView_clicked(const QModelIndex &index);

};


#endif // MAINWINDOW_H
