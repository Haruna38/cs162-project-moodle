//Finished

#include "ui/student.h"
#include "ui_student.h"
#include <ctime>
#include "ui/enrollingcourse_page.h"
#include "operating_function/database_function.hpp"
#include "ui/enrolled_courses.h"
#include "ui/studentscore.h"
#include "operating_function/general_function.hpp"

#include <QMessageBox>

#include "global.h"

void student::closeEvent (QCloseEvent *event)
{
   saveDatabase(mySchool);
   event->accept();
   QCoreApplication::quit();
}

student::student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
}

student::~student()
{
    delete ui;
}

void student::on_enroll_course_clicked()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    string currentDate = to_string(now->tm_year+1900) + "/" + to_string(now->tm_mon+1) + "/" + to_string(now->tm_mday);
    if (isInEnrollingTime(currentDate, now->tm_hour, now->tm_min, now->tm_sec)) {
        enrollingcourse_page* gotoECP = new enrollingcourse_page;
        gotoECP->show();
    }
    else QMessageBox::information(this, tr("Fail!"), tr("The current time is not in the registration time."));
}


void student::on_courses_button_clicked()
{
    enrolled_courses* gotoEC = new enrolled_courses(nullptr, mySchool.getStudent(current_id));
    gotoEC->show();
}

void student::on_view_score_clicked()
{
    studentScore* gotoSS = new studentScore(nullptr, mySchool.getStudent(current_id));
    gotoSS->show();
}


void student::on_my_profile_button_clicked()
{
    Student *st = mySchool.getStudent(current_id);
    std::string info = "Student ID: " + to_string(st->studentID) + "\n"
            + "Name: " + st->firstName + " " + st->lastName + "\n"
            + "Gender: " + (st->gender ? "Male" : "Female") + "\n"
            + "Date of birth: " + st->dateOfBirth + "\n"
            + "Social ID: " + to_string(st->socialID);
    QMessageBox::information(this, tr("User Information"), QString::fromUtf8(info));
}

