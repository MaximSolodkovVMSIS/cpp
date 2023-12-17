#include "description.h"
#include "qsqlerror.h"
#include "ui_description.h"
#include <QSqlQuery>

int Description::getID(){
    return productId;
}

void Description::setID(int id){
    this->productId = id;
}

Description::Description(const QString& login, const QString& Role, QSqlTableModel* descriptionModel, int productId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Description)
{
    user.setLogin(login);
    setID(productId);
    qDebug() << "Login: " << user.getLogin() << '\n' << "Role: " << '\n' <<Role << "ID: " << productId ;

    ui->setupUi(this);

    descriptionModel = new QSqlTableModel(this);
    descriptionModel->setTable("description");

    // Указываем фильтр для выборки только тех строк, у которых значение в столбце ID совпадает с productId
    descriptionModel->setFilter(QString("ID = %1").arg(productId));
    descriptionModel->select();

    if (descriptionModel->rowCount() > 0) {
        // Предполагается, что описание находится в 0 столбце
        QString description = descriptionModel->data(descriptionModel->index(0, 0)).toString();
        ui->plainTextEdit->setPlainText(description);
    }

    if (Role == "Client") {
        ui->plainTextEdit->setReadOnly(true);
    }
}


void Description::on_saveBut_clicked()
{
    QString descriptionText = ui->plainTextEdit->toPlainText();

    QSqlQuery query;

    productId = getID();

    // Обновляем таблицу description
    query.prepare("UPDATE description SET Описание = :description WHERE ID = :productId");
    query.bindValue(":description", descriptionText);
    query.bindValue(":productId", productId);

    if (query.exec()) {
        qDebug() << "Description updated successfully!";
    } else {
        qDebug() << "Failed to update description:" << query.lastError().text();
    }
}

Description::~Description()
{
    delete ui;
}



