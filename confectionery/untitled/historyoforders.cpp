#include "historyoforders.h"
#include "ui_historyoforders.h"
#include <QFile>
#include <QTextStream>

HistoryOfOrders::HistoryOfOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryOfOrders)
{
    ui->setupUi(this);

    // Открываем файл с историей заказов
    QFile file("C:\\programming\\C++\\hi\\database\\order_log.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        int orderNumber = 1; // начальный номер заказа

        // Читаем файл и добавляем данные в текстовое поле
        while (!in.atEnd()) {
            QString line = in.readLine();

            if (line.trimmed() == "-----------------------------") {
                // Найден разделитель, добавляем заголовок для текущего заказа
                QString orderHeader = QString("Заказ %1:").arg(orderNumber);
                ui->textBrowser->append(orderHeader);

                // Увеличиваем номер заказа
                orderNumber++;
            } else {
                // Добавляем строку к текстовому полю
                line.replace("//", ", ");

                ui->textBrowser->append(line);
            }
        }

        file.close();
    } else {
        ui->textBrowser->setText("Ошибка открытия файла с историей заказов.");
    }
}


HistoryOfOrders::~HistoryOfOrders()
{
    delete ui;
}
