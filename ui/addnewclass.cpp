#include "ui/addnewclass.h"
#include "ui_addnewclass.h"
#include "operating_function/structure.h"
#include "ui/addnewstudent.h"
#include "cs162-project-moodle-main/global.h"

#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

AddNewClass::AddNewClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewClass)
{
    ui->setupUi(this);
}

AddNewClass::~AddNewClass()
{
    delete ui;
}

void AddNewClass::on_addStudentBtt_clicked()
{
    addnewstudent* ansWindow = new addnewstudent(nullptr, ui);
    ansWindow->show();
}


void AddNewClass::on_tableWidget_cellClicked(int row, int column)
{
    ui->updateStudentBtt->setEnabled(true);
    ui->removeStudentBtt->setEnabled(true);
}


void AddNewClass::on_tableWidget_itemSelectionChanged()
{
    ui->updateStudentBtt->setEnabled(false);
    ui->removeStudentBtt->setEnabled(false);
}

void AddNewClass::on_saveBtt_clicked()
{
    Class* newClass = new Class();
    newClass->classID = ui->classlineEdit->text().toStdString();
    for (int i = 1; i < ui->tableWidget->rowCount(); i++) {
        Student* newStudent = new Student();
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            switch(j) {
            case 0:
                newStudent->No = ui->tableWidget->item(i, j)->text().toLongLong();
                break;
            case 1:
                newStudent->studentID = ui->tableWidget->item(i, j)->text().toInt();
                break;
            case 2:
                newStudent->firstName = ui->tableWidget->item(i, j)->text().toStdString();
                break;
            case 3:
                newStudent->lastName = ui->tableWidget->item(i, j)->text().toStdString();
                break;
            case 4:
                newStudent->gender = ((ui->tableWidget->item(i, j)->text().toStdString() == "Male") ? 1 : 0);
                break;
            case 5:
                newStudent->dateOfBirth = (ui->tableWidget->item(i, j))->text().toStdString();
                break;
            case 6:
                newStudent->socialID = (ui->tableWidget->item(i, j)->text().toLongLong());
            }
        }
        newClass->addNewStudent(newStudent);
    }
    mySchool.allClasses.addNewClass(newClass);
    this->close();
}

std::string AddNewClass::openFile()
{
    QString filename = QFileDialog::getOpenFileName(
                nullptr,
                QObject::tr("Open Document"),
                QDir::currentPath(),
                QObject::tr("Document files (*.csv)"));
    return filename.toStdString();
}

void AddNewClass::createClassListByFile(School& mySchool, string classID_x, string filename) {
    Class* newClass = new Class();
    newClass->classID = classID_x;
    ifstream fin; fin.open(filename);
    while (!fin.eof()) {
        Student* newStudent = new Student();
        //fin >> newStudent->No >> newStudent->studentID >> newStudent->firstName >> newStudent->lastName >> newStudent->dateOfBirth >> newStudent->socialID ;
        newClass->addNewStudent(newStudent);
        QTableWidgetItem* item;
        for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
            item = new QTableWidgetItem;
            switch(i) {
                case 0:
                    item->setText(QString::number(newStudent->No));
                    break;
                case 1:
                    item->setText(QString::number(newStudent->studentID));
                    break;
                case 2:
                    item->setText(QString::fromUtf8(newStudent->firstName));
                    break;
                case 3:
                    item->setText(QString::fromUtf8(newStudent->lastName));
                break;
                case 4:
                    item->setText(QString::fromUtf8((newStudent->gender == 0) ? "Female" : "Male"));
                    break;
                case 5:
                    item->setText(QString::fromUtf8(newStudent->dateOfBirth));
                    break;
                case 6:
                    item->setText(QString::number(newStudent->socialID));
                    break;
            }
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, item);
        }
    }
    mySchool.allClasses.addNewClass(newClass);
}


void AddNewClass::on_uploadFileBtt_clicked()
{
    string filename = openFile();
    createClassListByFile(mySchool,  ui->classlineEdit->text().toStdString(), filename);
}

