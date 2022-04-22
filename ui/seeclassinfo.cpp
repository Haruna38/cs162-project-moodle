#include "ui/seeclassinfo.h"
#include "ui_seeclassinfo.h"

#include "global.h"

#include <QTableWidgetItem>

std::string classID;
seeClassInfo::seeClassInfo(QWidget *parent, std::string classID_x) :
    QMainWindow(parent),
    ui(new Ui::seeClassInfo)
{
    ui->setupUi(this);
    classID = classID_x;
    ui->classIDText->setText(QString::fromUtf8(classID_x));
}

seeClassInfo::~seeClassInfo()
{
    delete ui;
}

void seeClassInfo::showStudentInClass() {
    Class* thisClass = mySchool.getClass(classID);
    QTableWidgetItem* item;
    Student* student = thisClass->monitor;
    while (student->nextStudent) {
        for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
            item = new QTableWidgetItem;
            switch(i) {
                case 0:
                    item->setText(QString::number(ui->tableWidget->rowCount()));
                    break;
                case 1:
                    item->setText(QString::number(student->studentID));
                    break;
                case 2:
                    item->setText(QString::fromUtf8(student->firstName));
                    break;
                case 3:
                    item->setText(QString::fromUtf8(student->lastName));
                break;
                case 4:
                    item->setText(QString::fromUtf8(((student->gender) ? "Male" : "Female")));
                    break;
                case 5:
                    item->setText(QString::fromUtf8(student->dateOfBirth));
                    break;
                case 6:
                    item->setText(QString::number(student->socialID));
                    break;
            }
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, item);
        }
    }
}
