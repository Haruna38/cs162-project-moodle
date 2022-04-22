#ifndef COURSE_INFOR_H
#define COURSE_INFOR_H

#include "operating_function/structure.h"
#include <QMainWindow>

namespace Ui {
class course_infor;
}

class course_infor : public QMainWindow
{
    Q_OBJECT

public:
    explicit course_infor(QWidget *parent = nullptr, Course* course = NULL);
    ~course_infor();

private:
    Ui::course_infor *ui;
    Course *thisCourse;
};

#endif // COURSE_INFOR_H
