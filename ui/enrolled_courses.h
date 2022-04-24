#ifndef ENROLLED_COURSES_H
#define ENROLLED_COURSES_H

#include <QMainWindow>
#include "operating_function/structure.h"

namespace Ui {
class enrolled_courses;
}

class enrolled_courses : public QMainWindow
{
    Q_OBJECT

public:
    explicit enrolled_courses(QWidget *parent = nullptr, Student* thisStudent = nullptr);
    ~enrolled_courses();


private:
    Ui::enrolled_courses *ui;
    void CustomTableDisplay(int schoolyear_x, int semester_x);
    void AllCourseTableDisplay();


private slots:
    void on_searchcourse_button_clicked();
    void on_customcourse_button_clicked();
    void on_allcourse_button_clicked();
};

#endif // ENROLLED_COURSES_H
