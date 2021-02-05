#ifndef sphere_H
#define sphere_H

#include "polygon.h"
#include <QMatrix4x4>
#include <QPainter>
#include "lamp.h"

class sphere
{
public:
    std::vector<Polygon> polygons;
    QMatrix4x4 fullTransformation;
    double r;
    double step;
    Lamp *lamp;
    bool displayCarcass = false;

    sphere();
    sphere(const sphere &e);
    void clear_polygons();
    void change_sphere(const QMatrix4x4 &mtrx);
    void set_step(double s);
    void create();
    void draw(QPainter *ptr, int center_x, int center_y, double step_pixels,
              int window_center_x, int window_center_y);
};

#endif // sphere_H
