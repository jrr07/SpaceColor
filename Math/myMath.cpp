#include "myMath.h"
#include <iostream>
#include <math.h>
using namespace std;
bool checkLine (int x, int y, int sx, int sy, int ex, int ey, int tolerance ){
    int a = abs((ey - sy) * x - (ex - sx) * y + ex * sy - sy * ex) / sqrt((ey - sy) * (ey - sy) + (ex - sx) * (ex - sx));
    if( a == 0 ) {
        cout << "선 위에 점이 있어요  ddd" << endl;
        return true;
    }
    return false;
}
bool checkCircle(int x, int y,int cx, int cy, int r, int tolerance){
    int a = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
    if(a - tolerance <= r && a + tolerance >= r){
        cout << "원 위에 점이 있어요  yyy " << endl;
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
        cout << "top left top right" << endl;
        return true;
     }

    if( topLeftX + tolerance >= x && topLeftX - tolerance <= x && topLeftY <= y && bottomLeftY > y){
        cout << "top left bottom left" << endl;
        return true;
    }

    if( bottomLeftY + tolerance >= y && bottomLeftY - tolerance <= y && bottomLeftX <= x && bottomRightX > x){
        cout << "bottom left bottom right" << endl;
        return true;
    }

    if ( bottomRightX + tolerance >= x && bottomRightX - tolerance <= x && topRightY <= y && bottomRightY > y){
        cout << "top Right bottom Right" << endl;
        return true;
    }
    return false;
}
