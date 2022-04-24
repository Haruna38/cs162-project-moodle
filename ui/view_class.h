#ifndef VIEW_CLASS_H
#define VIEW_CLASS_H
#include"structure.h"
#include <QMainWindow>
#include"classlist_6.h"
#include"ui_classlist_6.h"
namespace Ui {
class view_class;
}

class view_class : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_class(QWidget *parent = nullptr, Class *clss = nullptr);
    ~view_class();

private:
    Ui::view_class *ui;
    void ViewClassTableDisplay();
};

#endif // VIEW_CLASS_H
