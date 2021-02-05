#include "sphere.h"
#include <vector>
#include <cmath>
#include <QVector4D>
#include <QTextStream>

sphere::sphere() {
    r = 4;
    step = 0.1;
    lamp = new Lamp(70, 0, 0, 100);

    fullTransformation = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}

sphere::sphere(const sphere &e) {
    polygons = e.polygons;
    r = e.r;
    step = e.step;
}

void sphere::clear_polygons() {
    polygons.clear();
}

void sphere::change_sphere(const QMatrix4x4 &mtrx) {
    for (auto &polygon: polygons) {
        polygon.change_vertices(mtrx);
    }
}

void sphere::set_step(double s) {
    step = s;
}

void sphere::create() {
    std::vector<QVector4D> prevPoints{};
    QVector4D firstIter{0, 0, static_cast<float>(r * cos(0)), 1};
    QVector4D lastIter{0, 0, 0, 1};
    bool connectToOnePoint = true;
    for (double theta = step / 2.; theta < M_PI / 2.; theta += step / 2.) {
        if (connectToOnePoint) {
            QVector4D prevVertex;
            QVector4D firstVertex;
            for (double phi = 0.; phi < 2 * M_PI; phi += step) {
                if (phi == 0.) {
                    firstVertex = {
                        static_cast<float>(r * sin(theta) * cos(phi)),
                        static_cast<float>(r * sin(theta) * sin(phi)),
                        static_cast<float>(r * cos(theta)),
                        1
                    };
                    prevVertex = firstVertex;
                    prevPoints.push_back(prevVertex);
                    continue;
                }
                std::vector<QVector4D> toPushBack;
                QVector4D newVertex;
                newVertex = {
                    static_cast<float>(r * sin(theta) * cos(phi)),
                    static_cast<float>(r * sin(theta) * sin(phi)),
                    static_cast<float>(r * cos(theta)),
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
                if (phi + step >= 2 * M_PI) {
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
        } else if (theta + step/2. > M_PI/2.){
            theta = M_PI/2.;
            QVector4D prevVertex;
            QVector4D firstVertex;
            std::vector<QVector4D> newPrevPoints{};
            size_t cnt = 0;
            for (double phi = 0; phi < 2 * M_PI; phi += step, cnt++) {
                if (phi == 0.) {
                    firstVertex = {
                        static_cast<float>(r * sin(theta) * cos(phi)),
                        static_cast<float>(r * sin(theta) * sin(phi)),
                        static_cast<float>(r * cos(theta)),
                        1
                    };
                    prevVertex = firstVertex;
                    newPrevPoints.push_back(prevVertex);
                    continue;
                }
                std::vector<QVector4D> toPushBack;
                QVector4D newVertex;
                newVertex = {
                    static_cast<float>(r * sin(theta) * cos(phi)),
                    static_cast<float>(r * sin(theta) * sin(phi)),
                    static_cast<float>(r * cos(theta)),
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
                if (phi + step > 2 * M_PI) {
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
                    if (theta + step / 2. > M_PI) {
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
            for (double phi = 0; phi < 2 * M_PI; phi += step, cnt++) {
                if (phi == 0.) {
                    firstVertex = {
                        static_cast<float>(r * sin(theta) * cos(phi)),
                        static_cast<float>(r * sin(theta) * sin(phi)),
                        static_cast<float>(r * cos(theta)),
                        1
                    };
                    prevVertex = firstVertex;
                    newPrevPoints.push_back(prevVertex);
                    continue;
                }
                std::vector<QVector4D> toPushBack;
                QVector4D newVertex;
                newVertex = {
                    static_cast<float>(r * sin(theta) * cos(phi)),
                    static_cast<float>(r * sin(theta) * sin(phi)),
                    static_cast<float>(r * cos(theta)),
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
                if (phi + step > 2 * M_PI) {
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
                    if (theta + step / 2. > M_PI) {
                        connectToOnePoint = true;
                    }
                }
            }
        }
    }
    connectToOnePoint = true;
    prevPoints.clear();
    for (double f = 0.; f < r; f += r / 10.) {
        if (connectToOnePoint) {
            QVector4D prevVertex, firstVertex;
            for (double phi = 0.; phi < 2. * M_PI; phi += step) {
                if (phi == 0.) {
                    firstVertex = {
                        static_cast<float>(f * cos(phi)),
                        static_cast<float>(f * sin(phi)),
                        0.,
                        1.
                    };
                    prevVertex = firstVertex;
                    prevPoints.push_back(prevVertex);
                    continue;
                }
                std::vector<QVector4D> toPushBack;
                QVector4D newVertex = {
                    static_cast<float>(f * cos(phi)),
                    static_cast<float>(f * sin(phi)),
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
                if (phi + step >= 2 * M_PI) {
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
            if (f + step >= r) {
                f = r;
            }
            QVector4D prevVertex, firstVertex;
            std::vector<QVector4D> newPrevPoints;
            size_t cnt = 0;
            for (double phi = 0.; phi < 2 * M_PI; phi += step, cnt++) {
                if (phi == 0.) {
                    firstVertex = {
                        static_cast<float>(f * cos(phi)),
                        static_cast<float>(f * sin(phi)),
                        0.,
                        1.
                    };
                    prevVertex = firstVertex;
                    newPrevPoints.push_back(prevVertex);
                    continue;
                }
                std::vector<QVector4D> toPushBack;
                QVector4D newVertex = {
                    static_cast<float>(f * cos(phi)),
                    static_cast<float>(f * sin(phi)),
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
                if (phi + step >= 2 * M_PI) {
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
void sphere::draw(QPainter *ptr, int center_x, int center_y, double step_pixels,
                     int window_center_x, int window_center_y) {
    for (auto &polygon: polygons) {
        auto normal = polygon.get_normal();
        if (normal.z() > 0) {
            polygon.draw(ptr, center_x, center_y, step_pixels,
                         window_center_x, window_center_y, lamp, displayCarcass);
        }
    }
}
