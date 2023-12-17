#include "myorder.h"
#include "ui_myorder.h"
#include <QDebug>



MyOrder::MyOrder(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyOrder)
{
    ui->setupUi(this);

    user.setLogin(login);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Название", "Тип", "Цена", "Количество"});

    // Заполняем таблицу данными из файла
    updateOrderTable();

    priceTextBrowser = new QTextBrowser(this);
    priceTextBrowser->setGeometry(50, 280, 160, 30);
    priceTextBrowser->setText("Цена: ");

    updatePrice();

    connect(ui->tableWidget, &QTableWidget::itemChanged, this, &MyOrder::updatePrice);
}

void MyOrder::updateOrderTable()
{
    // Очистить текущую таблицу
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Заполнить таблицу данными из текущего заказа
    for (const auto& item : currentOrder.items) {
        int rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);

        // Создать ячейки и заполнить их данными
        QTableWidgetItem* nameItem = new QTableWidgetItem(item.name);
        QTableWidgetItem* typeItem = new QTableWidgetItem(item.type);
        QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(item.price));
        QTableWidgetItem* quantityItem = new QTableWidgetItem(QString::number(item.quantity));

        // Установить ячейки в таблицу
        ui->tableWidget->setItem(rowPosition, 0, nameItem);
        ui->tableWidget->setItem(rowPosition, 1, typeItem);
        ui->tableWidget->setItem(rowPosition, 2, priceItem);
        ui->tableWidget->setItem(rowPosition, 3, quantityItem);
    }
}

void MyOrder::updatePrice()
{
    double totalPrice = currentOrder.getTotalPrice();
    priceTextBrowser->setText("Цена: " + QString::number(totalPrice));
}

void MyOrder::on_pushButton_clicked()
{
    // Получаем индексы выделенных ячеек
    QModelIndexList selectedIndexes = ui->tableWidget->selectionModel()->selectedIndexes();

    // Удаляем по одному объекту из заказа за каждый клик
    if (!selectedIndexes.isEmpty()) {
        int row = selectedIndexes.first().row();

        // Получаем данные из удаляемой строки
        QString name = ui->tableWidget->item(row, 0)->text();
        QString type = ui->tableWidget->item(row, 1)->text();
        double price = ui->tableWidget->item(row, 2)->text().toDouble();
        int quantity = ui->tableWidget->item(row, 3)->text().toInt();

         qDebug() << "Removing Item:" << name << type << price << quantity;
        // Уменьшаем количество соответствующего объекта в заказе
        // Обновляем строку в виджете
        ui->tableWidget->item(row, 3)->setText(QString::number(quantity - 1));

        // Если количество стало равным 0, удаляем строку из виджета
        if (quantity - 1 == 0) {
            // Если количество стало равным 0, удаляем объект из заказа
            currentOrder.removeItem(name, type, price, 1);

            // Удаляем строку из виджета
            ui->tableWidget->removeRow(row);
        } else {
            // Иначе уменьшаем количество в заказе
            currentOrder.updateItemQuantity(name, type, price, quantity - 1);

            // Обновляем строку в виджете
            ui->tableWidget->item(row, 3)->setText(QString::number(quantity - 1));
        }
        // После удаления объекта пересчитываем общую цену и обновляем TextBrowser
        updatePrice();
    }
}

void MyOrder::on_pushBut_Buy_clicked() //on_pushBut_Buy
{
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
                << "Количество: " << ui->tableWidget->item(row, 3)->text() << ".\n";
            }

            logStream << "-----------------------------\n";
            logFile.close();
        } else {
            qDebug() << "Error opening log file for writing.";
        }
        QMessageBox::information(this, "Успешно", "Заказ выполнен успешно");
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
}

MyOrder::~MyOrder()
{
    delete ui;
}
