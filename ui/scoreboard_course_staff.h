#ifndef SCOREBOARD_COURSE_STAFF_H
#define SCOREBOARD_COURSE_STAFF_H

#include <QMainWindow>
#include <QTableWidgetItem>

#include "cs162-project-moodle-main/structure.h"

namespace Ui {
class scoreboard_course_staff;
}

class scoreboard_course_staff : public QMainWindow
{
    Q_OBJECT

public:
    explicit scoreboard_course_staff(QWidget *parent = nullptr, Course* thisCourse = nullptr);
    ~scoreboard_course_staff();

private slots:
    void tableWidget_itemClicked(QTableWidgetItem *item);

    void on_updatescore_button_clicked();

    void on_removescore_button_clicked();

private:
    Ui::scoreboard_course_staff *ui;
    void loadScoreBoard(Course* thisCourse);
};

#endif // SCOREBOARD_COURSE_STAFF_H
