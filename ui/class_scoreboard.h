#ifndef DESIGN14_H
#define DESIGN14_H

#include <QMainWindow>
#include "operating_function/structure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class design14; }
QT_END_NAMESPACE

class design14 : public QMainWindow
{
    Q_OBJECT

public:
    design14(QWidget *parent = nullptr);
    ~design14();
    void StudentTableDisplay(Class myClass, School mySchool);

private:
    Ui::design14 *ui;
};
#endif // DESIGN14_H
