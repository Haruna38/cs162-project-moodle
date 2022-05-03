#ifndef STAFF_H
#define STAFF_H

#include <QMainWindow>
#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>

#include "ui/school.h"

namespace Ui {
class staff;
}

class staff : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff(QWidget *parent = nullptr);
    ~staff();

private slots:
    void on_school_button_clicked();

    void on_courses_button_clicked();

    void on_my_profile_button_clicked();

private:
    Ui::staff *ui;
    school* sch;
    void closeEvent(QCloseEvent* event);
    // fakeAllCourseList* courseList;
};

#endif // STAFF_H
