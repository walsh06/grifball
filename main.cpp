#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "match.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Match m;

    m.sim();
    return a.exec();
}
