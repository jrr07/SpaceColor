#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
class Rectangle : public Figure{
private:
    int x;
    int y;
    int width;
    int height;

public:
    Rectangle();
    Rectangle(int x, int y, int width, int height, bool color);
    void setXPoint(int x);
    void setYPoint(int y);
    void setWidth(int width);
    void setHeight(int height);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    ~Rectangle();
    virtual void whoAreYou();
    void setData(int x, int y, int width, int height);
    void setData(int x, int y);
};





#endif // RECTANGLE_H
