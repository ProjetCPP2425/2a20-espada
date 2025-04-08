#ifndef EDITFORMATIONDIALOG_H
#define EDITFORMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class EditFormationDialog;
}

class EditFormationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditFormationDialog(QWidget *parent = nullptr);
    ~EditFormationDialog();

    void setFormationData(QString titre, QString description, QString date_debut, QString date_fin, int duree, float prix);

    QString getTitre() const;
    QString getDescription() const;
    QString getDateDebut() const;
    QString getDateFin() const;
    int getDuree() const;
    float getPrix() const;

    void setID(int id);
    int getID() const;

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_pushButton_ajouter_clicked();
private:
    Ui::EditFormationDialog *ui;
    int formationID;
};

#endif // EDITFORMATIONDIALOG_H
