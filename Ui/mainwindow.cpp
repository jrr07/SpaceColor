#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMouseEvent>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    this->drawType = 0;

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

    this->drawType = 0;


    cout << "nothing button pressed!" << endl;
}


void MainWindow::lineButtonPressed(){


    this->drawType = 1;
    cout << drawType << endl;
    cout << "line button pressed" << endl;
    list.append(new Line(20,20,30,30,true));
}


void MainWindow::circleButtonPressed(){

    this->drawType = 2;
    cout << drawType << endl;
    cout << "circle button pressed" << endl;
    list.append(new Circle(20,20,30,true));
}

void MainWindow::mousePressEvent(QMouseEvent *event){
   cout << "mouse pressed " << event->x()<<  endl << event->y()  << endl;
    if(this->drawType == 1) {

    }
}

