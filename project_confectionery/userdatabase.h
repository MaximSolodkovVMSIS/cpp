#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QComboBox>

#include "ui_userdatabase.h"

namespace Ui {
class UserDatabase;
}

class UserDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit UserDatabase(QWidget *parent = nullptr);
    ~UserDatabase();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::UserDatabase *ui;

    bool readUsersFromFile(); // Добавляем объявление функции для чтения пользователей из файла
};

#endif // USERDATABASE_H
