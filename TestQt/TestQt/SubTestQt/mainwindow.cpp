#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox mb(this);//()
    mb.setText("This is a messagebox!!");
    mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    mb.setInformativeText("This is an informative Text!!");
    mb.exec();
}
