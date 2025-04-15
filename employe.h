#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "em.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QtCharts>
#include <QSqlQuery>
#include <QTabWidget>
#include <QDialog>
#include <QVBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui {
class Employe;
}
QT_END_NAMESPACE

class Employe : public QMainWindow
{
    Q_OBJECT

public:
    Employe(QWidget *parent = nullptr);
    ~Employe();
private slots: // Ajout de "slots:"
    void on_pushButton_ajouter_clicked();
    void onDeleteButtonClicked(const QModelIndex &index);
    void onEditButtonClicked(const QModelIndex &index);


    void on_lineEdit_textChanged(const QString &arg1);
    void on_dispoSortButton_clicked();
    void on_emailSortButton_clicked();
    void on_telephoneSortButton_clicked();
    void on_pdfButton_clicked();
    void on_statbutton_clicked();

    void on_logoutButton_clicked();  // Add this line

private:
    Ui::Employe *ui;
    em Etmp;
    bool isValidName(const QString& name) const;
    bool isValidEmail(const QString& email) const;
    bool isValidPhone(int phone) const;
    bool isValidExperience(int experience) const;
    bool isValidPassword(const QString& password) const;


};
#endif // EMPLOYE_H
