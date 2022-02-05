#include "Ui/mainwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

    std::cout << "dddd" << std::endl;
    return 0;
}
