#ifndef SEECLASSINFO_H
#define SEECLASSINFO_H

#include <QMainWindow>

namespace Ui {
class seeClassInfo;
}

class seeClassInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit seeClassInfo(QWidget *parent = nullptr, std::string classID = "");
    ~seeClassInfo();

private:
    Ui::seeClassInfo *ui;
    void showStudentInClass();
};

#endif // SEECLASSINFO_H
