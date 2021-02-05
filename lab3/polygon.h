#ifndef POLYGON_H
#define POLYGON_H

#include <QVector4D>
#include <QPainter>
#include <QMatrix4x4>
#include <vector>
#include <map>
#include "lamp.h"

class Polygon
{
public:
    std::vector<QVector4D> vertices;
    std::map<char, int> rgb = {
        {'r', 0},
        {'g', 8},
        {'b', 250}
    };
    double ambient_coef = 0.5;
    double diffuse_coef = 1.5;
    double specular_coef = 1.5;
    double gloss_coef = 4.;

    Polygon() = delete;
    Polygon(const std::vector<QVector4D> &v);
    QVector3D get_normal();
    void add_vertex(const QVector4D &vertex);
    void add_vertex(double x, double y, double z, double d);
    void clear_verticies();
    void change_vertices(const QMatrix4x4 &mtrx);
    int calc_ambient_component(Lamp *lamp);
    int calc_diffuse_component(int dx, int dy, Lamp *lamp);
    int calc_specular_component(int dx, int dy, Lamp *lamp);
    void draw(QPainter *ptr, int center_x, int center_y, double step_pixels,
              int window_center_x, int window_center_y, Lamp *lamp, bool displayCarcass);
};

#endif // POLYGON_H
