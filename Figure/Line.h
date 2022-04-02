#ifndef LINE_H
#define LINE_H
#include "Figure.h"


class Line : public Figure {

private:
    int startX;
    int startY;
    int endX;
    int endY;
public:
    Line();
    Line(int startX, int startY, int endX, int endY, bool color);

    void setStartPoint(int startX, int startY);
    void setEndPoint(int endX,int endY);
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    void print();
    ~Line();
    virtual void whoAreYou();
    void setData(int startX,int  startY,int endX,int endY);
    void setData(int startX, int startY);
    void setData(int endX);
    virtual bool checkContain(int x, int y);
};




#endif // LINE_H
