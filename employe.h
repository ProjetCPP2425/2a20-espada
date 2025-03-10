#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "em.h"
#include <QMainWindow>


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
