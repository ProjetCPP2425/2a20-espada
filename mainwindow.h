#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rendezvous.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_updateRDV_clicked();
    void on_addRDV_clicked();
    void on_suppRDV_clicked();
    void on_tab_affichage_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    RendezVous rdv;
};

#endif // MAINWINDOW_H

