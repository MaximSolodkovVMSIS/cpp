#include "confectionerystoreinformationsystem.h"
#include "./ui_confectionerystoreinformationsystem.h"
#include <QMessageBox>
#include "authorization.h"
#include "registration.h"
#include <QPixmap>

confectioneryStoreInformationSystem::confectioneryStoreInformationSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::confectioneryStoreInformationSystem)
{
    ui->setupUi(this);   
}

confectioneryStoreInformationSystem::~confectioneryStoreInformationSystem()
{
    delete ui;
}

void confectioneryStoreInformationSystem::on_regButton_clicked()
{
    registration registration(this);
    registration.setModal(true);
    registration.exec();
}


void confectioneryStoreInformationSystem::on_logButton_clicked()
{
    authorization login(this);
    login.setModal(true);
    login.exec();
}

