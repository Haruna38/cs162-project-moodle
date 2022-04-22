#include "ui/staff.h"
#include "ui_staff.h"
#include "ui/school.h"

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

