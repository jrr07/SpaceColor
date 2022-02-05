#include "Figure.h"

Figure::Figure(){
    this->color = true;
}

Figure::Figure(bool color){
    this->color = color;
}
void Figure::setColor(bool color){
    this->color =color;
}
bool Figure::getColor(){
    return this->color;
}

Figure::~Figure(){

}
