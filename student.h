#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    ~student();

private slots:
    void on_enroll_course_clicked();

    void on_courses_button_clicked();

    void on_view_score_clicked();

    void on_my_profile_button_clicked();

private:
    Ui::student *ui;
    void closeEvent(QCloseEvent* event);
};

#endif // STUDENT_H
