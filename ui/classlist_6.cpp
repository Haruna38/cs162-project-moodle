#include "ui/classlist_6.h"
#include "./ui_classlist_6.h"
#include "operating_function/structure.h"

classlist_6::classlist_6(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::classlist_6)
{
    ui->setupUi(this);
}

classlist_6::~classlist_6()
{
    delete ui;
}
void classlist_6::ClassTableDisplay(School mySchool) {
    Class* cur = mySchool.allClasses.monitor;
        while (cur->nextClass) {
            cur = cur->nextClass;
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem* item;
                for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
                    item = new QTableWidgetItem;
                    switch(i) {
                                   case 0:
                                        item->setText(QString::number(ui->tableWidget->rowCount()));
                                         break;
                                    case 1:
                                         item->setText(QString::fromUtf8(cur->classID));
                                          break;
                                    case 2 :
                                         item->setText(QString::number(cur->sizeOfClass));
                                            break;
                    }
                 }
        }
}
int clssRow = -1 , clssCol = -1 ;
string classID_x = "";


void classlist_6::on_tableWidget_itemSelectionChanged()
{
    ui->view_class->setEnabled(false);
    ui->edit_class->setEnabled(false);
    ui->remove_class->setEnabled(false);
}





void classlist_6::on_tableWidget_cellClicked(int row, int column)
{
    ui->view_class->setEnabled(true);
    ui->edit_class->setEnabled(true);
    ui->remove_class->setEnabled(true);
    clssRow = row ;
}


void classlist_6::on_view_class_clicked()
{
    string classID_x =ui->tableWidget->item(clssRow,1)->text().toStdString() ;
    view_class *ansWindow = new view_class(nullptr,mySchool.getClass(classID_x)) ;
    ansWindow->show() ;
}



void classlist_6::on_edit_class_clicked()
{
    string classID_x =ui->tableWidget->item(clssRow,clssCol)->text().toStdString() ;

}


void classlist_6::on_remove_class_clicked()
{
    string classID_x =ui->tableWidget->item(clssRow,clssCol)->text().toStdString();
    ui->tableWidget->removeRow(clssRow) ;
}
