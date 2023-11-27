#include "myorder.h"
#include "ui_myorder.h"
#include <QDebug>

/*
void MyOrder::saveOrderToLogFile(const QString& login) {
    // Открываем лог-файл для записи
    QFile logFile("C:\\programming\\C++\\hi\\database\\order_log.txt");
    if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open log file for writing.");
        return;
    }
    // Создаем текстовый поток для записи в файл
    QTextStream out(&logFile);
    // Получаем текущую дату и время
    QDateTime currentDateTime = QDateTime::currentDateTime();
    // Записываем информацию о заказе в файл
    out << "Login: " << login << ", Order Time: " << currentDateTime.toString() << "\n";
    // Получаем выбранные строки из таблицы
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    // Записываем информацию о каждом выбранном продукте в заказе
    foreach (const QModelIndex &index, selectedRows) {
        for (int column = 0; column < model->columnCount(); ++column) {
            out << model->headerData(column, Qt::Horizontal).toString() << ": "
                << model->data(model->index(index.row(), column)).toString() << ". ";
        }
        out << "\n";
    }
    out << "-----------------------------" << "\n";
    logFile.close();
}
*/

void MyOrder::removeRowFromFile(const QStringList &rowData)
{
    // Открываем файл для чтения и записи
    QFile file("C:\\programming\\C++\\hi\\database\\orders.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Error opening file for reading and writing.";
        return;
    }

    QTextStream in(&file);
    QStringList lines;

    // Читаем все строки из файла
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("//");

        // Если строка не соответствует удаляемой, добавляем её в список строк
        if (fields != rowData) {
            lines.append(line);
        }
    }

    // Закрываем файл
    file.close();

    // Открываем файл снова для записи
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening file for writing.";
        return;
    }

    QTextStream out(&file);

    // Записываем обновленные строки в файл
    for (const QString &line : lines) {
        out << line << "\n";
    }

    // Закрываем файл
    file.close();
}

bool MyOrder::readProdutsFromFile() {
    QFile file("C:\\programming\\C++\\hi\\database\\orders.txt");  // Замените путь на свой
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("//");
        if (fields.size() >= 5) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(fields.at(col));
                if(col != 4){
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                }
                ui->tableWidget->setItem(row, col, item);
            }
        }
    }

    file.close();
    return true;
}


MyOrder::MyOrder(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyOrder)
{
    ui->setupUi(this);

    user.setLogin(login);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Название", "Тип", "Цена", "Добавка", "Количество"});

    // Заполняем таблицу данными из файла

    if (!readProdutsFromFile()) {
        QMessageBox::critical(this, "Error", "Вы еще не сделали заказ");
    }

}

void MyOrder::on_pushButton_clicked()
{
    // Получаем индексы выделенных ячеек
    QModelIndexList selectedIndexes = ui->tableWidget->selectionModel()->selectedIndexes();

    // Удаляем выделенные строки из виджета и из файла
    for (const QModelIndex &index : selectedIndexes) {
        int row = index.row();

        // Получаем данные из удаляемой строки
        QStringList rowData;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            rowData.append(item->text());
        }

        // Удаляем строку из виджета
        ui->tableWidget->removeRow(row);

        // Удаляем данные из файла
        removeRowFromFile(rowData);
    }
}

void MyOrder::on_pushButton_2_clicked()
{
    // Считываем данные из файла
    QStringList orderData;
    QFile orderFile("C:\\programming\\C++\\hi\\database\\orders.txt");
    if (orderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&orderFile);
        while (!in.atEnd()) {
            orderData.append(in.readLine());
        }
        orderFile.close();
    } else {
        qDebug() << "Error opening order file for reading.";
        return;
    }
        orderFile.remove();

        // Выводим сообщение об успешном выполнении заказа
        QMessageBox::information(this, "Success", "Order completed successfully!");

        // Получаем информацию о пользователе
        QString login = user.getLogin();

        // Записываем информацию о заказе в лог-файл
        QFile logFile("C:\\programming\\C++\\hi\\database\\order_log.txt");
        if (logFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream logStream(&logFile);
            QDateTime currentDateTime = QDateTime::currentDateTime();
            logStream << "Login: " << login << ", Order Time: " << currentDateTime.toString() << "\n";

            // Записываем данные из таблицы
            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                logStream << "Название: " << ui->tableWidget->item(row, 0)->text() << ", "
                << "Тип: " << ui->tableWidget->item(row, 1)->text() << ", "
                << "Цена: " << ui->tableWidget->item(row, 2)->text() << ", "
                << "Добавки: " << ui->tableWidget->item(row, 3)->text() << ", "
                << "Количество: " << ui->tableWidget->item(row, 4)->text() << ".\n";
            }

            logStream << "-----------------------------\n";
            logFile.close();
        } else {
            qDebug() << "Error opening log file for writing.";
        }
}



MyOrder::~MyOrder()
{
    delete ui;
}
