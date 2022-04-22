#include "enrollingcourse_page.h"
#include "cs162-project-moodle-main/global.h"
#include "cs162-project-moodle-main/general_function.hpp"
#include "ui_enrollingcourse_page.h"

#include <sstream>

#include <QTableWidgetItem>

enrollingcourse_page::enrollingcourse_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::enrollingcourse_page)
{
    ui->setupUi(this);
    showAllAvailableCourse(mySchool);
}

enrollingcourse_page::~enrollingcourse_page()
{
    delete ui;
}

int currentCellX = -1, currentCellY = -1;

void enrollingcourse_page::on_availableCourseTable_cellClicked(int row, int column)
{
    ui->enrollBtt->setEnabled(true);
    currentCellX = row;
}

void enrollingcourse_page::on_availableCourseTable_itemSelectionChanged()
{
    ui->enrollBtt->setEnabled(false);
}

bool enrollingcourse_page::compareCourse(Course* course) {
    for (int i = 0; i < ui->enrolledCourseTable->rowCount(); i++) {
         if (QString::fromUtf8(course->courseID) == ui->enrolledCourseTable->item(i, 1)->text()) return false;
    }
    return true;
}

void enrollingcourse_page::showAllAvailableCourse(School mySchool) {
    string sessionToTime[4] = {"7:30", "9:30", "13:30", "15:30"};
    string dayToTime[6] = {"MON", "TUE", "WED", "THU", "FRI", "SAT"};
    Course* cur = mySchool.allCourses.monitor;
    while (cur->nextCourse) {
        cur = cur->nextCourse;
        if (cur->schoolyear == getCurrentSchoolYear() && cur->semester == getSemester()) {
            ui->availableCourseTable->insertRow(ui->availableCourseTable->rowCount());
            QTableWidgetItem* item;
            for (int i = 0; i < ui->availableCourseTable->columnCount(); i++) {
                item = new QTableWidgetItem;
                switch(i) {
                case 0:
                    item->setText(QString::number(ui->availableCourseTable->rowCount()));
                    break;
                case 1:
                    item->setText(QString::fromUtf8(cur->courseID));
                    break;
                case 2:
                    item->setText(QString::fromUtf8(cur->courseName));
                    break;
                case 3:
                    item->setText(QString::fromUtf8(sessionToTime[cur->session[0]] + " " + dayToTime[cur->day[0]]));
                    break;
                case 4:
                    item->setText(QString::fromUtf8(sessionToTime[cur->session[0]] + " " + dayToTime[cur->day[0]]));
                    break;
                case 5:
                    item->setText(QString::fromUtf8(cur->teacherName));
                    break;
                case 6:
                    item->setText(QString::number(cur->schoolyear));
                    break;
                case 7:
                    item->setText(QString::number(cur->semester));
                    break;
                }
                if (compareCourse(cur)) ui->availableCourseTable->setItem(ui->availableCourseTable->rowCount()-1, i, item);
            }
        }
    }
}

void enrollingcourse_page::on_enrollBtt_clicked()
{
    QTableWidgetItem* item;
    for (int i = 0; i < ui->availableCourseTable->columnCount(); i++) {
        item = new QTableWidgetItem;
        switch(i) {
        case 0:
            item->setText(QString::number(ui->enrolledCourseTable->rowCount()));
            break;
        case 1:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        case 2:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        case 3:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        case 4:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        case 5:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        case 6:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        case 7:
            item->setText(ui->availableCourseTable->item(currentCellX, i)->text());
            break;
        }
        ui->enrolledCourseTable->setItem(ui->enrolledCourseTable->rowCount()-1, i, item);
    }

}


void enrollingcourse_page::on_enrolledCourseTable_cellClicked(int row, int column)
{
    ui->removeBtt->setEnabled(true);
    currentCellY = row;
}


void enrollingcourse_page::on_enrolledCourseTable_itemSelectionChanged()
{
    ui->removeBtt->setEnabled(false);
}


void enrollingcourse_page::on_saveBtt_clicked()
{
    Student* student = mySchool.getStudent(current_id);
    for (int i = 0; i < ui->enrolledCourseTable->rowCount(); i++) {
        stringstream ss(ui->enrolledCourseTable->item(i, 3)->text().toStdString());
        string session_x = "", day_x = "";
        ss >> session_x >> day_x;
        int session_xint = ((session_x == "7:30") ? 0 : ((session_x == "9:30") ? 1 : ((session_x == "13:30") ? 2 : 3)));
        int day_xint = ((day_x == "MON") ? 0 : ((day_x == "TUE") ? 1 : ((day_x == "WED") ? 2 : ((day_x == "THU") ? 3: ((day_x == "FRI") ? 4 : 5)))));
        Course* neededCourse = mySchool.getCourse(ui->enrolledCourseTable->item(i, 1)->text().toStdString(), session_xint, day_xint);
        student->myCourses.addNewEnrolledCourse(&(neededCourse->courseID));
    }
}

void enrollingcourse_page::on_removeBtt_clicked()
{
    ui->enrolledCourseTable->removeRow(currentCellY);
}

