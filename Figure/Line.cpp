#include "Line.h"
#include <iostream>
using namespace std;
Line::Line(){
    this->startX=0;
    this ->startY=0;
    this ->endX=0;
    this ->endY=0;
}

Line::Line(int startX, int startY, int endX, int endY, bool color )
    :Figure(color){

    this -> startX = startX;
    this -> startY = startY;
    this -> endX = endX;
    this -> endY = endY;
}
void Line::setStartPoint(int startX, int startY){
    this -> startX = startX;
    this -> startY =startY;
}
void Line:: setEndPoint(int endX, int endY){
    this -> endX = endX;
    this -> endY = endY;
}
int Line::getStartX(){
    return this -> startX;
}
int Line::getStartY(){
    return this -> startY;
}
int Line::getEndX(){
    return this -> endX;
}
int Line::getEndY(){
    return this -> endY;
}
/*void Line::print(){
   std::cout << "Line:(" << this->startX << ", " << this->startY << ")->(" << this->endX << ", " << this->endY << ")" << std::endl;
}
*/

Line::~Line(){

   // std::cout << "line ~Line" << std::endl;
}

void Line::whoAreYou(){
    cout << "i am line" << endl;
}
void Line::setData(int startX,int startY,int endX,int endY){
    this->startX = startX;
    this->startY = startY;
    this->endX = endX;
    this->endY = endY;
}
void Line::setData(int startX, int startY){
    this->startX = startX;
    this->startY = startY;
}
void Line::setData(int endX){
    this->endX = endX;
}
