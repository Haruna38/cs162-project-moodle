#include "ui/addnewcourse.h"
#include "ui_addnewcourse.h"
#include "operating_function/structure.h"
#include "cs162-project-moodle-main/global.h"
#include "ui_course_update.h"

#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

Ui::course_update* ancUI_x;
School HCMUS;

AddNewCourse::AddNewCourse(QWidget *parent, Ui::course_update* ancUI) :
    QMainWindow(parent),
    ui(new Ui::AddNewCourse)
{
    ui->setupUi(this);
    ancUI_x = ancUI;
}

AddNewCourse::~AddNewCourse()
{
    delete ui;
}

void savetoHCMUSAllCourses(std::string courseID_x, std::string coursename_x, std::string lecturer_x, int credits_x, int capacity, int day1, int day2, int session1, int session2, int schoolyear_x, int sem_x) {
    Course* newCourse = new Course;
    newCourse->courseID = courseID_x;
    newCourse->courseName = coursename_x;
    newCourse->teacherName = lecturer_x;
    newCourse->numberofCredit = credits_x;
    newCourse->maxStudent = capacity;
    newCourse->day[0] = day1;
    newCourse->day[1] = day2;
    newCourse->session[0] = session1;
    newCourse->session[1] = session2;
    newCourse->schoolyear = schoolyear_x;
    newCourse->semester = sem_x;
    HCMUS.allCourses.addNewCourse(newCourse);
}


void AddNewCourse::on_btnSave_clicked()
{
        std::string courseID_x = (ui->lnedCourseID->text()).toStdString();
        std::string coursename_x = (ui->lnedCourseName->text()).toStdString();
        std::string lecturer_x = (ui->lnedLecturer->text()).toStdString();
        int credits_x = (ui->spbxCredits->text()).toInt();
        int capacity = (ui->spbxCapacity->text()).toInt();
        std::string day;
        day = (ui->cbbxDay1->currentText()).toStdString();
        int day1 = (ui->cbbxDay1-)
        day = (ui->cbbxDay2->currentText()).toStdString();
        int day2 = DayStringtoInt(day);
        std::string session;
        session = (ui->cbbxSession1->currentText()).toStdString();
        int session1 = session[0] - 48;
        int session2 = session[0] - 48;
        int sem_x = (ui->lblSem->text()).toInt();
        std::string schoolyear = (ui->lblSchoolyear->text()).toStdString();
        int schoolyear_x = stoi(schoolyear.substr(0, 5));

        savetoHCMUSAllCourses(courseID_x, coursename_x, lecturer_x, credits_x, capacity, day1, day2, session1, session2, schoolyear_x, sem_x);
        addtoTableDisplayAllCourses(courseID_x, coursename_x, sem_x, schoolyear);

        this->close();
}

int AddNewCourse::DayStringtoInt(std::string dayString) {
    int dayInt;
    switch(dayString[1]){
    case 'o':{
        dayInt = 2;
        break;
    }
    case 'u': {
        dayInt = 3;
        break;
    }
    case 'e' : {
        dayInt = 4;
        break;
    }
    case 'h' : {
        dayInt = 5;
        break;
    }
    case 'r' : {
        dayInt = 6;
        break;
    }
    case 'a' : {
        dayInt = 7;
        break;
    }
    };
    return dayInt;
}

void AddNewCourse::addtoTableDisplayAllCourses(std::string courseID_x, std::string coursename_x, int sem_x, std::string schoolyear) {
    ancUI_x->tableDisplayAllCourses->insertRow(ancUI_x->tableDisplayAllCourses->rowCount());
    QTableWidgetItem* item;
    for (int i = 0; i < ancUI_x->tableDisplayAllCourses->columnCount(); i++) {
        item = new QTableWidgetItem;
        switch(i) {
            case 0:
                item->setText(QString::number(ancUI_x->tableDisplayAllCourses->rowCount()));
                break;
            case 1:
                item->setText(QString::fromUtf8(courseID_x));
                break;
            case 2:
                item->setText(QString::fromUtf8(coursename_x));
                break;
            case 3:
                item->setText(QString::number(sem_x));
            break;
            case 4:
                item->setText(QString::fromUtf8(schoolyear));
                break;
        }
        ancUI_x->tableDisplayAllCourses->setItem(ancUI_x->tableDisplayAllCourses->rowCount()-1, i, item);
    }
}
