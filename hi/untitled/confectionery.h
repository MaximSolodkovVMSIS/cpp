#ifndef CONFECTIONERY_H
#define CONFECTIONERY_H

#include <QDialog>
#include <QToolBar>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QItemDelegate>
#include <QDateTime>


#include "userdatabase.h"
#include "myorder.h"
#include "historyoforders.h"
#include "user.h"

class BaseComboBoxDelegate : public QItemDelegate {
public:
    BaseComboBoxDelegate(QObject* parent = nullptr) : QItemDelegate(parent) {}

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

    void setEditorData(QWidget* editor, const QModelIndex& index) const override;

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;

protected:
    virtual void populateComboBox(QComboBox* comboBox, int column, const QModelIndex& index) const = 0; // Метод для заполнения комбобокса
};

class ComboBoxDelegateForType : public BaseComboBoxDelegate {
public:
    ComboBoxDelegateForType(QObject* parent = nullptr) : BaseComboBoxDelegate(parent) {}
protected:
    void populateComboBox(QComboBox* comboBox, int column, const QModelIndex& index) const override {
        Q_UNUSED(column);
        comboBox->addItem("Торт");
        comboBox->addItem("Напиток");
        comboBox->addItem("Булочка");
    }
};

class ComboBoxDelegateForAdditive : public BaseComboBoxDelegate {
public:
    ComboBoxDelegateForAdditive(QObject* parent = nullptr) : BaseComboBoxDelegate(parent) {}
protected:
    void populateComboBox(QComboBox* comboBox, int column, const QModelIndex& index) const override {
        Q_UNUSED(column);
        QString productType = index.model()->data(index.model()->index(index.row(), 5), Qt::DisplayRole).toString();
        comboBox->clear();

        if(productType == "Булочка"){
            comboBox->setVisible(true);
            comboBox->addItem("Шоколад");
            comboBox->addItem("Корица");
            comboBox->addItem("Пудра");
        }
        else{
            comboBox->setVisible(false);
        }
    }
};


namespace Ui {
class confectionery;
}

class confectionery : public QDialog
{
    Q_OBJECT

public:

    void saveOrderToFile(const QString& productName, const QString& productType, const QString& productPrice, const QString productAdditive, const int quantity);
    void onTableClicked(const QModelIndex &index);
    void on_tableView_clickedRows(const QModelIndex &index);
    explicit confectionery(const QString& login, QWidget *parent = nullptr);
    QString readUsersRoleFromFile(const QString& username);
    ~confectionery();

private:
    User user;
    QToolBar *toolbar;
    Ui::confectionery *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;

private slots:
    void OnUserDatabaseActionTriggered();
    void on_addProduct_clicked();
    void on_removeProduct_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_addToOrder_clicked();
    void on_myOrder_clicked();
    void on_historyOfOrders_clicked();
};

#endif // CONFECTIONERY_H
