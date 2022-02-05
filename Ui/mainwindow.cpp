#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    connect(ui->nothingButton, &QPushButton::pressed, this, &MainWindow::nothingButtonPressed);

    connect(ui->lineButton, &QPushButton::pressed, this, &MainWindow::lineButtonPressed);

    connect(ui->circleButton, &QPushButton::pressed, this, &MainWindow::circleButtonPressed);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nothingButtonPressed(){

    cout << "nothing button pressed!" << endl;



}


void MainWindow::lineButtonPressed(){

    cout << "line button pressed" << endl;

}


void MainWindow::circleButtonPressed(){

    cout << "circle button pressed" << endl;

}

