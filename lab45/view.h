#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QOpenGLFunctions>
#include "sphere.h"

class View : public QGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

    sphere fig;
    bool displayCarcass;
    float rotateX;
    float rotateY;
    float rotateZ;
    float scale;
    float lightPositionX;
    float lightPositionY;
    float lightPositionZ;

public:
    View(QWidget *parent = nullptr);
    ~View() override;
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    sphere &get_fig();
    void change_display_carcass();
    void change_angle_rotate_x(float angle);
    void change_angle_rotate_y(float angle);
    void change_angle_rotate_z(float angle);
    void change_scale(float dif);
    float get_scale();
    void set_light_position_x(float x_pos);
    void set_light_position_y(float y_pos);
    void set_light_position_z(float z_pos);
    float get_light_position_x();
    float get_light_position_y();
    float get_light_position_z();
};

#endif // WIDGET_H
