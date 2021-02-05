#include "bezie.h"
#include <QWidget>
#include <QPainter>
#include <QMatrix3x3>
bezie::bezie(QPointF point1, QPointF point2, QPointF point3, QPointF point4, double speed, double width, double height, double z1, double z2, double z3, double z4){
    this->Point1 = point1;
    this->Point2 = point2;
    this->Point3 = point3;
    this->Point4 = point4;
    this->speed = speed;
    this->points_x = {};
    this->points_y = {};
    this->points_z = {};
    this->z1 = 100;
    this->z2 = 110;
    this->z3 = 50;
    this->z4 = 12;
    this->width = width;
    this->height = height;
    this->coordinates = {};

}
bezie::bezie(){

}

//bezie::bezie(const bezie &e) {
//    points_x = e.points_x;
//    Point1 = e.Point1;
//    Point2 = e.Point2;
//    Point3 = e.Point3;
//    Point4 = e.Point4;
//    points_y = e.points_y;
//}
void bezie::draw(QPainter *pen){
    pen->setPen(QColor(255, 0, 0, 255));

    double t = 0;
    double P1_x = (1-t)*(1-t)*(1-t) * Point1.x();
    double P1_y = (1-t)*(1-t)*(1-t) * Point1.y();
    double P2_x = 3 * (1-t)*(1-t) * t * Point2.x();
    double P2_y = 3 * (1-t)*(1-t) * t * Point2.y();
    double P3_x = 3 * (1-t)* t*t * Point3.x();
    double P3_y = 3 * (1-t)* t*t * Point3.y();
    double P4_x = t*t*t * Point4.x();
    double P4_y = t*t*t * Point4.y();
    double P1_z = (1-t)*(1-t)*(1-t) * z1;
    double P2_z = 3*(1-t)*(1-t) * t * z2;
    double P3_z = 3 * (1-t)* t*t * z3;
    double P4_z = t*t*t * z4;

    points_x.push_back(P1_x + P2_x + P3_x + P4_x);
    points_y.push_back(P1_y + P2_y + P3_y + P4_y);
    points_z.push_back(P1_z + P2_z + P3_z + P4_z);
    //double speed = 0.02;
    while (t<1){
        t += speed;
        P1_x = (1-t)*(1-t)*(1-t) * Point1.x();
        P1_y = (1-t)*(1-t)*(1-t) * Point1.y();
        P2_x = 3 * (1-t)*(1-t) * t * Point2.x();
        P2_y = 3 * (1-t)*(1-t) * t * Point2.y();
        P3_x = 3 * (1-t)* t*t * Point3.x();
        P3_y = 3 * (1-t)* t*t * Point3.y();
        P4_x = t*t*t * Point4.x();
        P4_y = t*t*t * Point4.y();
        P1_z = (1-t)*(1-t)*(1-t) * z1;
        P2_z = 3*(1-t)*(1-t) * t * z2;
        P3_z = 3 * (1-t)* t*t * z3;
        P4_z = t*t*t * z4;
        double x = P1_x + P2_x + P3_x + P4_x;
        double y = P1_y + P2_y + P3_y + P4_y;
        pen->drawLine(static_cast<int>(points_x.back() + width / 2),static_cast<int>(points_y.back() + height / 2),static_cast<int>(x + width / 2),static_cast<int>(y + height / 2));
        points_x.push_back(x);
        points_y.push_back(y);
        points_z.push_back(P1_z + P2_z + P3_z + P4_z);
        //pen->drawEllipse(static_cast<int>(x),static_cast<int>(y),1,1);
    }

}


void bezie::redraw(QPainter *pen){

}
