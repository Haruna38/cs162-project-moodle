#include "ui/class_scoreboard.h"
#include "./ui_class_scoreboard.h"

design14::design14(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::design14)
{
    ui->setupUi(this);
}

design14::~design14()
{
    delete ui;
}

void design14::StudentTableDisplay(Class myClass, School mySchool)
{
    Student* cur = myClass.monitor;
    QTableWidget *table = ui->tableWidget;
        while (cur->nextStudent) {
            cur = cur->nextStudent;
            table->insertRow(table->rowCount());
            QTableWidgetItem* item;
            for (int i = 0; i < table->columnCount(); i++) {
                item = new QTableWidgetItem;
                switch(i) {
                    case 0:
                        item->setText(QString::number(table->rowCount()));
                            break;
                    case 1:
                            item->setText(QString::number(cur->studentID));
                            break;
                    case 2 :
                            item->setText(QString::fromUtf8(cur->firstName));
                            break;
                    case 3 :
                        item->setText(QString::fromUtf8(cur->lastName));
                            break;
                }
                table->setItem(table->rowCount() - 1, i, item);
            }
            enrolledCourses courseList = cur->myCourses;
            enrolledCourse *course = courseList.monitor;
            int count = 0, marks = 0;
            while (course->nextEnrolledCourse != NULL) {
                course = course->nextEnrolledCourse;
                Course *allCourses = mySchool.allCourses.monitor;
                Course *selectedCourse = NULL;
                while (allCourses->nextCourse != NULL) {
                    allCourses = allCourses->nextCourse;
                    if (allCourses->courseID == *course->courseID) {
                        selectedCourse = allCourses;
                        score *board = allCourses->courseScoreBoard.getScoreOfStudent(cur->studentID);
                        if (board == NULL) return;
                        marks += board->finalMark;
                        ++count;
                        QTableWidgetItem *colItem = new QTableWidgetItem;
                        int r, l, x = 0;
                        for (;x < table->columnCount(); ++x) {
                            if (table->horizontalHeaderItem(x)->text().toStdString() == allCourses->courseID) break;
                        }
                        if (x >= table->columnCount()) {
                            x = table->columnCount() - 2;
                            QTableWidgetItem *header = new QTableWidgetItem;
                            header->setText(QString::fromUtf8(allCourses->courseID));
                            table->insertColumn(x);
                            table->setHorizontalHeaderItem(x, header);
                        }
                        colItem->setText(QString::number(board->finalMark));
                        table->setItem(table->rowCount() - 1, x, colItem);
                        break;
                    }
                }
                if (selectedCourse == NULL) return;
            }
            if (count > 0) {
                QTableWidgetItem *gpa = new QTableWidgetItem;
                gpa->setText(QString::number(marks / count));
            }
        }
}

