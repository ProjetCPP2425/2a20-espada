#ifndef FORMATIONMAINWINDOW_H
#define FORMATIONMAINWINDOW_H

#include <QMainWindow>
#include "formation.h"
#include "buttondelegate.h"
#include "editformationdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FormationMainWindow; }
QT_END_NAMESPACE

class FormationMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FormationMainWindow(QWidget *parent = nullptr);
    ~FormationMainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void onDeleteButtonClicked(const QModelIndex &index);
    void onEditButtonClicked(const QModelIndex &index);
    void on_pushButton_rechercher_clicked();
    void on_pdf_clicked();
    void on_statbutton_clicked();


private:
    Ui::FormationMainWindow *ui;
    Formation Ftmp;
};
#endif // FORMATIONMAINWINDOW_H
