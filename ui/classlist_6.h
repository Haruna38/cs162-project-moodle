#ifndef CLASSLIST_6_H
#define CLASSLIST_6_H

#include "operating_function/structure.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class classlist_6; }
QT_END_NAMESPACE

class classlist_6 : public QMainWindow
{
    Q_OBJECT

public:
    classlist_6(QWidget *parent = nullptr);
    ~classlist_6();
private slots:

    void on_tableWidget_itemSelectionChanged();

    void on_tableWidget_cellClicked(int row, int column);

    void on_view_class_clicked();

    void on_edit_class_clicked();

    void on_remove_class_clicked();

private:
    Ui::classlist_6 *ui;
    void ClassTableDisplay(School mySchool);
};
#endif // CLASSLIST_6_H
