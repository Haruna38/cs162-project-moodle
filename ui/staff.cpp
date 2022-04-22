#include "staff.h"
#include "ui_staff.h"
#include "utils.h"
#include "fakeallcourselist.h"
#include "school.h"

staff::staff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff)
{
    ui->setupUi(this);

    sch = new school;
    courseList = new fakeAllCourseList;

    connect(ui->my_profile_button, SIGNAL(clicked()), this, SLOT(showMyProfile()));
    connect(ui->courses_button, SIGNAL(clcked()), this, SLOT(showAllCourses()));
    connect(ui->school_button, SIGNAL(clicked()), this, SLOT(showSchoolOptions()));
}

staff::~staff()
{
    delete ui;
}

Manager *manager = new Manager;

void staff::showMyProfile () {
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(manager->getUser("21125112")));
    msgBox.exec();
}

void staff::showAllCourses () {
    courseList->show();
    this->close();
}

void staff::showSchoolOptions () {
    sch->show();
    this->close();
}

