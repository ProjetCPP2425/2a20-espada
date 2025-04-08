#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ressource.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_confirmer_clicked();
    void on_pushButton_supprimerr_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_confirmermodification_clicked();


    void on_statbutton_clicked();


    void on_quantite_2_clicked();

    void on_type_2_clicked();

    void on_rechercher_textChanged(const QString &text);

    void on_generatePDFButton_clicked();


    void on_pdfButton_clicked();

private:
    Ui::MainWindow *ui;
    ressource R;
    bool isValidInput();
};

#endif // MAINWINDOW_H
