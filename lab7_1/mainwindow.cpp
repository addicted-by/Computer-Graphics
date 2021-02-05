#include "mainwindow.h"
#include "view.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    vw = new view();
    setCentralWidget(vw);
}

MainWindow::~MainWindow()
{
}

