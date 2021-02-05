#include "mainwindow.h"
#include <QDockWidget>
#include <QGLWidget>
#include <QOpenGLFunctions>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    pan = new Panel();
    QDockWidget *dock = new QDockWidget("panel");
    dock->setWidget(pan);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    vw = new View();
    setCentralWidget(vw);
    pr_val[0] = 0.05f; pr_val[1] = 0.06f; pr_val[2] = 0.07f;
    pr_val[3] = 0.08f; pr_val[4] = 0.09f; pr_val[5] = 0.1f;
    pr_val[6] = 0.2f; pr_val[7] = 0.3f; pr_val[8] = 0.4f;
    pan->set_cnt_polygons(vw->get_fig().get_polygons_size());
    pan->set_lamp_pos_x(vw->get_light_position_x());
    pan->set_lamp_pos_y(vw->get_light_position_y());
    pan->set_lamp_pos_z(vw->get_light_position_z());
    animation = false;

    connect(pan, SIGNAL(push_left()),
            this, SLOT(turn_left()));
    connect(pan, SIGNAL(push_right()),
            this, SLOT(turn_right()));
    connect(pan, SIGNAL(push_up()),
            this, SLOT(turn_up()));
    connect(pan, SIGNAL(push_down()),
            this, SLOT(turn_down()));
    connect(pan, SIGNAL(approximation_changed(int)),
            this, SLOT(change_appr(int)));
    connect(pan, SIGNAL(plus_scale()),
            this, SLOT(plus_scale()));
    connect(pan, SIGNAL(minus_scale()),
            this, SLOT(minus_scale()));
    connect(pan, SIGNAL(push_apply()),
            this, SLOT(change_pos_lamp()));
    connect(pan, SIGNAL(clicked_display_carcass(bool)),
            this, SLOT(display_carcass(bool)));
    connect(pan, SIGNAL(pos_fig_x_changed(int)),
            this, SLOT(change_pos_fig_x(int)));
    connect(pan, SIGNAL(pos_fig_y_changed(int)),
            this, SLOT(change_pos_fig_y(int)));
    connect(pan, SIGNAL(pos_fig_z_changed(int)),
            this, SLOT(change_pos_fig_z(int)));
    connect(pan, SIGNAL(on_off_animation()), this, SLOT(on_off_animation()));
}

void MainWindow::turn_left() {
    vw->change_angle_rotate_y(-10.f);
    vw->updateGL();
}

void MainWindow::turn_right() {
    vw->change_angle_rotate_y(10.f);
    vw->updateGL();
}

void MainWindow::turn_up() {
    vw->change_angle_rotate_x(-10.f);
    vw->updateGL();
}

void MainWindow::turn_down() {
    vw->change_angle_rotate_x(10.f);
    vw->updateGL();
}

void MainWindow::change_appr(int sliderValue) {
    vw->get_fig().set_precision(pr_val[sliderValue - 1]);
    vw->get_fig().clear_polygons();
    vw->get_fig().create();
    pan->set_cnt_polygons(vw->get_fig().get_polygons_size());
    vw->updateGL();
}

void MainWindow::plus_scale() {
    vw->change_scale(0.25f);
    vw->updateGL();
}

void MainWindow::minus_scale() {
    if (vw->get_scale() <= 0.25f) {
        return;
    }
    vw->change_scale(-0.25f);
    vw->updateGL();
}

void MainWindow::change_pos_lamp() {
    vw->set_light_position_x(pan->get_lamp_pos_x());
    vw->set_light_position_y(pan->get_lamp_pos_y());
    vw->set_light_position_z(pan->get_lamp_pos_z());
    vw->updateGL();
}

void MainWindow::display_carcass(bool) {
    vw->change_display_carcass();
    vw->updateGL();
}

void MainWindow::change_pos_fig_x(int val) {
    vw->change_angle_rotate_x(val);
    vw->updateGL();
}

void MainWindow::change_pos_fig_y(int val) {
    vw->change_angle_rotate_y(val);
    vw->updateGL();
}

void MainWindow::change_pos_fig_z(int val) {
    vw->change_angle_rotate_z(val);
    vw->updateGL();
}
void MainWindow::on_off_animation(){
    if (!animation){
        vw->start_timer();
        animation = true;
    } else {
        vw->stop_timer();
        animation = false;
    }
}
