#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QMatrix4x4>
#include <cmath>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pan = new Panel();
    pan->resize(400, 100);
    QDockWidget *dock = new QDockWidget("panel");
    dock->setWidget(pan);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    vw = new view();
    setCentralWidget(vw);
    pan->set_cnt_polygons(static_cast<int>(vw->fig.polygons.size()));
    QVector3D pos_lamp = vw->fig.lamp->position;
    pan->set_lamp_position(pos_lamp);
    int power_lamp = vw->fig.lamp->power;
    pan->set_lamp_power(power_lamp);

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
            this, SLOT(change_lamp()));
    connect(pan, SIGNAL(clicked_display_carcass(bool)),
            this, SLOT(display_carcass(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::turn_left() {
    QMatrix4x4 matrix_Ry{
        static_cast<float>(cos(-M_PI / 6.)), 0, static_cast<float>(-sin(M_PI / 6.)), 0,
        0, 1, 0, 0,
        static_cast<float>(-sin(-M_PI / 6.)), 0, static_cast<float>(cos(-M_PI / 6.)), 0,
        0, 0, 0, 1
    };

    vw->fig.change_sphere(matrix_Ry);
    vw->fig.fullTransformation = matrix_Ry * vw->fig.fullTransformation;
    vw->update();
}

void MainWindow::turn_right() {
    QMatrix4x4 matrix_Ry{
        static_cast<float>(cos(M_PI / 6.)), 0, static_cast<float>(sin(M_PI / 6.)), 0,
        0, 1, 0, 0,
        static_cast<float>(-sin(M_PI / 6.)), 0, static_cast<float>(cos(M_PI / 6.)), 0,
        0, 0, 0, 1
    };

    vw->fig.change_sphere(matrix_Ry);
    vw->fig.fullTransformation = matrix_Ry * vw->fig.fullTransformation;
    vw->update();
}

void MainWindow::turn_up() {
    QMatrix4x4 matrix_Rx{
        1, 0, 0, 0,
        0, static_cast<float>(cos(M_PI / 6.)), static_cast<float>(-sin(M_PI / 6.)), 0,
        0, static_cast<float>(sin(M_PI / 6.)), static_cast<float>(cos(M_PI / 6.)), 0,
        0, 0, 0, 1
    };

    vw->fig.change_sphere(matrix_Rx);
    vw->fig.fullTransformation = matrix_Rx * vw->fig.fullTransformation;
    vw->update();
}

void MainWindow::turn_down() {
    QMatrix4x4 matrix_Rx{
        1, 0, 0, 0,
        0, static_cast<float>(cos(-M_PI / 6.)), static_cast<float>(-sin(-M_PI / 6.)), 0,
        0, static_cast<float>(sin(-M_PI / 6.)), static_cast<float>(cos(-M_PI / 6.)), 0,
        0, 0, 0, 1
    };

    vw->fig.change_sphere(matrix_Rx);
    vw->fig.fullTransformation = matrix_Rx * vw->fig.fullTransformation;
    vw->update();
}

void MainWindow::change_appr(int sliderValue) {
    QTextStream out(stdout);
    vw->fig.set_step(sliderValue / 10.);
    vw->fig.clear_polygons();
    vw->fig.create();
    vw->fig.change_sphere(vw->fig.fullTransformation);
    pan->set_cnt_polygons(static_cast<int>(vw->fig.polygons.size()));
    vw->update();
}

void MainWindow::plus_scale() {
    vw->step += 25;
    vw->fig.clear_polygons();
    vw->fig.create();
    vw->fig.change_sphere(vw->fig.fullTransformation);
    vw->update();
}

void MainWindow::minus_scale() {
    if (vw->step - 25 > 0) {
        vw->step -= 25;
        vw->fig.clear_polygons();
        vw->fig.create();
        vw->fig.change_sphere(vw->fig.fullTransformation);
        vw->update();
    }
}

void MainWindow::change_lamp() {
    vw->fig.lamp->set_position(pan->get_lamp_position());
    vw->fig.lamp->set_power(pan->get_lamp_power());
    vw->update();
}

void MainWindow::display_carcass(bool) {
    bool display = vw->fig.displayCarcass;
    vw->fig.displayCarcass = !display;
    vw->update();
}
