#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ressource.h"
#include <QMainWindow>

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
    bool isValidInput();
public slots:
    void on_pushButton_confirmer_clicked();
    void on_pushButton_supprimerr_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_confirmermodification_clicked();


private:
    Ui::MainWindow *ui;

    ressource R;
};
#endif // MAINWINDOW_H
