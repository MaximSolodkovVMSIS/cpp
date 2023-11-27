#include "confectionery.h"
#include "ui_confectionery.h"

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

void confectionery::saveOrderToFile(const QString& productName, const QString& productType, const QString& productPrice,const QString productAdditive, const int quantity)
{
    QFile file("C:\\programming\\C++\\hi\\database\\orders.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << productName << "//" << productType << "//" << productPrice << "//" << productAdditive << "//" <<quantity << "\n";
        // Добавьте дополнительные данные в файл, если они присутствуют в вашей модели
        file.close();

        QMessageBox::information(this, "Success", "Product added to the order successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the orders file.");
    }
}

confectionery::confectionery(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confectionery)
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
        ui->historyOfOrders->setVisible(false);
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

        model = new QSqlTableModel(this, db);
        model->setTable("product");
        model->select();

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ComboBoxDelegateForAdditive *comboBoxDelegateForAdditive = new ComboBoxDelegateForAdditive(this);
        ui->tableView->setItemDelegateForColumn(3, comboBoxDelegateForAdditive);

        ComboBoxDelegateForType* comboBoxDelegeteForType = new ComboBoxDelegateForType(this);
        ui->tableView->setItemDelegateForColumn(5, comboBoxDelegeteForType);

        ui->tableView->setSortingEnabled(true);
        connect(ui->tableView, &QTableView::clicked, this, &confectionery::on_tableView_clickedRows);

    }
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
    model->insertRow(model->rowCount());

    if (model->submitAll()) {
        QMessageBox::information(this, "Success", "Product added successfully!");
    }
}

void confectionery::on_removeProduct_clicked()
{
    model->removeRow(currentRow);
    model->select();
}

void confectionery::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

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
    QString productType = model->data(model->index(selectedRow, 5)).toString();
    QString productPrice = model->data(model->index(selectedRow, 4)).toString();
    QString productAdditive = model->data(model->index(selectedRow, 3)).toString();

    int quantity = 1;

    saveOrderToFile(productName, productType, productPrice, productAdditive,  quantity);
}

void confectionery::on_myOrder_clicked()
{
    MyOrder myorder(user.getLogin());
    myorder.setModal(true);
    myorder.exec();
}


void confectionery::on_historyOfOrders_clicked()
{
    HistoryOfOrders history;
    history.setModal(true);
    history.exec();
}

confectionery::~confectionery()
{
    delete ui;
}
