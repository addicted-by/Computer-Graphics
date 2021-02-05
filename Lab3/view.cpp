#include "view.h"
#include <QPainter>
#include <QResizeEvent>
#include <cmath>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QColor>
#include <algorithm>

view::view(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(0, 0, 0));
    setPalette(pal);

    setAutoFillBackground(true);

    fig.create();
    step = 40;
    center_x = 0;
    center_y = 0;
    first = true;
}

void view::paintEvent(QPaintEvent *) {
    QPainter ptr{this};
    ptr.setPen(QPen(QColor(255, 5, 0), 0.1));

    if (first) {
        center_x = width() / 2;
        center_y = height() / 2;
        first = false;
    }

    fig.draw(&ptr, center_x, center_y, step, width() / 2, height() / 2);
}

void view::resizeEvent(QResizeEvent *e) {
    if (e->oldSize().width() == -1 || e->oldSize().height() == -1) {
        return;
    }
    double coef_x = width() / static_cast<double>(e->oldSize().width());
    double coef_y = height() / static_cast<double>(e->oldSize().height());
//    double coef_z = sqrt(std::pow(width(), 2) + std::pow(height(), 2)) /
//            sqrt(std::pow(static_cast<double>(e->oldSize().width()), 2) + std::pow(static_cast<double>(e->oldSize().height()), 2));

    double min_coef = std::min(coef_x, coef_y);
    center_x *= coef_x;
    center_y *= coef_y;

    QMatrix4x4 mtrxS {
        static_cast<float>(min_coef), 0, 0, 0,
        0, static_cast<float>(min_coef), 0, 0,
        0, 0, static_cast<float>(min_coef), 0,
        0, 0, 0, 1
    };
    fig.change_sphere(mtrxS);
    fig.fullTransformation = mtrxS * fig.fullTransformation;
    update();
}

void view::mousePressEvent(QMouseEvent *event) {
    previousPoint = event->pos();
}

void view::mouseMoveEvent(QMouseEvent *event) {
    QPointF newPoint = event->pos();
    double deltaX = newPoint.x() - previousPoint.x();
    double deltaY = newPoint.y() - previousPoint.y();

    center_x += deltaX;
    center_y += deltaY;

    previousPoint = newPoint;
    update();
}
