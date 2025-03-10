#ifndef EDITEMPLOYEEDIALOG_H
#define EDITEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class EditEmployeeDialog;
}

class EditEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployeeDialog(QWidget *parent = nullptr);
    ~EditEmployeeDialog();

    // Set employee data in the dialog
    void setEmployeeData(QString nom, QString prenom, QString email, int telephone, QString specialite, int exp, QString dispo, QString log, QString mdp);

    // Get updated employee data from the dialog
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    int getTelephone() const;
    QString getSpecialite() const;
    int getExperience() const;
    QString getDisponibilite() const;
    QString getLogin() const;
    QString getMdp() const;

    // Store the ID internally
    void setID(int id);
    int getID() const;

private slots:
    void on_saveButton_clicked(); // Slot for the "Save" button
    void on_cancelButton_clicked(); // Slot for the "Cancel" button

private:
    Ui::EditEmployeeDialog *ui;
    int employeeID; // Store the ID of the employee being edited
};

#endif // EDITEMPLOYEEDIALOG_H
