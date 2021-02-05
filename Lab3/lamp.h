#ifndef LAMP_H
#define LAMP_H

#include <QVector3D>

class Lamp //Класс светильник
{
public:
    QVector3D position;
    int power;

    Lamp(int p, double x, double y, double z);
    void set_power(const int p);
    void set_position(const QVector3D &v);
    void set_position(const double x, const double y, const double z);
};

#endif // LAMP_H
