#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMouseEvent>
#include <QPainter>

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

    connect(ui->rectangleButton, &QPushButton::pressed, this, &MainWindow::rectangleButtonPressed);
}


MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < this-> list.count(); i ++ ){
        Figure* figure = this-> list.at(i);
        delete figure;
    }
    list.clear();
}

void MainWindow::nothingButtonPressed(){

    this->drawType = 0;


    cout << "nothing button pressed!" << endl;
}


void MainWindow::lineButtonPressed(){


    this->drawType = 1;
    cout << drawType << endl;
    cout << "line button pressed" << endl;
}


void MainWindow::circleButtonPressed(){

    this->drawType = 2;
    cout << drawType << endl;
    cout << "circle button pressed" << endl;
}

void MainWindow::rectangleButtonPressed(){

    this->drawType = 3;
    cout << drawType << endl;
    cout << "rectangle button pressed" << endl;
}
//1. 마우스 버튼을 눌렀을ㄸㅐ
void MainWindow::mousePressEvent(QMouseEvent *event){
   cout << "mouse pressed " << event->x()<<  endl << event->y()  << endl;

   //1.1. drawtype이 1일ㄸㅐ
   if(this->drawType == 1) {
       //1.1.1. 라인을 생성하고 리스트에 넣는다
       this->list.append(new Line(event->x(),event->y(),event->x()+10,event->y()+10,true));
       //1.1.2. 화면을 갱신한다
       this->update();
   }

   //1.2. drawtype이 2일ㄸㅐ
   if(this-> drawType== 2){
       //1.2.1. 서클을 생성하고 리스트에 넣는다
       this->list.append(new Circle(event->x(), event->y(), 50, true));
       //1.2.2. 화면을 갱신한다
       this->update();
    }

   //1.3. drawtype이 3일ㄸㅐ
   if(this-> drawType == 3){
       //1.3.1. rectangle을 리스트에 넣는다
       this->list.append(new Rectangle(event->x(),event->y(), 50, 80,true));
       //1.3.2. 화면을 갱신하다
       this->update();
   }

   //1.4. drawtype이 0일ㄸㅐ
   if(this-> drawType == 0){
       //1.4.1. 리스트 개수만큼 반복한다
       for(int i = 0; i < this-> list.count(); i++){
           //1.4.1.1. i번ㅉㅐ 도형이 마우스 클릭한 좌표에 존재할ㄸㅐ
                //1.4.1.1.1. 메세지 출력(어떠ㄴ 객체가 존재핬는지
                //1.4.1.1.2. 반복문을 탈출한다

       }
   }

}

//1. paintevent가 호출되었을ㄸㅐ
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter p(this);




    //1.1. 리스트 안에 문자를 도형 갯수 만큼 반복한다
    for(int i = 0; i < this->list.count(); i++){
        //1.1.1. i번쨰 도형을 찾는다
        Figure *figure = this->list.at(i);
        //1.1.2. i번ㅉㅐ 도형이 라인일ㄸㅐ
        if(dynamic_cast <Line*> (figure)){
            //1.1.2.1. line을 그려준다
            Line *line = dynamic_cast<Line*>(figure);
            int startX = line->getStartX();
            int startY = line->getStartY();
            int endX = line->getEndX();
            int endY = line->getEndY();
            p.drawLine(startX, startY, endX, endY);
        }

        //1.1.3 i번ㅉㅐ 도형이 서클일ㄸㅐ
        if(dynamic_cast<Circle*> (figure)){
            //1.1.3.1. circle을 그려준다
            Circle *circle = dynamic_cast<Circle*>(figure);
            int x = circle-> getCenterX() - circle->getRadius();
            int y = circle-> getCenterY() - circle->getRadius();
            int w = circle-> getRadius() * 2;
            int h = w;
            p.drawEllipse(x, y, w, h);
        }


        //1.1.4. i번ㅉㅐ 도형이 사각형일ㄸㅐ
        if(dynamic_cast<Rectangle*>(figure)){
            //1.1.4.1. rectangle을 그려준다
            Rectangle *rectangle = dynamic_cast<Rectangle*>(figure);
            int x = rectangle-> getX();
            int y = rectangle-> getY();
            int w = rectangle-> getWidth();
            int h = rectangle-> getHeight();
            p.drawRect(x, y, w, h);
        }


    }

}
