#include "staff.h"
#include "ui_staff.h"
#include "school.h"

staff::staff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff)
{
    ui->setupUi(this);

    sch = new school;
    // courseList = new fakeAllCourseList;
}

staff::~staff()
{
    delete ui;
}

