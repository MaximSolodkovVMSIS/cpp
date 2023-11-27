#include "authorization.h"


authorization::authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::authorization(confectioneryStoreInformationSystem *ConfectioneryStoreInformationSystem, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::authorization),
    ConfectioneryStoreInformationSystem(ConfectioneryStoreInformationSystem)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();



    QFile file("C:\\programming\\C++\\hi\\database\\user_data.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList parts = line.split("//");
        if(parts.size() >= 4 && parts[2] == login && parts[3] == password){
            file.close();
            QMessageBox::information(this, "Success", "Login successful!");

            this->close();

            ConfectioneryStoreInformationSystem->close();

            confectionery confectionery(login);
            confectionery.setModal(true);
            confectionery.exec();

            return;
        }
        else if(parts.size() >= 4 && parts[2] == login && parts[3] != password){
            QMessageBox::warning(this, "Error", "Password is incorrect");
            return;
        }
    }
    file.close();
    QMessageBox::warning(this, "Error", "Login is not found");


}
