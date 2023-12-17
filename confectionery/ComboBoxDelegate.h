#include <QMessageBox>
#include <QComboBox>
#include <QStyledItemDelegate>

class ComboBoxDelegate : public QStyledItemDelegate {
public:
    ComboBoxDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        Q_UNUSED(option);
        Q_UNUSED(index);

        // Создаем комбобокс для редактирования ячейки
        QComboBox* comboBox = new QComboBox(parent);
        comboBox->addItem("Вариант 1");
        comboBox->addItem("Вариант 2");
        comboBox->addItem("Вариант 3");

        return comboBox;
    }

    void setEditorData(QWidget* editor, const QModelIndex& index) const override {
        QString value = index.model()->data(index, Qt::EditRole).toString();
        QComboBox* comboBox = qobject_cast<QComboBox*>(editor);
        if (comboBox) {
            comboBox->setCurrentText(value);
        }
    }

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override {
        QComboBox* comboBox = qobject_cast<QComboBox*>(editor);
        if (comboBox) {
            model->setData(index, comboBox->currentText(), Qt::EditRole);
        }
    }
};
