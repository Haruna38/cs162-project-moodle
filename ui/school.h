#ifndef SCHOOL_H
#define SCHOOL_H

#include <QMainWindow>

namespace Ui {
class school;
}

class school : public QMainWindow
{
    Q_OBJECT

public:
    explicit school(QWidget *parent = nullptr);
    ~school();

private:
    Ui::school *ui;
};

#endif // SCHOOL_H
