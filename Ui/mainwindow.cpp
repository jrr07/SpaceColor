#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMouseEvent>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    this->drowType = 0;

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

    this->drowType = 0;


    cout << "nothing button pressed!" << endl;
}


void MainWindow::lineButtonPressed(){

    this->drowType = 1;

    cout << "line button pressed" << endl;

}


void MainWindow::circleButtonPressed(){

    this->drowType = 2;

    cout << "circle button pressed" << endl;

}

void MainWindow::mousePressEvent(QMouseEvent *event){
    cout << "mouse pressed " << event->x()<<  endl << event->y()  << endl;
}

