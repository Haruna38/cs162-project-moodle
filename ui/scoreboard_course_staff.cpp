#include "ui/scoreboard_course_staff.h"
#include "ui_scoreboard_course_staff.h"

#include "global.h"

Course* course = nullptr;

void scoreboard_course_staff::loadScoreBoard(Course* thisCourse)
{
    score* curScore = thisCourse->courseScoreBoard.monitor;
    while (curScore->nextScore) {
        curScore = curScore->nextScore;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem* item;
        for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
            item = new QTableWidgetItem;
            switch(i) {
                case 0:
                    item->setText(QString::number(ui->tableWidget->rowCount()));
                    break;
                case 1:
                    item->setText(QString::number(curScore->studentInform->studentID));
                    break;
                case 2:
                    Student* thisStudent;
                    thisStudent = mySchool.getStudent(curScore->studentInform->studentID);
                    item->setText(QString::fromUtf8(thisStudent->firstName + " " + thisStudent->lastName));
                    break;
                case 3:
                    item->setText(QString::number(curScore->totalMark));
                    break;
                case 4:
                    item->setText(QString::number(curScore->finalMark));
                    break;
                case 5:
                    item->setText(QString::number(curScore->midtermMark));
                    break;
                case 6:
                    item->setText(QString::number(curScore->otherMark));
                    break;
            }

        }
    }
}

scoreboard_course_staff::scoreboard_course_staff(QWidget *parent, Course* thisCourse) :
    QMainWindow(parent),
    ui(new Ui::scoreboard_course_staff)
{
    ui->setupUi(this);
    course = thisCourse;
    loadScoreBoard(course);
}

scoreboard_course_staff::~scoreboard_course_staff()
{
    delete ui;
}



void scoreboard_course_staff::tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->updatescore_button->setEnabled(true);
    ui->removescore_button->setEnabled(true);
}


void scoreboard_course_staff::on_updatescore_button_clicked()
{

}

void scoreboard_course_staff::on_removescore_button_clicked()
{
    int current_row = ui->tableWidget->currentRow();
    course->courseScoreBoard.deleteScore(current_row);
    ui->tableWidget->setRowCount(0);
    loadScoreBoard(course);
}

