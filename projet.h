#ifndef PROJET_H
#define PROJET_H

#include <QMainWindow>
#include <QModelIndex>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextEdit>
#include <QLineEdit>
#include <QDialog>
#include <QPointer>
#include "projets.h"
#include "buttondelegate.h"

namespace Ui {
class projet;
}

class Projet : public QMainWindow
{
    Q_OBJECT

public:
    explicit Projet(QWidget *parent = nullptr);
    ~Projet();
    QMap<QString, int> getStatusCounts();

private slots:
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
    void handleSendMessage();  // Add this declaration$;
    void handleNetworkReply(QNetworkReply *reply);

private:
    Ui::projet *ui;
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

};

#endif // PROJET_H
