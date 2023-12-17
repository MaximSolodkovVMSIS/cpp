#include "registration.h"


registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::registration(confectioneryStoreInformationSystem *ConfectioneryStoreInformationSystem, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::registration),
    ConfectioneryStoreInformationSystem(ConfectioneryStoreInformationSystem)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

bool Validation::isValidName(const QString& name){
    return name.length() > 1;
}

bool Validation::isValidSurname(const QString& surname){
    return surname.length() > 1;
}

bool Validation::isValidLogin(const QString& login){
    QRegularExpression pattern("^[a-zA-Z\\d]+$");
    return login.length() >= 4 && pattern.match(login).hasMatch();
}

bool Validation::isValidPassword(const QString& password){
    QRegularExpression pattern("^(?=.*[a-zA-Z])(?=.*\\d)[a-zA-Z\\d]+$"); //проверка на минимум один символ и одно число
    QRegularExpressionMatch match = pattern.match(password);
    return password.length() >= 8 && match.hasMatch();
}


bool registration::isLoginUnique(const QString& login)
{
    // Открываем файл для чтения
    QFile file("C:\\programming\\C++\\hi\\database\\user_data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        // Считываем строки из файла
        QString line = in.readLine();
        // Разбиваем строку на части, используя разделитель (например, пробел)
        QStringList parts = line.split("//");
        // Проверяем, есть ли логин в текущей строке
        if (parts.size() >= 3 && parts[2] == login) {
            file.close();
            return false; // Логин уже занят
        }
    }

    file.close();
    return true; // Логин уникален
}

void registration::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString surname = ui->surname->text();
    QString login = ui->login->text();
    QString password = ui->password->text();

    if(!Validation::isValidName(name)){
        QMessageBox::warning(this, "Error", "Name must be at least 2 symbol.");
    }
    else if(!Validation::isValidSurname(surname)){
        QMessageBox::warning(this, "Error", "Surname nust be at least 2 symbol.");
    }
    else if(!Validation::isValidLogin(login)){
        QMessageBox::warning(this, "Error", "Login must be more then 4 symbols and contain only characters(a-z, A-Z).");
    }
    else if(!Validation::isValidPassword(password)){
        QMessageBox::warning(this, "Error", "Password must be more then 8 symbols and contain only characters(a-z, A-Z), and contain numbers.");
    }
    else{
        if (isLoginUnique(login)) {
            QFile file("C:\\programming\\C++\\hi\\database\\user_data.txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                if(file.size() == 0){
                    out << name << "//" << surname << "//" << login << "//" << password << "//Admin\n";
                }
                else{
                    out << name << "//" << surname << "//" << login << "//" << password << "//Client\n";
                }

                file.close();

                QMessageBox::information(this, "Success", "User registered successfully!");

                // Закрываем текущее окно
                this->close();

                ConfectioneryStoreInformationSystem->close();

                // Открываем новое окно confectionery
                confectionery confectionery(login);
                confectionery.setModal(true);
                confectionery.exec();

            } else {
                // Ошибка открытия файла
                QMessageBox::critical(this, "Error", "Could not open the file for writing!");
            }
        } else {
            // Логин уже занят, выводим сообщение об ошибке
            QMessageBox::warning(this, "Error", "Login is already taken. Please choose another login.");
        }
    }
}
