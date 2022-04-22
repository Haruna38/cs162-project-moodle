#ifndef COURSE_UPDATE_H
#define COURSE_UPDATE_H

#include <QMainWindow>
#include "operating_function/structure.h"

namespace Ui {
class course_update;
}

class course_update : public QMainWindow
{
    Q_OBJECT

public:
    Ui::course_update *ui;
    explicit course_update(QWidget *parent = nullptr);
    ~course_update();

private slots:
    void on_btnAddNewCourse_clicked();

private:

    void AllCourseTableDisplay();
};

#endif // COURSE_UPDATE_H
