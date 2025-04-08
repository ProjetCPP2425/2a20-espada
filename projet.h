#ifndef PROJET_H
#define PROJET_H

#include <QMainWindow>
#include <QModelIndex>
#include "projets.h"
#include "qchartview.h"


namespace Ui {
class projet;
}

class Projet : public QMainWindow
{
    Q_OBJECT

public:
    explicit Projet(QWidget *parent = nullptr);  // Constructor
    ~Projet();  // Destructor
    QMap<QString, int> getStatusCounts();

private slots:
    void on_pushButton_ajouter_clicked();  // Slot for "Ajouter" button
    void on_pushButton_supprimer_clicked(const QModelIndex &index);  // Slot for "Supprimer" button
    void on_pushButton_modifier_clicked(const QModelIndex &index);
    void on_pushButton_search_clicked();
    void on_pushButton_pdf_clicked();
    void generateStatistiques();
    void drawStatistiquesChart(const QMap<QString, double> &statusPercentages);
    void on_pushButton_up_clicked();  // Sort ascending
    void on_pushButton_down_clicked();  // Sort descending

private:
    Ui::projet *ui;  // Pointer to the UI
    Projets pro;
    bool isEditMode = false;  // Flag to track whether you're in edit mode or add mode
    int currentProjectId = -1;    // Assuming Projets is a class for managing project data
    void generatePdf(const QSqlQueryModel *model);
    void on_pushButton_statistiques_clicked();
    QChartView *chartView;

};

#endif // PROJET_H

/*
 *
 *
 *
#ifndef PROJET_H
#define PROJET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class projet;
}
QT_END_NAMESPACE

class projet : public QMainWindow
{
    Q_OBJECT

public:
    projet(QWidget *parent = nullptr);
    ~projet();

private:
    Ui::projet *ui;
};
#endif // PROJET_H




*/
