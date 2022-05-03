//Finished

#include "ui/staff.h"
#include "ui_staff.h"
#include "global.h"
#include "operating_function/database_function.hpp"
#include "ui/school.h"
#include "ui/coursepage.h"
#include <fstream>

staff::staff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff)
{
    ui->setupUi(this);

    sch = new school;
    // courseList = new fakeAllCourseList;
}



void staff::closeEvent (QCloseEvent *event)
{
   saveDatabase(mySchool);
   event->accept();
   QCoreApplication::quit();
}

staff::~staff()
{
    delete ui;
}

void staff::on_school_button_clicked()
{
    school* gotoSchool = new school;
    gotoSchool->show();
}

void staff::on_courses_button_clicked()
{
    coursePage* gotoCI = new coursePage;
    gotoCI->show();
}


void staff::on_my_profile_button_clicked()
{
    Student *st = mySchool.getStudent(current_id);
    ifstream fin ("staff/" + to_string(current_id) + ".txt");
    if (fin.fail()) return void (QMessageBox::information(this, tr("Failed"), tr("Failed to get user info")));
    std::string info = "";
    string data;
    getline(fin, data);
    getline(fin, data);
    info += "Name: " + data + " ";
    getline(fin, data);
    info += data + "\n";
    getline(fin, data);
    string gender = data == "1" ? "Male" : "Female";
    info += "Gender: " + gender + "\n";
    getline(fin, data);
    info += "Date of birth: " + data + "\n";
    getline(fin, data);
    info += "Social ID: " + data;
    QMessageBox::information(this, tr("User Information"), QString::fromUtf8(info));
}

