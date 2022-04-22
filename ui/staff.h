#ifndef STAFF_H
#define STAFF_H

#include <QMainWindow>
#include <QDialog>
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

private:
    Ui::staff *ui;
    school* sch;
    // fakeAllCourseList* courseList;
};

#endif // STAFF_H
