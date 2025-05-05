#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rendezvous.h"
#include "Arduino_RDV.h"
//#include "tableexample.h"
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
    void on_tab_affichageRDV_clicked(const QModelIndex &index );
//void handleSerialData();

// metiers simples
    void on_rechercherRDV_textChanged(const QString &text);

    void on_pdfRDV_clicked();

    void on_modeRDV_2_clicked();

    void on_dateRDV_2_clicked();

    void on_statbuttonRDV_clicked();
// metiers avancés

    void checkUpcomingRdvNotification();
    void updateRdvButton();

    void on_btnRdvJour_clicked();

   void handleSerialData();

    void on_calander_rdv_clicked(const QDate &date);

    void on_calenderierRDV_clicked();

private:
    Ui::MainWindow *ui;
    RendezVous rdv;
RendezVous* r_tmp;
    QByteArray data; // variable contenant les données reçues

    Arduino_RDV A; // objet temporaire
      //TableExample *calendarWidget;
};

#endif // MAINWINDOW_H

