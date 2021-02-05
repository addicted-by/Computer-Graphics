#ifndef POLYGON_H
#define POLYGON_H

#include <QVector4D>
#include <vector>
#include <QVector3D>

class polygon
{
public:
    std::vector<QVector4D> vertices;

    polygon() = default;
    polygon(const std::vector<QVector4D> &v);
    polygon &operator=(const std::vector<QVector4D> &v);
    QVector3D get_normal();
};
////class Polygon
////{
////public:
////    std::vector<QVector4D> vertices;

////    Polygon() = default;
////    Polygon(const std::vector<QVector4D> &v);
////    Polygon &operator=(const std::vector<QVector4D> &v);
////    QVector3D get_normal();
////};

#endif // POLYGON_H
