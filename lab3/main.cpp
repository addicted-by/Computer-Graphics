#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(400, 800);
    QTextStream out(stdout);
    w.show();

    return a.exec();
}
