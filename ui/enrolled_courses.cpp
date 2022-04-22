#include "ui/enrolled_courses.h"
#include "ui_enrolled_courses.h"
#include <fstream>

#include <QTableWidgetItem>

enrolled_courses::enrolled_courses(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::enrolled_courses)
{
    ui->setupUi(this);
    ifstream fin; fin.open("schoolyear.txt");
    string tmp = "";
    while (fin >> tmp)
        ui->comboBox_2->addItem(QString::fromUtf8(tmp));
    fin.close();
}

enrolled_courses::~enrolled_courses()
{
    delete ui;
}

void enrolled_courses::CustomTableDisplay(School mySchool, int studentID_x, int schoolyear_x, int semester_x)
{
    Student* needed_student = mySchool.getStudent(studentID_x);
    enrolledCourse* curEnrolledCourse = needed_student->myCourses.monitor;
    while (curEnrolledCourse->nextEnrolledCourse) {
        curEnrolledCourse = curEnrolledCourse->nextEnrolledCourse;
        Course* found_course = mySchool.getCourse(curEnrolledCourse->courseID);
        if (found_course->schoolyear == schoolyear_x && found_course->semester == semester_x) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem* item;
            for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
                item = new QTableWidgetItem;
                switch(i) {
                    case 0:
                        item->setText(QString::number(ui->tableWidget->rowCount()));
                        break;
                    case 1:
                        item->setText(QString::fromUtf8(found_course->courseID));
                        break;
                    case 2:
                        item->setText(QString::fromUtf8(found_course->courseName));
                        break;
                    case 3:
                        item->setText(QString::number(found_course->numberofCredit));
                        break;
                    case 4:
                        item->setText(QString::fromUtf8(found_course->teacherName));
                        break;
                    case 5:
                        item->setText(QString::number(found_course->schoolyear));
                        break;
                    case 6:
                        item->setText(QString::number(found_course->semester));
                        break;
                }
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, item);
            }
        }
    }
}

void enrolled_courses::AllCourseTableDisplay(School mySchool, int studentID_x)
{
    Student* needed_student = mySchool.getStudent(studentID_x);
    enrolledCourse* curEnrolledCourse = needed_student->myCourses.monitor;
    while (curEnrolledCourse->nextEnrolledCourse) {
        curEnrolledCourse = curEnrolledCourse->nextEnrolledCourse;
        Course* found_course = mySchool.getCourse(curEnrolledCourse->courseID);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem* item;
        for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
            item = new QTableWidgetItem;
            switch(i) {
                case 0:
                    item->setText(QString::number(ui->tableWidget->rowCount()));
                    break;
                case 1:
                    item->setText(QString::fromUtf8(found_course->courseID));
                    break;
                case 2:
                    item->setText(QString::fromUtf8(found_course->courseName));
                    break;
                case 3:
                    item->setText(QString::number(found_course->numberofCredit));
                    break;
                case 4:
                    item->setText(QString::fromUtf8(found_course->teacherName));
                    break;
                case 5:
                    item->setText(QString::number(found_course->schoolyear));
                    break;
                case 6:
                    item->setText(QString::number(found_course->semester));
                    break;
            }
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, item);
        }
    }
}



void enrolled_courses::on_searchcourse_button_clicked()
{
    if (ui->allcourse_button) AllCourseTableDisplay(mySchool, current_id);
    else {
        int schoolyear_x = (ui->comboBox->itemData(ui->comboBox->currentIndex())).toInt();
        int semester_x = (ui->comboBox_2->itemData(ui->comboBox_2->currentIndex())).toString().split("-")[0].toInt();
        CustomTableDisplay(mySchool, current_id, schoolyear_x, semester_x);
    }
}


void enrolled_courses::on_customcourse_button_clicked()
{
    ui->comboBox->setEnabled(true);
    ui->comboBox_2->setEnabled(true);
}


void enrolled_courses::on_allcourse_button_clicked()
{
    ui->comboBox->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
}

