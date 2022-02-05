#ifndef FIGURE_H
#define FIGURE_H


class Figure{
protected:
    bool color;
public:
    Figure();
    Figure(bool color);
    void setColor(bool color);
    bool getColor();
    virtual ~Figure() =0; //추상클래스 선언
    virtual void whoAreYou() = 0;
};


#endif // FIGURE_H
