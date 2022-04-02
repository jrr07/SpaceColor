#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qlist.h"
#include "Figure/Figure.h"
#include "Figure/Line.h"
#include "Figure/Circle.h"
#include "Figure/Rectangle.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QList<Figure*> list;
    QList<Figure*> selectedFigures;
    int drawType;

protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void nothingButtonPressed();
    void lineButtonPressed();
    void circleButtonPressed();
    void rectangleButtonPressed();
};


#endif // MAINWINDOW_H
