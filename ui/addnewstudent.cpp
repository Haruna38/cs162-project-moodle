#include "ui/addnewstudent.h"
#include "ui_addnewstudent.h"
#include "ui/addnewclass.h"
#include "ui_addnewclass.h"

Ui::AddNewClass* ancUI_xy;

#include <QTableWidgetItem>

addnewstudent::addnewstudent(QWidget *parent, Ui::AddNewClass* ancUI) :
    QDialog(parent),
    ui(new Ui::addnewstudent)
{
    ui->setupUi(this);
    ancUI_xy = ancUI;
}

addnewstudent::~addnewstudent()
{
    delete ui;
}

void addnewstudent::on_pushButton_clicked()
{
    long long studentID_x = (ui->studentIDEdit->text()).toLongLong();
    std::string firstname_x = (ui->firstNameEdit->text()).toStdString();
    std::string lastname_x = (ui->lastNameEdit->text()).toStdString();
    std::string gender_x = (ui->genderBox->currentText()).toStdString();
    std::string date_x = (ui->birthdateEdit->date()).toString("dd/MM/yyyy").toStdString();
    long long socialID_x = (ui->socialIDEdit->text()).toLongLong();
    ancUI_xy->tableWidget->insertRow(ancUI_xy->tableWidget->rowCount());
    QTableWidgetItem* item;
    for (int i = 0; i < ancUI_xy->tableWidget->columnCount(); i++) {
        item = new QTableWidgetItem;
        switch(i) {
            case 0:
                item->setText(QString::number(ancUI_xy->tableWidget->rowCount()));
                break;
            case 1:
                item->setText(QString::number(studentID_x));
                break;
            case 2:
                item->setText(QString::fromUtf8(firstname_x));
                break;
            case 3:
                item->setText(QString::fromUtf8(lastname_x));
            break;
            case 4:
                item->setText(QString::fromUtf8(gender_x));
                break;
            case 5:
                item->setText(QString::fromUtf8(date_x));
                break;
            case 6:
                item->setText(QString::number(socialID_x));
                break;
        }
        ancUI_xy->tableWidget->setItem(ancUI_xy->tableWidget->rowCount()-1, i, item);
    }
    this->close();
}

