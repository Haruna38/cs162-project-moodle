#include "ui/mainwindow.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include "./ui_mainwindow.h"
#include "ui/staff.h"
#include "operating_function//login_function.h"
using namespace std;

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    staffWindow = new staff;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string username = (ui->usernameInput->text()).toStdString();
    string password = (ui->passwordInput->text()).toStdString();
    if (login(username, password))  {
            staffWindow->show();
    }
    else QMessageBox::information(this, tr("Fail to login"), tr("You've entered wrong username or password"));
}
