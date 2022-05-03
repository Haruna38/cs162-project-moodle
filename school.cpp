//Finished

#include "ui/school.h"
#include "ui/classlist_6.h"
#include "ui_school.h"
#include "ui/course_create.h"

school::school(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::school)
{
    ui->setupUi(this);
}

school::~school()
{
    delete ui;
}

void school::on_classes_button_clicked()
{
    classlist_6* gotoCL6 = new classlist_6;
    gotoCL6->show();
}

void school::on_create_semester_clicked()
{
    Course_Create* gotoCC = new Course_Create;
    gotoCC->show();
}

