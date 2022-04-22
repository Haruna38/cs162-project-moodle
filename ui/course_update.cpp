#include "course_update.h"
#include "ui_course_update.h"
#include "addnewcourse.h"
#include <fstream>

#include "cs162-project-moodle-main/global.h"
#include <QTableWidgetItem>

course_update::course_update(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::course_update)
{
    ui->setupUi(this);
}

course_update::~course_update()
{
    delete ui;
}


void course_update::AllCourseTableDisplay()
{
    Course*  curCourse = mySchool.allCourses.monitor;
    while (curCourse->nextCourse) {
        curCourse = curCourse->nextCourse;
        ui->tableDisplayAllCourses->insertRow(ui->tableDisplayAllCourses->rowCount());
        QTableWidgetItem* item;
        for (int i = 0; i < ui->tableDisplayAllCourses->columnCount(); i++) {
            item = new QTableWidgetItem;
            switch(i) {
                case 0:
                    item->setText(QString::number(ui->tableDisplayAllCourses->rowCount()));
                    break;
                case 1:
                    item->setText(QString::fromUtf8(curCourse->courseID));
                    break;
                case 2:
                    item->setText(QString::fromUtf8(curCourse->courseName));
                    break;
                case 3:
                    item->setText(QString::number(curCourse->semester));
                    break;
                case 4:
                    item->setText(QString::number(curCourse->schoolyear));
                    break;
            }
            ui->tableDisplayAllCourses->setItem(ui->tableDisplayAllCourses->rowCount()-1, i, item);
        }
    }
}

void course_update::on_btnAddNewCourse_clicked()
{
    AddNewCourse* ansWindow = new AddNewCourse(nullptr, ui);
    ansWindow->show();
}

