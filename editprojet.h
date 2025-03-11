#ifndef EDITPROJET_H
#define EDITPROJET_H

#include <QDialog>

namespace Ui {
class Editprojet;
}

class Editprojet : public QDialog
{
    Q_OBJECT

public:
    explicit Editprojet(QWidget *parent = nullptr);
    ~Editprojet();

    // Set
    void setProjectData(QString nom_projet, QString description, QString date_debut, QString date_fin, QString statue);

    // Get updated
    QString getNom() const;
    QString getDescription() const;
    QString getDate_Debut() const;
    QString getDate_Fin() const;
    QString getStatue() const;
    // Store the ID internally
    void setID(int id);
    int getID() const;

private slots:
    void on_saveButton_clicked(); // Slot for the "Save" button
    void on_cancelButton_clicked(); // Slot for the "Cancel" button

private:
    Ui::Editprojet *ui;
    int projetID;
};


#endif // EDITPROJET_H
