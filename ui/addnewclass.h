#ifndef ADDNEWCLASS_H
#define ADDNEWCLASS_H

#include <QMainWindow>
#include "operating_function/structure.h"

namespace Ui {
class AddNewClass;
}

class AddNewClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewClass(QWidget *parent = nullptr);
    ~AddNewClass();
    Ui::AddNewClass *ui;

private slots:

    void on_addStudentBtt_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_itemSelectionChanged();

    void on_saveBtt_clicked();

    void on_uploadFileBtt_clicked();

private:
    std::string openFile();
    void createClassListByFile(School& mySchool, string classID_x, string filename);
};

#endif // ADDNEWCLASS_H
