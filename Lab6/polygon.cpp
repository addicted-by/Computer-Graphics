#include "polygon.h"

#include <QVector4D>
#include <vector>
#include <QVector3D>


polygon::polygon(const std::vector<QVector4D> &v) {
    vertices = v;
}

polygon &polygon::operator=(const std::vector<QVector4D> &v) {
    vertices = v;
    return *this;
}
