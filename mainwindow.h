#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rendezvous.h"
#include "Arduino_RDV.h"
#include "arduino.h"
#include "smssender.h"
//hammmaaaaaaaaaaaaaa

#include "arduino_employe.h"
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
#include <QStyledItemDelegate>
#include <QPushButton>
#include <QApplication>
#include <QMouseEvent>
#include <QMainWindow>
#include <QModelIndex>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextEdit>
#include <QLineEdit>
#include <QDialog>
#include <QPointer>
//#include "tableexample.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//hammmmaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// ButtonDelegate class
class ButtonDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ButtonDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
    //QVBoxLayout *rdvbox;


signals:
    void deleteButtonClicked(const QModelIndex &index);
    void editButtonClicked(const QModelIndex &index);

private:
    QPushButton *deleteButton;
    QPushButton *editButton;
};

// EditEmployeeDialog class
namespace Ui {
class EditEmployeeDialog;
}

class EditEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployeeDialog(QWidget *parent = nullptr);
    ~EditEmployeeDialog();


    void setEmployeeData(QString nom, QString prenom, QString email, int telephone, QString specialite, int exp, QString dispo, QString log, QString mdp);
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    int getTelephone() const;
    QString getSpecialite() const;
    int getExperience() const;
    QString getDisponibilite() const;
    QString getLogin() const;
    QString getMdp() const;
    void setID(int id);
    int getID() const;

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::EditEmployeeDialog *ui;
    int employeeID;
};
//hammaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setRdvBoxVisible(bool visible);
    void setEmpBoxVisible(bool visible);
    void setClientBoxVisible(bool visible);
    void setResBoxVisible(bool visible);
    void setprojetBoxVisible(bool visible);
    QMap<QString, int> getStatusCounts();

private slots:
    void on_updateRDV_clicked();
    void on_addRDV_clicked();
    void on_suppRDV_clicked();
    void on_tab_affichageRDV_clicked(const QModelIndex &index );
    //hammaaaaaaaaaaaaa
    void on_pushButton_ajouterEMP_clicked();
    void onDeleteButtonClicked(const QModelIndex &index);
    void onEditButtonClicked(const QModelIndex &index);
    void on_lineEditEMP_textChanged(const QString &arg1);
    void on_dispoSortButton_clicked();
    void on_emailSortButton_clicked();
    void on_telephoneSortButton_clicked();
    void on_pdfButtonEMP_clicked();
    void on_statbuttonEMP_clicked();
    void on_logoutButton_clicked();
    void handleSerialData();
    //hammaaaaaaaaaaaaaaaaaaaaaaaaaa
    //feressssssss
    void on_pushButton_ajouter_2c_clicked();
    void on_pushButton_supprimer_2c_clicked();
    void on_pushButton_modifier_2c_clicked();
    void on_tableView_2c_clicked(const QModelIndex &index);
    void on_pushButton_search_mod_2c_clicked();
    void on_pushButton_pdf_2c_clicked();
    void on_rechercher_2c_textChanged(const QString &text);
    void on_trier_nom_2c_clicked();
    void on_trier_date_2c_clicked();
    void on_trier_type_2c_clicked();
    void on_pushbutton_6c_clicked();

    //fereeeeessss
    //moataz
    void on_pushButton_confirmer_res_clicked();
    void on_pushButton_supprimerr_res_clicked();
    void on_pushButton_modifier_res_clicked();
    void on_pushButton_confirmermodification_res_clicked();
    void on_qrCodeButton_clicked();
    void on_statbutton_res_clicked();


    void on_quantite_2_clicked();

    void on_type_2_clicked();

    void on_rechercher_textChanged(const QString &text);

    //void on_generatePDFButton_clicked();


    void on_pdfButton_res_clicked();
    void on_pushButton_envoyer_res_clicked();


    //moataz
    //akram
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked(const QModelIndex &index);
    void on_pushButton_modifier_clicked(const QModelIndex &index);
    void on_pushButton_search_clicked();
    void on_pushButton_pdf_clicked();
    void generateStatistiques();
    void drawStatistiquesChart(const QMap<QString, double> &statusPercentages);
    void on_pushButton_up_clicked();
    void on_pushButton_down_clicked();
    void openChatbot();
    void on_pushButton_statistiques_clicked();
    void handleSendMessage();
    void handleNetworkReply(QNetworkReply *reply);
    //akram
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

  // void handleSerialData();

    void on_calander_rdv_clicked(const QDate &date);

    void on_calenderierRDV_clicked();

private:
    Ui::MainWindow *ui;
    RendezVous rdv;
     QVBoxLayout *rdvbox;
RendezVous* r_tmp;
    QByteArray data; // variable contenant les données reçues

    Arduino_RDV A; // objet temporaire
      //TableExample *calendarWidget;
    //hammaaaaaaaaaaaaaaaaa
    em Etmp;
    bool isValidName(const QString& name) const;
    bool isValidEmail(const QString& email) const;
    bool isValidPhone(int phone) const;
    bool isValidExperience(int experience) const;
    bool isValidPassword(const QString& password) const;
    Arduino_EMPLOYE emp;
    //hammaaaaaaaaaaaaaaaaaaaaa

    //ferrrreesss
    Clients cli;
    Arduino *arduino;
    QString originalEmpId;
    QString originalEmpName;

    void populateEmployeeComboBox();
    void populateTypeComboBox();
    void populateSpecialiteComboBox();
    void setupArduinoConnection();

    //ferrrreeeesssss

    //moataz
    ressource R;
    bool isValidInput();
    QNetworkAccessManager *manager;
    void onSMSResponseReceived(QNetworkReply* reply);
    bool envoyerSMS(const QString& numero, const QString& message);

    //moataz
    //akram
    Projets pro;
    bool isEditMode = false;
    int currentProjectId = -1;
    ButtonDelegate *buttonDelegate;
    QPointer<QDialog> m_chatbotDialog;
    QPointer<QTextEdit> m_chatDisplay;
    QNetworkAccessManager* m_chatbotManager;
    void queryChatbotAPI(const QString& message);
    void generatePdf(const QSqlQueryModel *model);
    QPointer<QLineEdit> m_messageInput;
    void initializeChatbot();
    QPointer<QNetworkAccessManager> m_networkManager;
    void showError(const QString &error);
    void showChatMessage(const QString &sender, const QString &message);
    void initializeChatbotUI();
    void sendToChatbotAPI(const QString &message);
    //akram
};

#endif // MAINWINDOW_H

