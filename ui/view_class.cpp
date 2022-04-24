#include"addnewclass.h"
#include"ui_addnewclass.h"
#include"addnewstudent.h"
#include"ui_addnewstudent.h"
#include"view_class.h"
#include"ui_view_class.h"
Class *class_x ;
view_class::view_class(QWidget *parent, Class *clss) :
    QMainWindow(parent),
    ui(new Ui::view_class)
{
    ui->setupUi(this);
    class_x = clss ;
}

view_class::~view_class()
{
    delete ui;
}
void view_class::ViewClassTableDisplay() {
   ui->classlineEdit->setText(QString::fromUtf8(class_x->classID)) ;
    Student *cur = class_x->monitor ;
    while (cur->nextStudent) {
        cur = cur->nextStudent;
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem* item;
            for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
                item = new QTableWidgetItem;
                switch(i) {
                               case 0:
                                    item->setText(QString::number(ui->tableWidget->rowCount()));
                                     break;
                                case 1:
                                     item->setText(QString::number(cur->studentID));
                                      break;
                                case 2 :
                                     item->setText(QString::fromUtf8(cur->firstName));
                                        break;
                                case 3 :
                                     item->setText(QString::fromUtf8(cur->lastName));
                                        break;
                                case 4 :
                                      item->setText(QString::fromUtf8((cur->gender==1) ? "Male" : "Female" ))  ;
                                        break;
                                case 5 :
                                      item->setText(QString::fromUtf8(cur->dateOfBirth)) ;
                                         break ;
                                case 6 :
                                      item->setText(QString::number(cur->socialID)) ;
                                         break ;
                }
             }
    }
}
