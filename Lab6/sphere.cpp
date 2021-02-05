#include "sphere.h"
#include <QVector4D>
#include <cmath>

sphere::sphere(float i, float j, float k) :
    a(i), b(j), c(k) {
    precision = 0.08f;
    ambient_color = new float(4);
    ambient_color[0] = 0.2f;
    ambient_color[1] = 0.2f;
    ambient_color[2] = 0.2f;
    ambient_color[3] = 1.f;
    diffuse_color = new float(4);
    diffuse_color[0] = 0.3f;
    diffuse_color[1] = 0.3f;
    diffuse_color[2] = 0.3f;
    diffuse_color[3] = 1.f;
    specular_color = new float(4);
    specular_color[0] = 1.f;
    specular_color[1] = 1.f;
    specular_color[2] = 1.f;
    specular_color[3] = 1.f;
    shininess = 90;
    create();
}

sphere::~sphere() {

}

sphere &sphere::operator=(const sphere &other) {
    a = other.a;
    b = other.b;
    c = other.c;
    precision = other.precision;
    polygons = other.polygons;
    return *this;
}

float sphere::get_a() {
    return a;
}

void sphere::set_a(float i) {
    a = i;
}

float sphere::get_b() {
    return b;
}

void sphere::set_b(float j) {
    b = j;
}

float sphere::get_c() {
    return c;
}

void sphere::set_c(float k) {
    c = k;
}

float sphere::get_precision() {
    return precision;
}

void sphere::set_precision(float p) {
    precision = p;
}

const float *sphere::get_ambient_color() {
    return ambient_color;
}

const float *sphere::get_diffuse_color() {
    return diffuse_color;
}

const float *sphere::get_specular_color() {
    return specular_color;
}

unsigned int sphere::get_shininess() {
    return shininess;
}

std::vector<polygon> &sphere::get_polygons() {
    return this->polygons;
}

void sphere::create() {
    std::vector<QVector4D> prevPoints{};
    float step = precision;
    QVector4D firstIter{0, 0, a * static_cast<float>(cos(0)), 1};
    QVector4D lastIter{0, 0, 0, 1};
    bool connectToOnePoint = true;
    for (double theta = static_cast<double>(step) / 2.; theta < M_PI / 2.; theta += static_cast<double>(step) / 2.) {
        if (connectToOnePoint) {
            QVector4D prevVertex;
            QVector4D firstVertex;
            for (double phi = 0.; phi < 2 * M_PI; phi += static_cast<double>(step)) {
            if (phi == 0.) {
            firstVertex = {
            a * static_cast<float>(sin(theta) * cos(phi)),
            a * static_cast<float>(sin(theta) * sin(phi)),
            a * static_cast<float>(cos(theta)),
            1
         };
        prevVertex = firstVertex;
        prevPoints.push_back(prevVertex);
        continue;
        }
        std::vector<QVector4D> toPushBack;
        QVector4D newVertex;
        newVertex = {
            a * static_cast<float>(sin(theta) * cos(phi)),
            a * static_cast<float>(sin(theta) * sin(phi)),
            a * static_cast<float>(cos(theta)),
            1
        };
        toPushBack = {
            firstIter,
            prevVertex,
            newVertex
        };
        polygons.push_back(toPushBack);
        prevVertex = newVertex;
        prevPoints.push_back(prevVertex);
        if (phi + static_cast<double>(step) >= 2 * M_PI) {
            toPushBack = {
                firstIter,
                prevVertex,
                firstVertex
            };
            polygons.push_back(toPushBack);
            prevPoints.push_back(firstVertex);
            connectToOnePoint = false;
        }
        }
        } else if (theta + static_cast<double>(step)/2. > M_PI/2.){
        theta = M_PI/2.;
        QVector4D prevVertex;
        QVector4D firstVertex;
        std::vector<QVector4D> newPrevPoints{};
        size_t cnt = 0;
        for (double phi = 0; phi < 2 * M_PI; phi += static_cast<double>(step), cnt++) {
        if (phi == 0.) {
        firstVertex = {
            a * static_cast<float>(sin(theta) * cos(phi)),
            a * static_cast<float>(sin(theta) * sin(phi)),
            a * static_cast<float>(cos(theta)),
            1
        };
        prevVertex = firstVertex;
        newPrevPoints.push_back(prevVertex);
        continue;
        }
        std::vector<QVector4D> toPushBack;
        QVector4D newVertex;
        newVertex = {
            a * static_cast<float>(sin(theta) * cos(phi)),
            a * static_cast<float>(sin(theta) * sin(phi)),
            a * static_cast<float>(cos(theta)),
            1
        };
        toPushBack = {
        prevPoints[cnt - 1],
        prevVertex,
        newVertex
        };
        polygons.push_back(toPushBack);
        toPushBack = {
        prevPoints[cnt - 1],
        newVertex,
        prevPoints[cnt]
        };
        polygons.push_back(toPushBack);
        prevVertex = newVertex;
        newPrevPoints.push_back(prevVertex);
        if (phi + static_cast<double>(step) > 2 * M_PI) {
        cnt++;
        toPushBack = {
        prevPoints[cnt - 1],
        prevVertex,
        firstVertex
        };
        polygons.push_back(toPushBack);
        toPushBack = {
        prevPoints[cnt - 1],
        firstVertex,
        prevPoints[cnt]
        };
        polygons.push_back(toPushBack);
        newPrevPoints.push_back(firstVertex);
        prevPoints = newPrevPoints;
        if (theta + static_cast<double>(step) / 2. > M_PI) {
        connectToOnePoint = true;
        }
        }
        }
        }
        else {
        QVector4D prevVertex;
        QVector4D firstVertex;
        std::vector<QVector4D> newPrevPoints{};
        size_t cnt = 0;
        for (double phi = 0; phi < 2 * M_PI; phi += static_cast<double>(step), cnt++) {
        if (phi == 0.) {
        firstVertex = {
            a * static_cast<float>(sin(theta) * cos(phi)),
            a * static_cast<float>(sin(theta) * sin(phi)),
            a * static_cast<float>(cos(theta)),
            1
        };
        prevVertex = firstVertex;
        newPrevPoints.push_back(prevVertex);
        continue;
        }
        std::vector<QVector4D> toPushBack;
        QVector4D newVertex;
        newVertex = {
            a * static_cast<float>(sin(theta) * cos(phi)),
            a * static_cast<float>(sin(theta) * sin(phi)),
            a * static_cast<float>(cos(theta)),
            1
        };
        toPushBack = {
        prevPoints[cnt - 1],
        prevVertex,
        newVertex
        };
        polygons.push_back(toPushBack);
        toPushBack = {
        prevPoints[cnt - 1],
        newVertex,
        prevPoints[cnt]
        };
        polygons.push_back(toPushBack);
        prevVertex = newVertex;
        newPrevPoints.push_back(prevVertex);
        if (phi + static_cast<double>(step) > 2 * M_PI) {
        cnt++;
        toPushBack = {
        prevPoints[cnt - 1],
        prevVertex,
        firstVertex
        };
        polygons.push_back(toPushBack);
        toPushBack = {
        prevPoints[cnt - 1],
        firstVertex,
        prevPoints[cnt]
        };
        polygons.push_back(toPushBack);
        newPrevPoints.push_back(firstVertex);
        prevPoints = newPrevPoints;
        if (theta + static_cast<double>(step) / 2. > M_PI) {
        connectToOnePoint = true;
        }
        }
        }
        }
        }
        connectToOnePoint = true;
        prevPoints.clear();
        for (float r = 0.; r < a; r += a / 10.f) {
        if (connectToOnePoint) {
        QVector4D prevVertex, firstVertex;
        for (double phi = 0.; phi < 2. * M_PI; phi += static_cast<double>(step)) {
        if (phi == 0.) {
        firstVertex = {
        r * static_cast<float>(cos(phi)),
        r * static_cast<float>(sin(phi)),
        0.,
        1.
        };
        prevVertex = firstVertex;
        prevPoints.push_back(prevVertex);
        continue;
        }
        std::vector<QVector4D> toPushBack;
        QVector4D newVertex = {
            r * static_cast<float>(cos(phi)),
            r * static_cast<float>(sin(phi)),
            0.,
            1.
        };
        toPushBack = {
        lastIter,
        newVertex,
        prevVertex
        };
        polygons.push_back(toPushBack);
        prevVertex = newVertex;
        prevPoints.push_back(prevVertex);
        if (phi + static_cast<double>(step) >= 2 * M_PI) {
        toPushBack = {
        lastIter,
        firstVertex,
        prevVertex
        };
        polygons.push_back(toPushBack);
        prevPoints.push_back(firstVertex);
        }
        }
        connectToOnePoint = false;
        } else {
        if (r + step >= a) {
        r = a;
        }
        QVector4D prevVertex, firstVertex;
        std::vector<QVector4D> newPrevPoints;
        size_t cnt = 0;
        for (double phi = 0.; phi < 2 * M_PI; phi += static_cast<double>(step), cnt++) {
        if (phi == 0.) {
        firstVertex = {
            r * static_cast<float>(cos(phi)),
            r * static_cast<float>(sin(phi)),
            0.,
            1.
        };
        prevVertex = firstVertex;
        newPrevPoints.push_back(prevVertex);
        continue;
        }
        std::vector<QVector4D> toPushBack;
        QVector4D newVertex = {
            r * static_cast<float>(cos(phi)),
            r * static_cast<float>(sin(phi)),
            0.,
            1.
        };
        toPushBack = {
        prevPoints[cnt - 1],
        newVertex,
        prevVertex
        };
        polygons.push_back(toPushBack);
        toPushBack = {
        prevPoints[cnt - 1],
        prevPoints[cnt],
        newVertex
        };
        polygons.push_back(toPushBack);
        prevVertex = newVertex;
        newPrevPoints.push_back(prevVertex);
        if (phi + static_cast<double>(step) >= 2 * M_PI) {
        cnt++;
        toPushBack = {
        prevPoints[cnt - 1],
        firstVertex,
        prevVertex
        };
        polygons.push_back(toPushBack);
        toPushBack = {
        prevPoints[cnt - 1],
        prevPoints[cnt],
        firstVertex
        };
        polygons.push_back(toPushBack);
        newPrevPoints.push_back(firstVertex);
        prevPoints = newPrevPoints;
        }
        }
        }
        }
        }

void sphere::clear_polygons() {
    polygons.clear();
}

size_t sphere::get_polygons_size() {
    return polygons.size();
}
