#include "ui/school.h"
#include "ui_school.h"

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
