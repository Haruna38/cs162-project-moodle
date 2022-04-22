#include "course_infor.h"
#include "ui_course_infor.h"
#include"structure.h"
course_infor::course_infor(QWidget *parent , Course* course) :
    QMainWindow(parent),
    ui(new Ui::course_infor)
{
    ui->setupUi(this);
    thisCourse = course;
    ui->course_id->setText(QString::fromUtf8(thisCourse->courseID));
    ui->course_name->setText(QString::fromUtf8(thisCourse->courseName));
    ui->teacher_course->setText(QString::fromUtf8(thisCourse->teacherName));
    ui->num_student->setText(QString::number(thisCourse->maxStudent));
    ui->numOfCredit->setText(QString::number(thisCourse->numberofCredit));
}

course_infor::~course_infor()
{
    delete ui;
}
