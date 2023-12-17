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
#include <QMouseEvent>
#include <QTimer>
#include <QSortFilterProxyModel>


#include "userdatabase.h"
#include "myorder.h"
#include "historyoforders.h"
#include "user.h"
#include "order.h"
#include "description.h"



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

namespace Ui {
class confectionery;
}

class confectionery : public QDialog
{
    Q_OBJECT

public:
    void mouseReleaseEvent(QMouseEvent *event);
    void onTableClicked(const QModelIndex &index);
    void on_tableView_clickedRows(const QModelIndex &index);
    explicit confectionery(const QString& login, QWidget *parent = nullptr);
    QString readUsersRoleFromFile(const QString& username);
    ~confectionery();

private:
    QSortFilterProxyModel* proxyModel;
    QSqlTableModel* descriptionModel;
    QTimer* doubleClickTimer;
    User user;
    QToolBar *toolbar;
    Ui::confectionery *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
    bool doubleClickHandled;

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void OnUserDatabaseActionTriggered();
    void on_addProduct_clicked();
    void on_removeProduct_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_addToOrder_clicked();
    void on_myOrder_clicked();
    void on_historyOfOrders_clicked();
    void on_searchButton_clicked();
};

class CustomSqlTableModel : public QSqlTableModel {
public:
    CustomSqlTableModel(const QString& role, QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase())
        : QSqlTableModel(parent, db), userRole(role) {}

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        Qt::ItemFlags flags = QSqlTableModel::flags(index);

        if (index.column() == 5) {  // Если столбец ID
            flags |= Qt::ItemIsEditable;
        }

        return flags;
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override {
        // Добавим обработку изменений для столбца ID
        if (index.column() == 5 && role == Qt::EditRole) {
            bool ok;
            int newId = value.toInt(&ok);
            if (ok) {
                // Проверим, что ID следующий в последовательности
                int rowCount = this->rowCount();
                if (newId <= rowCount + 1) {
                    return QSqlTableModel::setData(index, value, role);
                } else {
                    // Если порядок нарушен, выполните дополнительные действия
                    QMessageBox::warning(nullptr, "Error", "Invalid ID. It should be in sequence.");
                    return false;
                }
            }
        }
        return QSqlTableModel::setData(index, value, role);
    }

private:
    QString userRole;
};


#endif // CONFECTIONERY_H
