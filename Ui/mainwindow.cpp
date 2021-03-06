#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include "Math/myMath.h"
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
}

//1.라인 버튼을 눌렀을ㄸㅐ
void MainWindow::lineButtonPressed(){
    //1.1선택된 도형이 있으면

    if( this-> selectedFigures.count() > 0){
        //1.1.1. 선택해제 한다
        selectedFigures.clear();
        //1.1.2. 화면을 갱신한다
        this->update();
    }

    //1.2. drawtype을 바ㄲㅜㄴ다
    this->drawType = 1;

}


void MainWindow::circleButtonPressed(){
    //2.1선택된 도형이 있으면
    if( this-> selectedFigures.count() > 0){
        //2.1.1. 선택해제 한다
        selectedFigures.clear();
        //2.1.2. 화면을 갱신한다
        this->update();
    }
    //2.2 drawtype을 바ㄲㅜㄴ다
    this->drawType = 2;
}

void MainWindow::rectangleButtonPressed(){
    //3.1선택된 도형이 있으면
    if( this-> selectedFigures.count() > 0){
        //3.1.1. 선택해제 한다
        selectedFigures.clear();
        //3.1.2. 화면을 갱신한다
        this->update();
    }
    //3.2drawtype을 바ㄲㅜㄴ다
    this->drawType = 3;
}

//1. 마우스 버튼을 눌렀을ㄸㅐ
void MainWindow::mousePressEvent(QMouseEvent *event){
    //cout << "mouse pressed " << event->x()<<  endl << event->y()  << endl;

    //1.1. drawtype이 1일ㄸㅐ
    if(this->drawType == 1) {
        //1.1.1. 라인을 생성하고 리스트에 넣는다
        this->list.append(new Line(event->x(),event->y(),event->x() - 200 ,event->y() -40 ,true));
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
            //1.4.1.1. i번ㅉㅐ 위치한 객체를 꺼낸다
            Figure *figure = this ->list.at(i);


            //1.4.1.2. ㄲㅓ낸 객체가 마우스 위에 있을떄
            bool f = figure->checkContain(event->x(), event->y());
            if(f == true){
                bool fi = selectedFigures.contains(figure);

                //1.4.1.2.1 꺼낸 객체가 선택되지 않았을ㄸㅐ
                if(fi == false){
                    //쉬프트 키가 안 눌러진 상태일ㄸㅐ
                    if(!(event->modifiers() & Qt::ShiftModifier)){
                        //1.4.1.2.1.1 객체를 선택

                            this-> selectedFigures.append(figure);
                            //1.4.1.2.1.2 화면을 갱신한다
                            this->update();
                            return;
                    }

                }
                //1.4.1.2.2. 이미 선택된 상태일 ㄸㅐ
                else {
                    //1.4.1.2.2.1쉬프트키가 눌러진 상태일ㄸㅐ
                    if (event->modifiers() & Qt::ShiftModifier){
                        //1.4.1.2.2.1.1 selectedfigures에서 ㅃㅐㄴ다
                        this-> selectedFigures.removeOne(figure);
                        //1.4.1.2.2.1.2 화면을 갱신
                        this->update();
                        return;
                    }
                }
            }
        }
    }
}

//1. 키를 눌렀을ㄸㅐ
void MainWindow::keyPressEvent(QKeyEvent *event) {
    //1.1 drawtype이 0일ㄸㅐ
    if(this->drawType == 0){
        //1.1.1 ctrl A가 눌렸을ㄸㅐ
        if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_A) {
            //1.1.1.1 리스트 개수 만큼 돌린다
            for(int i = 0; i < this-> list.count(); i++) {
                //1.1.1.1.1 i번ㅉㅐ 위치한 객체를 ㄲㅓ낸다
                Figure *figure = this ->list.at(i);
                bool fi = selectedFigures.contains(figure);
                //1.1.1.1.2 선택되지 않은 객체가 있을ㄸㅐ
                if(fi == false){
                    //1.1.1.1.2.1 선택되지 않은 객체를 모두 선택
                    this->selectedFigures.append(figure);
                    //1.1.1.1.2.2 화면 갱신
                    this->update();
                }
            }
        }
        //1.1.2 esc가 눌렸을ㄸㅐ
        else if(event->key() == Qt::Key_Escape){
            //1.1.2.1 selectedfigures를 clear시킨다
            selectedFigures.clear();
            //1.1.2.2 화면을 갱신한다
            this->update();
        }
        //1.1.3 delete가 눌렸을ㄸㅐ
        else if(event->key() == Qt::Key_Delete){
            //1.1.3.1 selectedFigures 반복
            for(int i = 0; i < this-> selectedFigures.count(); i++) {
                 Figure *figure = this ->selectedFigures.at(i);
                 //1.1.3.1.1 리스트에 선택된 객체를 ㅃㅐㄴ다
                 this->list.removeOne(figure);
                 //1.1.3.1.1 delete
                 delete figure;
            }
            //1.1.3.2 selected figures를 clear
            this->selectedFigures.clear();
            //1.1.3.3 화면을 갱신
            this->update();

        }

    }
}



//1. paintevent가 호출되었을ㄸㅐ
void MainWindow::paintEvent(QPaintEvent *event) {
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

    QPen pen(Qt::black, 3, Qt::DotLine);
    p.setPen(pen);

    //1.1. 리스트 안에 문자를 도형 갯수 만큼 반복한다
    for(int i = 0; i < this->selectedFigures.count(); i++){
        //1.1.1. i번쨰 도형을 찾는다
        Figure *figure = this->selectedFigures.at(i);
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


