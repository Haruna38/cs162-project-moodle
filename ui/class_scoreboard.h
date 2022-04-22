#ifndef CLASS_SCOREBOARD_H
#define CLASS_SCOREBOARD_H

#include <QMainWindow>
#include "structure.h"

namespace Ui {
class class_scoreboard;
}

class class_scoreboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit class_scoreboard(QWidget *parent = nullptr);
    ~class_scoreboard();
    void StudentTableDisplay(Class myClass, School mySchool);

private:
    Ui::class_scoreboard *ui;
};

#endif // CLASS_SCOREBOARD_H
