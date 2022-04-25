#ifndef FAKEALLCOURSELIST_H
#define FAKEALLCOURSELIST_H

#include <QMainWindow>

namespace Ui {
class fakeAllCourseList;
}

class fakeAllCourseList : public QMainWindow
{
    Q_OBJECT

public:
    explicit fakeAllCourseList(QWidget *parent = nullptr);
    ~fakeAllCourseList();

private:
    Ui::fakeAllCourseList *ui;
};

#endif // FAKEALLCOURSELIST_H
