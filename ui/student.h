#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    ~student();

private:
    Ui::student *ui;
};

#endif // STUDENT_H
