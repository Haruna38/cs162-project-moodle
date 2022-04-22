#ifndef COURSE_CREATE_H
#define COURSE_CREATE_H

#include <QMainWindow>
#include "cs162-project-moodle-main/BeginingOfSem.h"
using namespace std;

namespace Ui {
class Course_Create;
}

class Course_Create : public QMainWindow
{
    Q_OBJECT

public:
    explicit Course_Create(QWidget *parent = nullptr);
    ~Course_Create();

private slots:
    void on_btnSave_3_clicked();

private:
    Ui::Course_Create *ui;
};

#endif // COURSE_CREATE_H
