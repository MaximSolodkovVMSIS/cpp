#include "confectionery.h"
#include "ui_confectionery.h"
#include <QMouseEvent>
#include <QTimer>

QWidget *BaseComboBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const {
    Q_UNUSED(option);
    QComboBox* comboBox = new QComboBox(parent);
    populateComboBox(comboBox, index.column(), index); // Метод, который будет вызываться для заполнения комбобокса
    return comboBox;
}

void BaseComboBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QComboBox* comboBox = qobject_cast<QComboBox*>(editor);
    if (comboBox) {
        comboBox->setCurrentText(value);
    }
}

void BaseComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {
    QComboBox* comboBox = qobject_cast<QComboBox*>(editor);
    if (comboBox) {
        model->setData(index, comboBox->currentText(), Qt::EditRole);
    }
}

QString confectionery::readUsersRoleFromFile(const QString& login){
    QFile file("C:\\programming\\C++\\hi\\database\\user_data.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr, "Error", "Could not open file");
        return QString();
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList parts = line.split("//");
        if(parts.size() >= 3 && parts[2] == login){
            file.close();
            return parts[4];
        }
    }
    QMessageBox::warning(nullptr, "Warning", "User not found");
    return QString();
}

confectionery::confectionery(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confectionery),
    doubleClickHandled(false)
{
    ui->setupUi(this);

    user.setLogin(login);

    QString currentRole = readUsersRoleFromFile(login);

    // Инициализируем toolbar
    toolbar = new QToolBar("User Database", this);
    toolbar->addAction("User Database");

    // Добавляем ToolBar в верхнюю часть окна
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setMenuBar(toolbar);

    if(currentRole != "Admin"){
        toolbar->hide();
    }

    if(currentRole != "Cook" && currentRole != "Admin"){
        ui->addProduct->setVisible(false);
        ui->removeProduct->setVisible(false);
    }

    connect(toolbar, &QToolBar::actionTriggered, this, &confectionery::OnUserDatabaseActionTriggered);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\programming\\C++\\hi\\database\\products.db");
    if(!db.open()){
        QMessageBox::warning(this, "Error", "Database did non open: " + db.lastError().databaseText());
    }
    else {

        model = new CustomSqlTableModel(readUsersRoleFromFile(user.getLogin()), this, db);
        model->setTable("product");
        model->select();

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ComboBoxDelegateForType* comboBoxDelegeteForType = new ComboBoxDelegateForType(this);
        ui->tableView->setItemDelegateForColumn(4, comboBoxDelegeteForType);

        ui->tableView->setSortingEnabled(true);
        connect(ui->tableView, &QTableView::clicked, this, &confectionery::on_tableView_clickedRows);
        connect(ui->tableView, &QTableView::doubleClicked, this, &confectionery::on_tableView_doubleClicked);

        ui->tableView->setColumnHidden(5, true);  // Скрываем столбец ID
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        doubleClickTimer = new QTimer(this);
        doubleClickTimer->setSingleShot(true);

        connect(doubleClickTimer, &QTimer::timeout, [this]() {
            doubleClickHandled = false;
        });

        ui->tableView->setColumnHidden(6, true);  // Скрываем столбец статусом
    }
}

void confectionery::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (!doubleClickHandled) {
        doubleClickHandled = true;
        // Получаем данные выбранного элемента
        if (index.column() == 2) {
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            QVariant productIdData = model->data(model->index(index.row(), 5));  // Предполагается, что столбец ID находится на позиции 5

            if (productIdData.isValid()) {
                int productId = productIdData.toInt();
                Description description(user.getLogin(), readUsersRoleFromFile(user.getLogin()), model, productId, this);
                // Открываем новое окно модально
                description.setModal(true);
                description.exec();
            }
        }
        doubleClickTimer->start(500); // Задержка в миллисекундах перед сбросом doubleClickHandled
    }
}

void confectionery::mouseReleaseEvent(QMouseEvent *event)
{
    // Проверяем, было ли двойное нажатие
    if (event->button() == Qt::LeftButton && event->type() == QEvent::MouseButtonRelease && event->modifiers() == Qt::NoModifier) {
        doubleClickHandled = false;
    }
    QDialog::mouseReleaseEvent(event);
}

void confectionery::on_tableView_clickedRows(const QModelIndex &index){
    // Вызываем selectRow для выделения всей строки при клике на любую ячейку
    ui->tableView->selectRow(index.row());
}

void confectionery::OnUserDatabaseActionTriggered() {
    UserDatabase UserDatabase;
    UserDatabase.setModal(true);
    UserDatabase.exec();
}


void confectionery::on_addProduct_clicked()
{
    // Получаем максимальный ID из модели
    int maxId = model->rowCount() > 0 ? model->data(model->index(model->rowCount() - 1, 5)).toInt() : 0;

    // Увеличиваем текущий максимальный ID на 1
    int newId = maxId + 1;

    // Вставляем новую строку и устанавливаем значения в основной таблице
    model->insertRow(model->rowCount());
    model->setData(model->index(model->rowCount() - 1, 5), newId);

    // Создаем новую строку и устанавливаем значения в таблице описания
    descriptionModel = new QSqlTableModel();
    descriptionModel->setTable("description");
    descriptionModel->select();

    descriptionModel->insertRow(descriptionModel->rowCount());
    descriptionModel->setData(descriptionModel->index(descriptionModel->rowCount() - 1, 1), newId);

    // Если успешно добавились оба продукта, фиксируем изменения
    if (model->submitAll() && descriptionModel->submitAll()) {
        QMessageBox::information(this, "Success", "Product added successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Failed to add product.");
    }
}

void confectionery::on_removeProduct_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (!selectedIndexes.isEmpty()) {
        int row = selectedIndexes.first().row();
        int removedId = model->data(model->index(row, 5)).toInt();

        // Удаляем строку
        model->removeRow(row);
        model->select();

        if (model->submitAll()) {
            QMessageBox::information(this, "Success", "Product removed successfully!");
        } else {
            QMessageBox::warning(this, "Error", "Failed to remove product.");
        }
    }
}


void confectionery::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

Order currentOrder;

void confectionery::on_addToOrder_clicked()
{
    // Получаем индекс выбранной строки
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a row to add to the order.");
        return;
    }
    // Получаем данные из выбранной строки
    int selectedRow = selectedRows.first().row();
    QString productName = model->data(model->index(selectedRow, 0)).toString();
    QString productType = model->data(model->index(selectedRow, 4)).toString();
    QString productPriceStr = model->data(model->index(selectedRow, 3)).toString();

    productPriceStr.replace(",", ".");

    double productPrice = productPriceStr.toDouble();

    int quantity = 1;

    currentOrder.addItem(productName, productType, productPrice, quantity);
}

void confectionery::on_myOrder_clicked()
{
    MyOrder myorder(user.getLogin());
    myorder.setModal(true);
    myorder.exec();
}


void confectionery::on_historyOfOrders_clicked()
{
    HistoryOfOrders history(user.getLogin(), readUsersRoleFromFile(user.getLogin()));
    history.setModal(true);
    history.exec();
}

void confectionery::on_searchButton_clicked()
{
    QString search = ui->search->text();
    if (search.isEmpty()) {
        // Если строка поиска пуста, очищаем фильтр
        model->setFilter("");
    } else {
        QString formattedSearch;
        formattedSearch += search.at(0).toUpper();

        for (int i = 1; i < search.length(); ++i) {
            formattedSearch += search.at(i).toLower();
        }

        // Применяем фильтр по первому столбцу для частичного совпадения с игнорированием регистра
        model->setFilter(QString("Название LIKE '%%1%' COLLATE NOCASE").arg(formattedSearch));
        model->select();
    }
}

confectionery::~confectionery()
{
    delete ui;
}


