#ifndef PROJET_H
#define PROJET_H
#include "projets.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class projet;
}
QT_END_NAMESPACE

class Projet : public QMainWindow
{
    Q_OBJECT

public:
    Projet(QWidget *parent = nullptr);
    ~Projet();


public slots :

    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked(const QModelIndex &index);

private:
    Ui::projet *ui;
    Projets pro;
};
#endif // PROJET_H
