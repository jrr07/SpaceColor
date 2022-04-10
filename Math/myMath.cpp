#include "myMath.h"
#include <iostream>


using namespace std;

#define PI 3.1415926535

double getAngle(int sx, int sy, int ex, int ey){
    return atan2(ey - sy, ex - sx) * 180/PI;
}


void rotate(int cx, int cy, int x, int y, double angle, double *rx, double *ry){
    *rx = (cos(angle * PI/180) * (x - cx) - sin(angle * PI/180) * (y - cy)) + cx;
    *ry = (sin(angle * PI/180) * (x - cx) + cos(angle * PI/180) * (y - cy)) + cy;
}
bool checkLine (int x, int y, int sx, int sy, int ex, int ey, int tolerance ){
    double clickX2;
    double clickY2;
    double endX2;
    double endY2;
    double angle = getAngle(sx, sy , ex, ey) ;
    rotate(sx, sy, x, y, -angle, &clickX2, &clickY2);
    rotate(sx, sy, ex, ey, -angle, &endX2, &endY2);

    if(sx - tolerance < clickX2 && endX2 + tolerance > clickX2 && sy - tolerance < clickY2 && endY2 + tolerance > clickY2){
        return true;
    }
    return false;

}
bool checkCircle(int x, int y,int cx, int cy, int r, int tolerance){
    int a = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
    if(a - tolerance <= r && a + tolerance >= r){
        return true;
    }
    return false;
}
bool checkRectnagle(int x, int y,int sx, int sy, int w,int h, int tolerance){
    int topLeftX = sx;
    int topLeftY = sy;
    int topRightX = sx + w;
    int topRightY = sy;
    int bottomLeftX = sx;
    int bottomLeftY = sy + h;
    int bottomRightX = sx + w;
    int bottomRightY = sy + h;

    if( topLeftY + tolerance >= y && topLeftY - tolerance <= y &&  topLeftX <= x && topRightX > x){
        return true;
     }

    if( topLeftX + tolerance >= x && topLeftX - tolerance <= x && topLeftY <= y && bottomLeftY > y){
        return true;
    }

    if( bottomLeftY + tolerance >= y && bottomLeftY - tolerance <= y && bottomLeftX <= x && bottomRightX > x){
        return true;
    }

    if ( bottomRightX + tolerance >= x && bottomRightX - tolerance <= x && topRightY <= y && bottomRightY > y){
        return true;
    }
    return false;
}
