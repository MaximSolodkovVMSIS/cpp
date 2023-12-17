#include "historyoforders.h"
#include "ui_historyoforders.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


HistoryOfOrders::HistoryOfOrders(const QString& login, const QString& role, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryOfOrders)
{
    user.setLogin(login);
    qDebug() << "Login: " << user.getLogin() << '\n' << "Role: " << role ;
    ui->setupUi(this);

    // Открываем файл с историей заказов
    QFile file("C:\\programming\\C++\\hi\\database\\order_log.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        bool isAdmin = (role == "Admin");
        bool showOrder = isAdmin;  // Показывать ли текущий заказ

        QString currentOrder;  // Строка для хранения текущего заказа пользователя

        // Читаем файл и добавляем данные в текстовое поле
        while (!in.atEnd()) {
            QString line = in.readLine();

            if (line.trimmed() == "-----------------------------") {
                // Найден разделитель, проверяем, нужно ли выводить заказ
                if (showOrder) {
                    ui->textBrowser->append(currentOrder);
                }

                // Сбрасываем флаг для следующего заказа
                showOrder = isAdmin;

                // Очищаем строку после добавления заказа
                currentOrder.clear();
            } else {
                // Добавляем строку к текущему заказу
                line.replace("//", ", ");
                currentOrder += line + "\n";

                if (!isAdmin && line.startsWith("Login: " + login)) {
                    // Если это строка с заказом пользователя, устанавливаем флаг
                    showOrder = true;
                }
            }
        }

        // После выхода из цикла проверяем, был ли последний заказ пользователя
        if (showOrder) {
            ui->textBrowser->append(currentOrder);
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
