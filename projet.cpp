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

void Projet::on_pushButton_ajouter_clicked() {
    QString nom_projet = ui->lineEdit_2->text().trimmed();
    QString description = ui->lineEdit_10->text().trimmed();
    QString date_debut = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString date_fin = ui->dateEdit_2->date().toString("dd/MM/yyyy");
    QString statue = ui->lineEdit_9->text().trimmed();

    // Date validation
    QDate debutDate = ui->dateEdit->date();
    QDate finDate = ui->dateEdit_2->date();

    if (finDate < debutDate) {
        QMessageBox::warning(this, tr("Warning"), tr("End date cannot be before start date!"));
        return;
    }


    if (nom_projet.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty() || statue.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("Please fill all fields!"));
        return;
    }

    if (isEditMode) {
        // In Edit Mode, update the existing project
        if (pro.modifier(currentProjectId, nom_projet, description, date_debut, statue, date_fin)) {
            QMessageBox::information(this, tr("Success"), tr("Project updated successfully!"));
            ui->tableView->setModel(pro.afficher());  // Refresh the table view
            isEditMode = false;  // Reset to Add mode after editing
            currentProjectId = -1;  // Clear the project ID
            ui->pushButton_14->setText("Add");  // Change button text back to "Add"

            // Clear the input fields after updating
            ui->lineEdit_2->clear();
            ui->lineEdit_10->clear();
            ui->dateEdit->clear();
            ui->dateEdit_2->clear();
            ui->lineEdit_9->clear();
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to update project!"));
        }
    } else {
        // In Add Mode, add a new project
        Projets p(0, nom_projet, description, date_debut, date_fin, statue, 1);
        if (p.ajouter()) {
            QMessageBox::information(this, tr("Success"), tr("Project added successfully!"));
            ui->tableView->setModel(pro.afficher());  // Refresh the table view

            // Clear the input fields after adding
            ui->lineEdit_2->clear();
            ui->lineEdit_10->clear();
            ui->dateEdit->clear();
            ui->dateEdit_2->clear();
            ui->lineEdit_9->clear();
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to add project!"));
        }
    }
}



void Projet::on_pushButton_supprimer_clicked(const QModelIndex &index)
{
    int id_projet = index.siblingAtColumn(0).data().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirm Delete"),
                                  tr("Are you sure you want to delete this project?"),
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (pro.supprimer(id_projet)) {
            QMessageBox::information(this, tr("Success"), tr("Project deleted successfully!"));

            // Manually update the table view here
            ui->tableView->setModel(pro.afficher());  // Refresh the table with new data
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to delete project!"));
        }
    }
}

void Projet::on_pushButton_modifier_clicked(const QModelIndex &index) {
    int id_projet = index.siblingAtColumn(0).data().toInt();
    QString nom_projet = index.siblingAtColumn(1).data().toString();
    QString description = index.siblingAtColumn(2).data().toString();
    QString date_debut = index.siblingAtColumn(3).data().toString();
    QString date_fin = index.siblingAtColumn(4).data().toString();
    QString statue = index.siblingAtColumn(5).data().toString();

    // Convert dates from database format to display format
    QDate db_debut = QDate::fromString(date_debut, "yyyy-MM-dd");
    QDate db_fin = QDate::fromString(date_fin, "yyyy-MM-dd");

    ui->lineEdit_2->setText(nom_projet);
    ui->lineEdit_10->setText(description);
    ui->dateEdit->setDate(db_debut);
    ui->dateEdit_2->setDate(db_fin);
    ui->lineEdit_9->setText(statue);

    isEditMode = true;
    currentProjectId = id_projet;
    ui->pushButton_14->setText("Update");
}


void Projet::on_pushButton_search_clicked()
{
    QString searchTerm = ui->lineEdit->text().trimmed();

    // Call the recherche function and update the table view with search results
    if (!searchTerm.isEmpty()) {
        ui->tableView->setModel(pro.recherche(searchTerm));
    } else {
        // If the search box is empty, you can either leave the table as it is
        // or refresh it with the full list of projects.
        ui->tableView->setModel(pro.afficher());
    }
}

void Projet::generatePdf(const QSqlQueryModel *model)
{
    // Open file dialog to get the save location
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty()) {
        return;  // User canceled the save dialog
    }

    // Create a QPdfWriter instance to write to a PDF file
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);  // Set the page size to A4

    // Create a QTextDocument to hold the content
    QTextDocument document;

    // Set the document's font (you can change it based on your preferences)
    QFont font("Arial", 12);
    document.setDefaultFont(font);

    // Prepare content for the PDF in HTML format
    QString htmlContent = "<h1 style='text-align:center;'>Project List</h1>";
    htmlContent += "<table style='width:100%; border: 1px solid black; border-collapse: collapse;'>";
    htmlContent += "<tr><th>ID</th><th>Name</th><th>Description</th><th>Status</th></tr>";

    // Loop through each row in the model and create an HTML table row
    for (int row = 0; row < model->rowCount(); ++row) {
        htmlContent += "<tr>";

        // Get the values of each column in the row
        for (int column = 0; column < model->columnCount(); ++column) {
            htmlContent += "<td style='border: 1px solid black; padding: 5px;'>"
                           + model->data(model->index(row, column)).toString()
                           + "</td>";
        }

        htmlContent += "</tr>";
    }

    htmlContent += "</table>";

    // Set the HTML content to the QTextDocument
    document.setHtml(htmlContent);

    // Render the document to the PDF writer
    document.print(&writer);

    // Notify the user that the PDF was generated
    QMessageBox::information(this, "PDF Generated", "The PDF file has been generated successfully.");
}

void Projet::on_pushButton_pdf_clicked()
{
    // Get the model from the table view
    QSqlQueryModel *model = static_cast<QSqlQueryModel *>(ui->tableView->model());

    // Call the PDF generation function
    if (model) {
        generatePdf(model);
    } else {
        QMessageBox::warning(this, "No Data", "There is no data to generate the PDF.");
    }
}


void Projet::generateStatistiques()
{
    // Get the counts of each status
    QMap<QString, int> statusCounts = getStatusCounts();

    // Calculate the total number of projects
    int totalProjects = 0;
    for (const auto& item : statusCounts) {
        totalProjects += item;  // item is an integer representing the count
    }

    // Avoid division by zero if no projects are present
    if (totalProjects == 0) {
        qDebug() << "No projects found.";
        return;
    }

    // Calculate and display the percentage for each status
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        QString status = it.key();  // Get the key (status)
        int count = it.value();     // Get the value (count)
        double percentage = (count / static_cast<double>(totalProjects)) * 100;

        // Debug output to check the calculated percentages
        qDebug() << "Status:" << status << "Count:" << count << "Percentage:" << percentage << "%";
    }
}


void Projet::drawStatistiquesChart(const QMap<QString, double> &statusPercentages)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up the pen and brush for drawing the chart
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::blue));  // Default color for "En cours"

    // Get the center and radius of the circle
    int radius = 100;
    int centerX = width() / 2;
    int centerY = height() / 2;

    // Initialize start angle for the first sector
    int startAngle = 90 * 16;  // 90 degrees in 1/16th degree units

    // Loop through each status and draw the sectors
    for (auto it = statusPercentages.begin(); it != statusPercentages.end(); ++it) {
        double percentage = it.value();
        int spanAngle = (360 * percentage / 100) * 16;  // Convert percentage to angle (in 1/16th degree units)

        if (it.key() == "En cours") {
            painter.setBrush(QBrush(Qt::yellow));  // Color for "En cours"
        } else if (it.key() == "Terminé") {
            painter.setBrush(QBrush(Qt::green));  // Color for "Terminé"
        } else if (it.key() == "Annulé") {
            painter.setBrush(QBrush(Qt::red));  // Color for "Annulé"
        }

        // Draw the pie slice for this status
        painter.drawPie(centerX - radius, centerY - radius, 2 * radius, 2 * radius, startAngle, spanAngle);

        // Update the start angle for the next sector
        startAngle += spanAngle;
    }

    // Draw the percentages text in the center
    painter.setPen(QPen(Qt::black));
    painter.setFont(QFont("Arial", 14, QFont::Bold));

    // Display the percentage text in the center
    painter.drawText(centerX - 50, centerY + 20, "Statistics");
}

void Projet::on_pushButton_statistiques_clicked()
{
    // Create a dialog to display the chart
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Project Statistics");
    chartDialog->resize(600, 500);

    QVBoxLayout *layout = new QVBoxLayout(chartDialog);

    // Fetch status counts and calculate percentages
    QMap<QString, int> statusCounts = getStatusCounts();
    int totalProjects = 0;
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        totalProjects += it.value();
    }

    if (totalProjects == 0) {
        QMessageBox::information(this, "No Data", "No projects found for statistics.");
        delete chartDialog;
        return;
    }

    QPieSeries *series = new QPieSeries();
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        double percentage = (it.value() / static_cast<double>(totalProjects)) * 100;
        QPieSlice *slice = series->append(it.key() + ": " + QString::number(percentage, 'f', 1) + "%", percentage);
        slice->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Project Status Statistics");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    chartDialog->exec();
    delete chartDialog;
}



QMap<QString, int> Projet::getStatusCounts() {
    QSqlQuery query;
    query.prepare("SELECT STATUT, COUNT(*) FROM PROJET GROUP BY STATUT");
    query.exec();

    QMap<QString, int> statusCounts;
    while (query.next()) {
        QString statut = query.value(0).toString();
        int count = query.value(1).toInt();
        statusCounts[statut] = count;
    }
    return statusCounts;
}


void Projet::on_pushButton_up_clicked()
{
    ui->tableView->setModel(pro.afficherSortedAsc());
    ui->tableView->resizeColumnsToContents();
}

void Projet::on_pushButton_down_clicked()
{
    ui->tableView->setModel(pro.afficherSortedDesc());
    ui->tableView->resizeColumnsToContents();
}
void Projet::openChatbot()
{
    if (m_chatbotDialog.isNull()) {
        initializeChatbotUI();
    }
    m_chatbotDialog->show();
    m_chatbotDialog->raise();
    m_chatbotDialog->activateWindow();
}

// Initialize chatbot UI components
void Projet::initializeChatbotUI()
{
    m_chatbotDialog = new QDialog(this);
    m_chatbotDialog->setWindowTitle("AI Assistant");
    m_chatbotDialog->setMinimumSize(400, 500);

    QVBoxLayout *mainLayout = new QVBoxLayout(m_chatbotDialog);

    // Chat display area
    m_chatDisplay = new QTextEdit(m_chatbotDialog);
    m_chatDisplay->setReadOnly(true);
    mainLayout->addWidget(m_chatDisplay);

    // Input area
    QHBoxLayout *inputLayout = new QHBoxLayout();
    m_messageInput = new QLineEdit(m_chatbotDialog);
    QPushButton *sendButton = new QPushButton("Send", m_chatbotDialog);
    inputLayout->addWidget(m_messageInput);
    inputLayout->addWidget(sendButton);
    mainLayout->addLayout(inputLayout);

    // Connections
    connect(sendButton, &QPushButton::clicked, this, &Projet::handleSendMessage);
    connect(m_messageInput, &QLineEdit::returnPressed, this, &Projet::handleSendMessage);

    // Welcome message
    showChatMessage("Assistant", "Hello! How can I help you today?");
}

// Handle send button click
void Projet::handleSendMessage()
{
    if (m_messageInput.isNull()) return;

    QString message = m_messageInput->text().trimmed();
    if (message.isEmpty()) return;

    showChatMessage("You", message);
    m_messageInput->clear();

    sendToChatbotAPI(message);
}

// Send message to chatbot API
void Projet::sendToChatbotAPI(const QString &message)
{
    if (!m_networkManager) {
        showError("Network service unavailable");
        return;
    }

    const QString apiKey = "Bearer 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";
    if (apiKey.contains("your_actual_api_key")) {
        showError("API key not configured");
        return;
    }

    QUrl apiUrl("https://api-inference.huggingface.co/models/facebook/blenderbot-3B");
    QNetworkRequest request(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", apiKey.toUtf8());

    QJsonObject payload;
    payload["inputs"] = message;
    payload["parameters"] = QJsonObject{
        {"max_length", 150},
        {"temperature", 0.7},
        {"wait_for_model", true}
    };

    QNetworkReply *reply = m_networkManager->post(request, QJsonDocument(payload).toJson());

    // Set timeout
    QTimer::singleShot(30000, reply, &QNetworkReply::abort);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        this->handleNetworkReply(reply);
    });
}

// Handle network response
void Projet::handleNetworkReply(QNetworkReply *reply)
{
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response);

        if (!json.isNull() && json.isArray()) {
            QString replyText = json.array().first().toString();
            showChatMessage("Assistant", replyText);
        } else {
            showError("Invalid response format");
        }
    } else {
        showError(QString("Network error: %1").arg(reply->errorString()));
    }

    reply->deleteLater();
}

// Display message in chat
void Projet::showChatMessage(const QString &sender, const QString &message)
{
    if (!m_chatDisplay.isNull()) {
        m_chatDisplay->append(QString("<b>%1:</b> %2").arg(sender, message));
    }
}

// Display error message
void Projet::showError(const QString &error)
{
    qDebug() << "Error:" << error;
    if (!m_chatDisplay.isNull()) {
        m_chatDisplay->append(QString("<font color='red'>Error: %1</font>").arg(error));
    }
}
