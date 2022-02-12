#include "Ui/mainwindow.h"
#include "Figure/Line.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
     QList<Figure*>list;



   cout << "end" << endl;
    return 0;
}
