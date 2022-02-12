#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(){
    this->x = 0;
    this->y = 0;
    this->width = 10;
    this->height = 10;
}

Rectangle::Rectangle(int x, int y, int width, int height, bool color)
    :Figure(color){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rectangle::setXPoint(int x){
    this-> x = x;
}

void Rectangle::setYPoint(int y){
    this-> y = y;
}

void Rectangle::setWidth(int width){
    this->width = width;
}
void Rectangle::setHeight(int height){
    this->height = height;
}

int Rectangle::getX(){
    return this->x;
}

int Rectangle::getY(){
    return this->y;
}

int Rectangle::getWidth(){
    return this->width;
}

int Rectangle::getHeight(){
    return this ->height;
}
Rectangle::~Rectangle(){

}

void Rectangle::whoAreYou(){
    std::cout << "i am retangle" << std::endl;
}
void Rectangle::setData(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rectangle::setData(int x, int y){
    this->x = x;
    this->y = y;
}
