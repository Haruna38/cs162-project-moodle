#ifndef ADDNEWSTUDENT_H
#define ADDNEWSTUDENT_H

#include <QDialog>
#include "addnewclass.h"

namespace Ui {
class addnewstudent;
}

class addnewstudent : public QDialog
{
    Q_OBJECT

public:
    explicit addnewstudent(QWidget *parent = nullptr, Ui::AddNewClass* ancUI = nullptr);
    ~addnewstudent();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addnewstudent *ui;
};

#endif // ADDNEWSTUDENT_H
