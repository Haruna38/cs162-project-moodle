#include "ui/course_create.h"
#include "ui_course_create.h"
#include "operating_function/BeginingOfSem.h"
using namespace std;

Course_Create::Course_Create(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Course_Create)
{
    ui->setupUi(this);
    ifstream fin; fin.open("schoolyear.txt");
    string tmp = "";
    while (fin >> tmp)
        ui->cbbSchoolyear->addItem(QString::fromUtf8(tmp));
    fin.close();
}

Course_Create::~Course_Create()
{
    delete ui;
}

void Course_Create::on_btnSave_3_clicked()
{
    int semester_x = (ui->cbbSem->itemData(ui->cbbSem->currentIndex())).toInt();
    string startdate_x = ui->dedStart->date().toString("dd/MM/yyyy").toStdString();
    string enddate_x = ui->dedEnd->date().toString("dd/MM/yyyy").toStdString();
    int schoolyear_x = (ui->cbbSchoolyear->itemData(ui->cbbSchoolyear->currentIndex())).toInt();

    createSemester(semester_x, startdate_x, enddate_x, schoolyear_x);
}

