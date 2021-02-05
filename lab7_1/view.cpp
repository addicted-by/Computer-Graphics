#include "view.h"
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPainter>

view::view(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(0, 0, 0));
    setPalette(pal);

    setAutoFillBackground(true);

    //bezie.create();
    time = 0;
    center_x = 0;
    center_y = 0;
    flag = true;
    flag1 = false;
    flag2 = false;
    flag3 = false;
    flag4 = false;
//    mPoint2 = QPointF();
//    mPoint3 = QPointF();
//    mPoint4 = QPointF();

}
QPointF point1 = QPointF();
QPointF point3 = QPointF();
QPointF point2 = QPointF();
QPointF point4 = QPointF();
void view::paintEvent(QPaintEvent *)
{



    if (flag) {
        if (flag1){
            QPainter ptr{this};
            ptr.setPen(QPen(QColor(255, 255, 255)));
            ptr.drawRect(static_cast<int>(Point.x()), static_cast<int>(Point.y()), 10, 10);
            point1 = Point;
            flag1 = false;
        }else if (flag2){
            QPainter ptr{this};
            ptr.setPen(QPen(QColor(255, 255, 255)));
            ptr.drawRect(point1.x(), point1.y(), 10, 10);
            ptr.drawRect(Point.x(), Point.y(), 10, 10);
            point2 = Point;
            flag2 = false;
        } else if (flag3){
            QPainter ptr{this};
            ptr.setPen(QPen(QColor(255, 255, 255)));
            ptr.drawRect(point1.x(), point1.y(), 10, 10);
            ptr.drawRect(point2.x(), point2.y(), 10, 10);
            ptr.drawRect(Point.x(), Point.y(), 10, 10);
            point3 = Point;
            flag3 = false;
        } else if (flag4){
            QPainter ptr{this};
            ptr.setPen(QPen(QColor(255, 255, 255)));
            ptr.drawRect(point1.x(), point1.y(), 10, 10);
            ptr.drawRect(point2.x(), point2.y(), 10, 10);
            ptr.drawRect(point3.x(), point3.y(), 10, 10);
            ptr.drawRect(Point.x(), Point.y(), 10, 10);
            flag4 = false;
            flag = false;
            point4 = Point;
        }
    }
}

void view::resizeEvent(QResizeEvent *)
{

}

void view::mousePressEvent(QMouseEvent *event)
{
    Point = event->pos();
   // event->accept();
    flag1 = true;
    flag2 = true;
    flag3 = true;
    flag4 = true;
    update();


}

void view::mouseReleaseEvent(QMouseEvent *e)
{

}
