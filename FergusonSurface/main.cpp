#include <QApplication>
#include <QtGlobal>
#include <ctime>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    qsrand(time(0));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
