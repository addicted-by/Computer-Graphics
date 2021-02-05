#include "mainwindow.h"
#include <QPainter>
#include <cmath>
#include <vector>

MainWindow::MainWindow(QMainWindow *parent)
: QMainWindow(parent) {
    QLabel* lblX1(new QLabel("По х:", this));
    lblX1->move(10, 0);
    X1 = new QDoubleSpinBox(this);
    X1->setRange(-960.00, 960.00);
    X1->setSingleStep(1);
    X1->setValue(160.00);
    X1->move(5, 30);
    QLabel* lblY1(new QLabel("По у:", this)); //Надпись
    lblY1->move(110, 0); //Расположение надписи
    Y1 = new QDoubleSpinBox(this); //Коробочка со стрелочками
    Y1->setRange(-540.00, 540.00); //Мин и макс занчения
    Y1->setSingleStep(1.00); //Шаг изменения
    Y1->setValue(120.00); //Начальное значение
    Y1->move(110, 30); //Расположение коробочки
    QLabel* lblK(new QLabel("K:", this));
    lblK->move(215, 0);
    K = new QDoubleSpinBox(this);
    K->setRange(0.00, 100.00);
    K->setSingleStep(0.1);
    K->setValue(3.00);
    K->move(220, 30);
    X2 = new QDoubleSpinBox(this);
    X2->setRange(-960.00, 960.00);
    X2->setSingleStep(1.00);
    X2->setValue(120);
    X2->move(5, 65);
    Y2 = new QDoubleSpinBox(this);
    Y2->setRange(-540.00, 540.00);
    Y2->setSingleStep(1.00);
    Y2->setValue(120.00);
    Y2->move(110, 65);
    X3 = new QDoubleSpinBox(this);
    X3->setRange(-960.00, 960.00);
    X3->setSingleStep(1.0);
    X3->setValue(0.0);
    X3->move(5, 100);
    Y3 = new QDoubleSpinBox(this);
    Y3->setRange(-540.00, 540.00);
    Y3->setSingleStep(1.00);
    Y3->setValue(1.30);
    Y3->move(110, 100);
    X4 = new QDoubleSpinBox(this);
    X4->setRange(-960.00, 960.00);
    X4->setSingleStep(1.00);
    X4->setValue(50.00);
    X4->move(5, 135);
    Y4 = new QDoubleSpinBox(this);
    Y4->setRange(-540.00, 540.00);
    Y4->setSingleStep(1.00);
    Y4->setValue(120.00);
    Y4->move(110, 135);
    connect(X1, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(Y1, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(K, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(X2, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(Y2, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(X3, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(Y3, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(X4, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
    connect(Y4, SIGNAL(valueChanged(double)),
    this, SLOT(redrawOnValueChange(double)));
}
MainWindow::~MainWindow() {

}
void MainWindow::redrawOnValueChange(double) {//вызывается при изменении параметров
update();
}
void MainWindow::paintEvent(QPaintEvent*) {
    const double x1(X1->value());
    const double y1(Y1->value());
    const double x2(X2->value());
    const double y2(Y2->value());
    const double x3(X3->value());
    const double y3(Y3->value());
    const double x4(X4->value());
    const double y4(Y4->value());
    const double shag(K->value());
    double A=y1/((x1-x2)*(x1-x3)*(x1-x4)),
    B=y2/((x2-x1)*(x2-x3)*(x2-x4)),
    C=y3/((x3-x1)*(x3-x2)*(x3-x4)),
    D=y4/((x4-x1)*(x4-x2)*(x4-x3));
    double y=0.0, centery=height()/2, centerx=width()/2, yh=0.0;
    QPainter ptr(this);
    double k=5.0;
    ptr.drawLine(x1-k+centerx, y1-k+centery, x1+k+centerx, y1+k+centery);
    ptr.drawLine(x1-k+centerx, y1+k+centery, x1+k+centerx, y1-k+centery);
    ptr.drawLine(x2-k+centerx, y2-k+centery, x2+k+centerx, y2+k+centery);
    ptr.drawLine(x2-k+centerx, y2+k+centery, x2+k+centerx, y2-k+centery);
    ptr.drawLine(x3-k+centerx, y3-k+centery, x3+k+centerx, y3+k+centery);
    ptr.drawLine(x3-k+centerx, y3+k+centery, x3+k+centerx, y3-k+centery);
    ptr.drawLine(x4-k+centerx, y4-k+centery, x4+k+centerx, y4+k+centery);
    ptr.drawLine(x4-k+centerx, y4+k+centery, x4+k+centerx, y4-k+centery);
    ptr.drawLine(0, centery, width(), centery);
    ptr.drawLine(centerx, 0, centerx, height());
    for (double x=-960; x<960; x+=shag) {
        y=A*(x-x2)*(x-x3)*(x-x4)+B*(x-x1)*(x-x3)*(x-x4)+C*(x-x1)*(x-x2)*(x-x4)+D*(x-x1)*(x-x2)*(x-x3);
        double xh=x+shag;
        yh=A*(xh-x2)*(xh-x3)*(xh-x4)+B*(xh-x1)*(xh-x3)*(xh-x4)+C*(xh-x1)*(xh-x2)*(xh-x4)+D*(xh-x1)*(xh-x2)*(xh-x3);
        ptr.drawLine(x+centerx, y + centery, xh+centerx, yh + centery);
    }
}
