#ifndef MYMATH_H
#define MYMATH_H

#include <math.h>

bool checkLine (int x, int y, int sx, int sy, int ex, int ey, int tolerance = 4 );
bool checkCircle(int x, int y,int cx, int cy, int r, int tolerance = 4);
bool checkRectnagle(int x, int y,int sx, int sy, int w,int h, int tolerance = 4);
double getAngle(int sx, int sy, int ex, int ey);
void rotate(int cx, int cy, int x, int y, double angle, double *rx, double *ry);
#endif // MYMATH_H
