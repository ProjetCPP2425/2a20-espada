#include "employe.h"
#include "ui_employe.h"
#include "em.h"
#include "buttondelegate.h"
#include "editemployeedialog.h"
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QSqlError>  // Include to check for SQL errors
#include <QDebug>
#include <QDesktopServices>
#include <QtCharts>
#include <QSqlQuery>
#include <QTabWidget>
#include <QDialog>
#include <QVBoxLayout>
Employe::Employe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Employe)
{
    ui->setupUi(this);
    connect(ui->pdfButton, &QPushButton::clicked, this, &Employe::on_pdfButton_clicked);
    connect(ui->statbutton,&QPushButton::clicked, this, &Employe::on_statbutton_clicked);
    ui->tableView->setModel(Etmp.afficher());
    // Hide the IDEMPLOYE column (column 0)
    ui->tableView->setColumnHidden(0, true);

    // Set the custom delegate for the buttons
    ButtonDelegate *buttonDelegate = new ButtonDelegate(this);
    ui->tableView->setItemDelegateForColumn(10, buttonDelegate); // Column 10: Supprimer
    ui->tableView->setItemDelegateForColumn(11, buttonDelegate); // Column 11: Modifier

    // Connect button signals to slots
    connect(buttonDelegate, &ButtonDelegate::deleteButtonClicked, this, &Employe::onDeleteButtonClicked);
    connect(buttonDelegate, &ButtonDelegate::editButtonClicked, this, &Employe::onEditButtonClicked);

    ui->tableView->resizeColumnsToContents();
}

Employe::~Employe()
{
    delete ui;
}

// Validation function for name (only alphabets)
bool Employe::isValidName(const QString& name) const {
    QRegularExpression regex("^[A-Za-z]+$");
    return regex.match(name).hasMatch();
}

// Validation function for email (must follow a valid email format)
bool Employe::isValidEmail(const QString& email) const {
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex.match(email).hasMatch();
}

// Validation function for phone (must be exactly 8 digits)
bool Employe::isValidPhone(int phone) const {
    QString phoneStr = QString::number(phone);
    QRegularExpression regex("^\\d{8}$");
    return regex.match(phoneStr).hasMatch();
}

// Validation function for experience (must be between 0 and 50)
bool Employe::isValidExperience(int experience) const {
    return experience >= 0 && experience <= 50;
}

// Validation function for password (must contain at least 1 uppercase, 3 digits, 1 special character, and be at least 8 characters long)
bool Employe::isValidPassword(const QString& password) const {
    QRegularExpression regex("^(?=.*[A-Z])(?=.*\\d{3,})(?=.*[!@#$%^&*])(?=.*[a-z]).{8,}$");
    return regex.match(password).hasMatch();
}

void Employe::on_pushButton_ajouter_clicked()
{
    QString NOM = ui->lineEdit_nom->text();
    QString PRENOM = ui->lineEdit_prenom->text();
    QString EMAIL = ui->lineEdit_email->text();
    QString SPECIALITE = ui->specialite->currentText();
    bool ok1, ok2;
    int TELEPHONE = ui->lineEdit_telephone->text().toInt(&ok1);
    int EXPERIENCE = ui->lineEdit_experience->text().toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer des nombres valides pour le téléphone et l'expérience.");
        return;
    }

    QString DISPONIBILITE = ui->dispo->currentText();
    QString LOGIN = ui->lineEdit_login->text();
    QString MDP = ui->lineEdit_mdp->text();

    // Check if all fields are filled
    if (NOM.isEmpty() || PRENOM.isEmpty() || EMAIL.isEmpty() || SPECIALITE.isEmpty() ||
        !ok1 || !ok2 || DISPONIBILITE.isEmpty() || LOGIN.isEmpty() || MDP.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Validate name and surname
    if (!isValidName(NOM) || !isValidName(PRENOM)) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }

    // Validate email
    if (!isValidEmail(EMAIL)) {
        QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
        return;
    }

    // Validate phone
    if (!isValidPhone(TELEPHONE)) {
        QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // Validate experience
    if (!isValidExperience(EXPERIENCE)) {
        QMessageBox::warning(this, "Erreur", "L'expérience ne doit pas dépasser 50.");
        return;
    }

    // Validate password
    if (!isValidPassword(MDP)) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une majuscule, trois chiffres, un caractère spécial, et avoir une longueur minimale de 8 caractères.");
        return;
    }

    em E(NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN, MDP);

    bool test = E.ajouter();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_telephone->clear();
    ui->specialite->setCurrentIndex(0);
    ui->lineEdit_experience->clear();
    ui->dispo->setCurrentIndex(0);
    ui->lineEdit_login->clear();
    ui->lineEdit_mdp->clear();
    if (test) {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}

void Employe::onDeleteButtonClicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the IDEMPLOYE value from the hidden column (column 0)
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    // Call the supprimer method
    bool success = Etmp.supprimer(id);

    if (success) {
        // Refresh the table view
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression.");
    }
}

void Employe::onEditButtonClicked(const QModelIndex &index)
{
    // Get the row of the clicked button
    int row = index.row();

    // Retrieve the employee data from the model
    QModelIndex idIndex = ui->tableView->model()->index(row, 0);
    int id = ui->tableView->model()->data(idIndex).toInt();

    QString nom = ui->tableView->model()->index(row, 1).data().toString();
    QString prenom = ui->tableView->model()->index(row, 2).data().toString();
    QString email = ui->tableView->model()->index(row, 3).data().toString();
    int telephone = ui->tableView->model()->index(row, 4).data().toInt();
    QString specialite = ui->tableView->model()->index(row, 5).data().toString();
    int experience = ui->tableView->model()->index(row, 6).data().toInt();
    QString disponibilite = ui->tableView->model()->index(row, 7).data().toString();
    QString login = ui->tableView->model()->index(row, 8).data().toString();
    QString mdp = ui->tableView->model()->index(row, 9).data().toString();

    // Open the edit dialog
    EditEmployeeDialog dialog(this);
    dialog.setID(id); // Set the ID internally
    dialog.setEmployeeData(nom, prenom, email, telephone, specialite, experience, disponibilite, login, mdp);

    if (dialog.exec() == QDialog::Accepted) {
        // Retrieve the updated data from the dialog
        QString newNom = dialog.getNom();
        QString newPrenom = dialog.getPrenom();
        QString newEmail = dialog.getEmail();
        int newTelephone = dialog.getTelephone();
        QString newSpecialite = dialog.getSpecialite();
        int newExperience = dialog.getExperience();
        QString newDisponibilite = dialog.getDisponibilite();
        QString newLogin = dialog.getLogin();
        QString newMdp = dialog.getMdp();

        // Validate the updated fields
        if (newNom.isEmpty() || newPrenom.isEmpty() || newEmail.isEmpty() || newSpecialite.isEmpty() ||
            newDisponibilite.isEmpty() || newLogin.isEmpty() || newMdp.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
            return;
        }

        if (!isValidName(newNom) || !isValidName(newPrenom)) {
            QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
            return;
        }

        if (!isValidEmail(newEmail)) {
            QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
            return;
        }

        if (!isValidPhone(newTelephone)) {
            QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir exactement 8 chiffres.");
            return;
        }

        if (!isValidExperience(newExperience)) {
            QMessageBox::warning(this, "Erreur", "L'expérience ne doit pas dépasser 50.");
            return;
        }

        if (!isValidPassword(newMdp)) {
            QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une majuscule, trois chiffres, un caractère spécial, et avoir une longueur minimale de 8 caractères.");
            return;
        }

        // If all validations pass, proceed to update the employee
        bool success = Etmp.modifier(dialog.getID(), newNom, newPrenom, newEmail, newTelephone, newSpecialite, newExperience, newDisponibilite, newLogin, newMdp);

        if (success) {
            // Refresh the table view
            ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(this, "Succès", "Employé modifié avec succès.");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification.");
        }
    }
}

void Employe::on_lineEdit_textChanged(const QString &arg1)
{
    QString searchText = arg1.trimmed();

    if (searchText.isEmpty()) {
        // If search field is empty, show all employees
        ui->tableView->setModel(Etmp.afficher());
        return;
    }

    // Create a new model
    QSqlQueryModel *model = new QSqlQueryModel();

    // Prepare the query with multiple search conditions (Oracle-specific syntax)
    QString queryStr = "SELECT IDEMPLOYE, NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, "
                       "EXPERIENCE, DISPONIBILITE, LOGIN, MDP FROM EMPLOYE "
                       "WHERE (NOM LIKE :search OR "
                       "PRENOM LIKE :search OR "
                       "SPECIALITE LIKE :search OR "
                       "TO_CHAR(IDEMPLOYE) LIKE :search OR "
                       "TO_CHAR(EXPERIENCE) LIKE :search)";

    // Create and execute the query
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":search", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Search query error:" << query.lastError().text();
        delete model; // Clean up the model if query fails
        return;
    }

    // Set the query using the new recommended approach
    model->setQuery(std::move(query));

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEMPLOYE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SPECIALITE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EXPERIENCE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("LOGIN"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("MDP"));

    // Add empty columns for buttons (to match the original display)
    model->insertColumn(10); // Column 10: Supprimer
    model->insertColumn(11); // Column 11: Modifier

    // Set headers for the new columns
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Supprimer"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Modifier"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true); // Hide the IDEMPLOYE column
}
void Employe::on_dispoSortButton_clicked()
{
    static bool ascending = true;
    QString order = ascending ? "DISPONIBILITE" : "DISPONIBILITE_DESC";
    ascending = !ascending;

    QSqlQueryModel* model = Etmp.Trier_Employe(order);
    if (model) {
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(0, true);
    }
}

void Employe::on_emailSortButton_clicked()
{
    static bool ascending = true;
    QString order = ascending ? "EMAIL" : "EMAIL_DESC";
    ascending = !ascending;

    QSqlQueryModel* model = Etmp.Trier_Employe(order);
    if (model) {
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(0, true);
    }
}

void Employe::on_telephoneSortButton_clicked()
{
    static bool ascending = true;
    QString order = ascending ? "TELEPHONE" : "TELEPHONE_DESC";
    ascending = !ascending;

    QSqlQueryModel* model = Etmp.Trier_Employe(order);
    if (model) {
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(0, true);
    }
}
void Employe::on_pdfButton_clicked()
{
    // Get save file name
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QString(), "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;

    // Ensure .pdf extension
    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    // Check database connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données non établie.");
        return;
    }

    // Set up PDF printer
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    // Create HTML document
    QTextDocument doc;
    QString html;
    QTextStream stream(&html);

    // HTML header and title
    stream << "<html><body>";
    stream << "<h2 style='text-align: center;'>Liste des Employés</h2>";
    stream << "<hr><br>";
    stream << "<table style='width:100%; border-collapse: collapse; font-size: 12px;'>";

    // Table headers (excluding ID and button columns)
    stream << "<tr style='background-color: #f2f2f2;'>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Nom</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Prénom</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Email</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Téléphone</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Spécialité</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Expérience</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Disponibilité</th>";
    stream << "<th style='border: 1px solid black; padding: 8px;'>Login</th>";
    stream << "</tr>";

    // Query employee data
    QSqlQuery query(db);
    query.prepare("SELECT NOM, PRENOM, EMAIL, TELEPHONE, SPECIALITE, EXPERIENCE, DISPONIBILITE, LOGIN FROM EMPLOYE");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // Add table rows
    while (query.next()) {
        stream << "<tr>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("NOM").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("PRENOM").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("EMAIL").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("TELEPHONE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("SPECIALITE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("EXPERIENCE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("DISPONIBILITE").toString() << "</td>";
        stream << "<td style='border: 1px solid black; padding: 8px;'>" << query.value("LOGIN").toString() << "</td>";
        stream << "</tr>";
    }

    stream << "</table></body></html>";
    doc.setHtml(html);

    // Print to PDF
    doc.print(&printer);

    // Show success message
    QMessageBox::information(this, "PDF", "Liste des employés exportée en PDF avec succès.");

    // Open the PDF automatically
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}
void Employe::on_statbutton_clicked()
{
    QTabWidget *tabWidget = new QTabWidget();

    struct StatInfo {
        QString title;
        QString field;
    };

    // Define the statistics we want to show
    QList<StatInfo> stats = {
        {"Répartition par spécialité", "SPECIALITE"},
        {"Répartition par disponibilité", "DISPONIBILITE"},
        {"Répartition par expérience", "EXPERIENCE"}
    };

    // Color palette for the pie charts
    QStringList colors = {
        "#ff6f61", "#6b5b95", "#88b04b", "#f7cac9",
        "#92a8d1", "#955251", "#b565a7", "#009688",
        "#f4b400", "#607d8b"
    };

    // Create a tab for each statistic
    for (const StatInfo &stat : stats)
    {
        QPieSeries *series = new QPieSeries();

        // Build and execute the query
        QSqlQuery query;
        QString queryString = QString("SELECT %1, COUNT(*) FROM EMPLOYE GROUP BY %1").arg(stat.field);
        query.prepare(queryString);

        if (query.exec()) {
            while (query.next()) {
                QString label = query.value(0).toString();
                int count = query.value(1).toInt();

                // For experience, add "years" to the label
                if (stat.field == "EXPERIENCE") {
                    label = QString("%1 ans").arg(label);
                }

                if (!label.isEmpty()) {
                    QPieSlice *slice = series->append(label, count);
                    slice->setLabelVisible(true);
                    slice->setExploded(true);
                    slice->setLabel(QString("%1\n%2 employés").arg(label).arg(count));
                }
            }
        } else {
            qDebug() << "Query error:" << query.lastError().text();
            continue;
        }

        // Apply colors to slices
        int colorIndex = 0;
        for (QPieSlice *slice : series->slices()) {
            slice->setColor(QColor(colors[colorIndex % colors.size()]));
            colorIndex++;
        }

        // Configure the chart
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(stat.title);
        chart->setTitleFont(QFont("Arial", 14, QFont::Bold));
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setFont(QFont("Arial", 9));

        // Create chart view
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Create tab content
        QWidget *tab = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(tab);
        layout->addWidget(chartView);
        tab->setLayout(layout);

        // Add tab to the tab widget
        tabWidget->addTab(tab, stat.title);
    }

    // Create and show the dialog
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des employés");
    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->addWidget(tabWidget);
    dialog->setLayout(dialogLayout);
    dialog->resize(900, 600);
    dialog->exec();
}
