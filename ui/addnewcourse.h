#ifndef ADDNEWCOURSE_H
#define ADDNEWCOURSE_H

#include <QMainWindow>
#include "ui/course_update.h"
#include "ui_course_update.h"

namespace Ui {
class AddNewCourse;
}

class AddNewCourse : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewCourse(QWidget *parent = nullptr, Ui::course_update* ancUI = nullptr);
    void addtoTableDisplayAllCourses(std::string courseID_x, std::string coursename_x, int sem_x, std::string schoolyear);
    //void savetoHCMUSAllCourses(std::string courseID_x, std::string coursename_x, std::string lecturer_x, int credits_x, int capacity, int day1, int day2, int session1, int session2, int schoolyear_x, int sem_x);
    int DayStringtoInt(std::string dayString);
    ~AddNewCourse();

private slots:
    void on_btnSave_clicked();

private:
    Ui::AddNewCourse *ui;
};

#endif // ADDNEWCOURSE_H
