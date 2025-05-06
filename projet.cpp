#include "projet.h"
#include "ui_projet.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include "buttondelegate.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextEdit>          // For QTextEdit widget
#include <QJsonObject>        // For QJsonObject
#include <QJsonArray>         // For QJsonArray
#include <QJsonDocument>      // For QJsonDocument
#include <QNetworkAccessManager>  // For QNetworkAccessManager
#include <QNetworkRequest>    // For QNetworkRequest
#include <QNetworkReply>
#include <QTimer>
#include <QScopedPointer>


const QString HF_API_TOKEN = "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";

Projet::Projet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::projet),
    m_networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Initialize Arduino
    arduino = new Arduino(this);
    setupArduinoConnection();

    ui->tableView->setModel(pro.afficher());

    // Set up button delegates
    ButtonDelegate *buttonDelegate = new ButtonDelegate(this);
    ui->tableView->setItemDelegateForColumn(6, buttonDelegate);
    ui->tableView->setItemDelegateForColumn(7, buttonDelegate);

    // Connect signals
    connect(buttonDelegate, &ButtonDelegate::deleteButtonClicked,
            this, &Projet::on_pushButton_supprimer_clicked);
    connect(buttonDelegate, &ButtonDelegate::editButtonClicked,
            this, &Projet::on_pushButton_modifier_clicked);

    connect(ui->pushButton_14, &QPushButton::clicked, this, &Projet::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Projet::on_pushButton_search_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &Projet::on_pushButton_pdf_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &Projet::on_pushButton_statistiques_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Projet::on_pushButton_up_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &Projet::on_pushButton_down_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &Projet::openChatbot);
    if (!m_networkManager) {
        qCritical() << "Failed to initialize network manager";
    }



    // Adjust column widths
    ui->tableView->resizeColumnsToContents();
}

Projet::~Projet()
{
    delete ui;
    if (!m_chatbotDialog.isNull()) {
        m_chatbotDialog->deleteLater();
    }
}

