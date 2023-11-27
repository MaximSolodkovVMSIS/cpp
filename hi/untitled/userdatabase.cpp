#include "userdatabase.h"


UserDatabase::UserDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDatabase)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Имя", "Фамилия", "Логин", "Роль"});

    // Заполняем таблицу данными из файла
    if (!readUsersFromFile()) {
        QMessageBox::critical(this, "Error", "Could not read users from file");
    }
}

UserDatabase::~UserDatabase()
{
    delete ui;
}

bool UserDatabase::readUsersFromFile()
{
    QFile file("C:\\programming\\C++\\hi\\database\\user_data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("//");
        if (parts.size() >= 5) {
            // Добавляем новую строку в таблицу
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // Устанавливаем значения в ячейки таблицы
            for (int col = 0; col < 3; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(parts[col]);
                ui->tableWidget->setItem(row, col, item);
            }
            QComboBox *roleComboBox = new QComboBox();
            roleComboBox->addItems({"Admin", "Client", "Cook"});

            // Устанавливаем текущее значение из файла
            int currentIndex = roleComboBox->findText(parts[4]);
            if (currentIndex != -1) {
                roleComboBox->setCurrentIndex(currentIndex);
            }

            // Вставляем комбо-бокс в ячейку таблицы
            ui->tableWidget->setCellWidget(row, 3, roleComboBox);
        }
    }

    file.close();
    return true;
}

void UserDatabase::on_pushButtonSave_clicked()
{
    QFile file("C:\\programming\\C++\\hi\\database\\user_data.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }

    QTextStream in(&file);
    QStringList lines;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("//");
        if (parts.size() >= 5) {
            int row = ui->tableWidget->currentRow();
            if (row >= 0) {
                // Если строка выбрана, обновляем роль
                if (row == lines.size()) {
                    QComboBox *roleComboBox = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(row, 3));
                    if (roleComboBox) {
                        parts[4] = roleComboBox->currentText();
                    }
                }
            }

            // Добавляем строку в список
            lines.append(parts.join("//"));
        }
    }

    file.resize(0); // Очищаем содержимое файла

    // Перезаписываем файл с обновленными строками
    QTextStream out(&file);
    foreach (const QString &line, lines) {
        out << line << Qt::endl;
    }

    file.close();

    QMessageBox::information(this, "Success", "Roles saved successfully!");
}
