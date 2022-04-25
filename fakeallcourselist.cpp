#include "fakeallcourselist.h"
#include "ui_fakeallcourselist.h"

fakeAllCourseList::fakeAllCourseList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fakeAllCourseList)
{
    ui->setupUi(this);
}

fakeAllCourseList::~fakeAllCourseList()
{
    delete ui;
}
