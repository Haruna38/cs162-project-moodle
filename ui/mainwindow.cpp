#include <fstream>
#include <iostream>
#include <QMessageBox>
#include "global.h"
#include "ui/mainwindow.h"
#include "ui/staff.h"
#include "ui/student.h"
#include "./ui_mainwindow.h"
#include "operating_function/database_function.hpp"
#include "operating_function/login_function.h"
#include "operating_function/general_function.hpp"
using namespace std;

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string username = (ui->usernameInput->text()).toStdString();
    string password = (ui->passwordInput->text()).toStdString();
    if (login(username, password)) {
            current_id = stoi(username);
            loadDatabase(mySchool);
            if () {
                staff* staffWindow = new staff;
                staffWindow->show();
            }
            else {
                student* newStudentStartPage = new student;
                newStudentStartPage->show();
            }
    }
    else QMessageBox::information(this, tr("Fail to login"), tr("You've entered wrong username or password"));
}
