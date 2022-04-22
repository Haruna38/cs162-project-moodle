#ifndef ENROLLINGCOURSE_PAGE_H
#define ENROLLINGCOURSE_PAGE_H

#include <QMainWindow>

#include "operating_function/structure.h"

namespace Ui {
class enrollingcourse_page;
}

class enrollingcourse_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit enrollingcourse_page(QWidget *parent = nullptr);
    ~enrollingcourse_page();

private slots:

    void on_availableCourseTable_cellClicked(int row, int column);

    void on_availableCourseTable_itemSelectionChanged();

    void on_enrollBtt_clicked();

    void on_enrolledCourseTable_cellClicked(int row, int column);

    void on_enrolledCourseTable_itemSelectionChanged();

    void on_saveBtt_clicked();

    void on_removeBtt_clicked();

private:
    Ui::enrollingcourse_page *ui;
    void showAllAvailableCourse(School mySchool);
    bool compareCourse(Course* course);
};

#endif // ENROLLINGCOURSE_PAGE_H
