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

private slots:
    void on_classes_button_clicked();

    void on_create_semester_clicked();

private:
    Ui::school *ui;
};

#endif // SCHOOL_H
