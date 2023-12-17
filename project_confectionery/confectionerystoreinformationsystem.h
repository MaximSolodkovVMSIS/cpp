#ifndef CONFECTIONERYSTOREINFORMATIONSYSTEM_H
#define CONFECTIONERYSTOREINFORMATIONSYSTEM_H

#include <QMainWindow>

namespace Ui { class confectioneryStoreInformationSystem; }

class confectioneryStoreInformationSystem : public QMainWindow
{
    Q_OBJECT

public:
    confectioneryStoreInformationSystem(QWidget *parent = nullptr);
    ~confectioneryStoreInformationSystem();

private slots:
    void on_regButton_clicked();

    void on_logButton_clicked();

private:
    Ui::confectioneryStoreInformationSystem *ui;
};
#endif // CONFECTIONERYSTOREINFORMATIONSYSTEM_H
