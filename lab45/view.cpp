#include "view.h"
#include <QGLWidget>
#include <QOpenGLFunctions>

View::View(QWidget *parent)
    : QGLWidget(parent), fig(sphere(0.9f, 0.4f, 0.4f)) {
    displayCarcass = false;
    rotateX = rotateY = rotateZ = 0.f;
    scale = 1.f;
    lightPositionX = lightPositionY = 0.f;
    lightPositionZ = 0.f;
}

View::~View() {

}

void View::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.f, 0.f, 0.f, 1.f);

    glEnable(GL_DEPTH_TEST);
}

void View::resizeGL(int width, int height) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
}

void View::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float a, b, c;
    a = fig.get_a();
    b = fig.get_b();
    c = fig.get_c();
    if (a < 1.f) {
        a = 1.;
    }
    if (b < 1.f) {
        b = 1.;
    }
    if (c < 1.f) {
        c = 1.;
    }
    glOrtho(-2. * static_cast<double>(a), 2. * static_cast<double>(a), -2. * static_cast<double>(b),
            2. * static_cast<double>(b), -2. * static_cast<double>(c), 2. * static_cast<double>(c));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(rotateX, 1.f, 0.f, 0.f);
    glRotatef(rotateY, 0.f, 1.f, 0.f);
    glRotatef(rotateZ, 0.f, 0.f, 1.f);
    glScalef(scale, scale, scale);

    if (displayCarcass) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDisable(GL_LIGHTING);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glEnable(GL_LIGHTING);
    }

    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_NORMALIZE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, fig.get_ambient_color());
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fig.get_diffuse_color());
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, fig.get_specular_color());
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, fig.get_shininess());

    float light_ambient[] = {0.f, 0.22f, 0.51f, 1.f};
    float light_diffuse[] = {1.f, 1.f, 1.f, 1.f};
    float light_specular[] = {1.f, 1.f, 1.f, 1.f};
    float light_position[] = {lightPositionX,
                              lightPositionY,
                              lightPositionZ, 1.f};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 128);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.f);
    glPopMatrix();
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glColor3f(1.f, 0.f, 0.f);
    for (auto polygon: fig.get_polygons()) {
        glBegin(GL_POLYGON);
            for (auto vertex: polygon.vertices) {
                glVertex3f(vertex.x(), vertex.y(), vertex.z());
            }
        glEnd();
    }
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
}

sphere &View::get_fig() {
    return fig;
}

void View::change_display_carcass() {
    displayCarcass = (displayCarcass == true ? false : true);
}

void View::change_angle_rotate_x(float angle) {
    rotateX = static_cast<int>(angle) % 360;
}

void View::change_angle_rotate_y(float angle) {
    rotateY = static_cast<int>(angle) % 360;
}

void View::change_angle_rotate_z(float angle) {
    rotateZ = static_cast<int>(angle) % 360;
}

void View::change_scale(float dif) {
    scale += dif;
}

float View::get_scale() {
    return scale;
}

void View::set_light_position_x(float x_pos) {
    lightPositionX = x_pos;
}

void View::set_light_position_y(float y_pos) {
    lightPositionY = y_pos;
}

void View::set_light_position_z(float z_pos) {
    lightPositionZ = z_pos;
}

float View::get_light_position_x() {
    return lightPositionX;
}

float View::get_light_position_y() {
    return lightPositionY;
}

float View::get_light_position_z() {
    return lightPositionZ;
}
