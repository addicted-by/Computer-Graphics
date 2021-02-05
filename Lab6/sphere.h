#ifndef sphere_H
#define sphere_H

#include <vector>
#include "polygon.h"
#include <QVector4D>
#include <vector>
#include <QVector3D>



class sphere
{
    float a, b, c;
    float precision;
    float *ambient_color;
    float *diffuse_color;
    float *specular_color;
    unsigned int shininess;
    std::vector<polygon> polygons;
public:
    sphere(float i, float j, float k);
    ~sphere();
    sphere &operator=(const sphere &other);
    float get_a();
    void set_a(float i);
    float get_b();
    void set_b(float j);
    float get_c();
    void set_c(float k);
    float get_precision();
    void set_precision(float p);
    const float *get_ambient_color();
    const float *get_diffuse_color();
    const float *get_specular_color();
    unsigned int get_shininess();
    std::vector<polygon> &get_polygons();
    void create();
    void clear_polygons();
    size_t get_polygons_size();
};

#endif // sphere_H
