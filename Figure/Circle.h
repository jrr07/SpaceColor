#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
class Circle : public Figure{
private:
    int centerX;
    int centerY;
    int radius;

public:
    Circle();
    Circle(int centerX, int centerY, int radius, bool color);
    void setCenterPoint(int centerX, int centerY);
    void setRadius(int radius);
    int getCenterX();
    int getCenterY();
    int getRadius();
    ~Circle();
    virtual void whoAreYou();
    void setData(int centerX,int centerY,int radius);
    void setData(int centerX);
    void setData(int centerX, int centerY);
    virtual bool checkContain(int x, int y);
};






#endif // CIRCLE_H
