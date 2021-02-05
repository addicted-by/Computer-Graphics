#ifndef BEZIE_H
#define BEZIE_H
#include<QWidget>
#include<QPainter>
#include <QVector3D>

class bezie
{
public:
    QPointF Point1;
    QPointF Point2;
    QPointF Point3;
    QPointF Point4;
    QPointF x;
    QPointF y;
    QPointF x_prev;
    QPointF y_prev;
    std::vector<QVector3D> coordinates;
    double z1;
    double z2;
    double z3;
    double z4;
    double speed;
    double width;
    double height;
    std::vector<double> points_x;
    std::vector<double> points_y;
    std::vector<double> points_z;
    bezie();
   // bezie(const bezie &e);
    bezie(QPointF point1, QPointF point2, QPointF point3, QPointF point4, double speed, double width, double height, double z1, double z2, double z3, double z4);
    void draw(QPainter *pen);
    void redraw(QPainter *pen);
    std::vector<float> static get_x();
    std::vector<float> get_y();
    //void draw(QPainter *ptr, int center_x, int center_y, double step_pixels,
          //  int window_center_x, int window_center_y);
signals:

public slots:
};

#endif // BEZIE_H
