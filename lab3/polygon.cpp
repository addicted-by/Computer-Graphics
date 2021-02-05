#include "polygon.h"
#include <QVector3D>
#include <QPen>
#include <QColor>
#include <QPolygonF>
#include <QPointF>
#include <cmath>

Polygon::Polygon(const std::vector<QVector4D> &v) {
    vertices = v;
}

QVector3D Polygon::get_normal() {
    QVector3D first{
        vertices[1][0] - vertices[0][0],
        vertices[1][1] - vertices[0][1],
        vertices[1][2] - vertices[0][2]
    };
    QVector3D second{
        vertices[2][0] - vertices[0][0],
        vertices[2][1] - vertices[0][1],
        vertices[2][2] - vertices[0][2]
    };

    QVector3D normal{
        first[1] * second[2] - first[2] * second[1],
        first[2] * second[0] - first[0] * second[2],
        first[0] * second[1] - first[1] * second[0]
    };

    return normal;
}

void Polygon::add_vertex(const QVector4D &vertex) {
    vertices.push_back(vertex);
}

void Polygon::add_vertex(double x, double y, double z, double d) {
    QVector4D v{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z), static_cast<float>(d)};
    vertices.push_back(v);
}

void Polygon::clear_verticies() {
    vertices.clear();
}

void Polygon::change_vertices(const QMatrix4x4 &mtrx) {
    for (auto &vertex: vertices) {
        vertex = mtrx * vertex;
    }
}

int Polygon::calc_ambient_component(Lamp *lamp) {
    return static_cast<int>(ambient_coef * lamp->power);
}

int Polygon::calc_diffuse_component(int dx, int dy, Lamp *lamp) {
    QVector3D toLamp = QVector3D{
        lamp->position.x() - (vertices[0].x() + dx),
        lamp->position.y() - (vertices[0].y() + dy),
        lamp->position.z() - vertices[0].z()
    };
    QVector3D toLampNormalized = toLamp.normalized();
    QVector3D normal = this->get_normal().normalized();
    double scalarProduct = static_cast<double>(toLampNormalized.x() * normal.x() +
                                               toLampNormalized.y() * normal.y() +
                                               toLampNormalized.z() * normal.z());

    int res = static_cast<int>(diffuse_coef * scalarProduct * lamp->power * 100 / pow((static_cast<double>(toLamp.length())), 1.2));
    if (res < 0) {
        res = 0;
    }
    return res;
}

int Polygon::calc_specular_component(int dx, int dy, Lamp *lamp) {
    QVector3D toLamp = QVector3D{
        lamp->position.x() - (vertices[0].x() + dx),
        lamp->position.y() - (vertices[0].y() + dy),
        lamp->position.z() - vertices[0].z()
    };
    QVector3D toLampNormalized = toLamp.normalized();
    QVector3D toObserver = QVector3D{0 - (vertices[0].x()), 0 - (vertices[0].y()), vertices[0].z()}.normalized();
    QVector3D median = (toLampNormalized + toObserver) / (toLampNormalized + toObserver).length();
    QVector3D normal = this->get_normal().normalized();
    float scalarProduct = median.x() * normal.x() + median.y() * normal.y() + median.z() * normal.z();
    int res = static_cast<int>(specular_coef * pow(static_cast<double>(scalarProduct), gloss_coef) *
                               lamp->power * 100 / pow((static_cast<double>(toLamp.length())), 1.2));
    if (res < 0) {
        res = 0;
    }
    return res;
}

void Polygon::draw(QPainter *ptr, int center_x, int center_y, double step_pixels,
                   int window_center_x, int window_center_y, Lamp *lamp,
                   bool displayCarcass) {
    QPen oldPen = ptr->pen();
    int resCalcAmbientComponent = calc_ambient_component(lamp);
    int resCalcDiffuseComponent = calc_diffuse_component(center_x - window_center_x,
                                                         center_y - window_center_y, lamp);
    int resCalcSpecularComponent = calc_specular_component(center_x - window_center_x,
                                                           center_y - window_center_y, lamp);
    int r = rgb['r'] + resCalcAmbientComponent + resCalcDiffuseComponent + resCalcSpecularComponent;
    int g = rgb['g'] + resCalcAmbientComponent + resCalcDiffuseComponent + resCalcSpecularComponent;
    int b = rgb['b'] + resCalcAmbientComponent + resCalcDiffuseComponent + resCalcSpecularComponent;
    if (r > 255) {
        r = 255;
    }
    if (g > 255) {
        g = 255;
    }
    if (b > 255) {
        b = 255;
    }
    QPen newPen(QColor(r, g, b), 0.5, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
    ptr->setPen(newPen);
    ptr->setBrush(QColor(r, g, b));
    QPolygonF pol;
    for (size_t i = 0; i < 3; i++) {
        pol << QPointF(
            static_cast<double>(vertices[i][0]) * step_pixels + center_x,
            static_cast<double>(vertices[i][1]) * step_pixels + center_y
        );
    }
    ptr->drawPolygon(pol);
    if (displayCarcass) {
        ptr->setPen(oldPen);
        for (size_t i = 0; i < 3; i++) {
            ptr->drawLine(
                static_cast<int>(static_cast<double>(vertices[i][0]) * step_pixels + center_x),
                static_cast<int>(static_cast<double>(vertices[i][1]) * step_pixels + center_y),
                static_cast<int>(static_cast<double>(vertices[(i + 1) % 3][0]) * step_pixels + center_x),
                static_cast<int>(static_cast<double>(vertices[(i + 1) % 3][1]) * step_pixels + center_y)
            );
        }
    }
}
