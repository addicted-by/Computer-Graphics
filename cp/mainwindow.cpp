#include "mainwindow.h"
#include <QDockWidget>
#include <QMatrix4x4>
#include <cmath>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{


    vw = new view();
    //vw->resize(800,800);
    setCentralWidget(vw);
    pan = new Panel();
    pan->resize(400, 100);
    QDockWidget *dock = new QDockWidget("panel");
    dock->setWidget(pan);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
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
}

MainWindow::~MainWindow()
{
}

void MainWindow::turn_left() {
    QMatrix4x4 matrix_Ry{
        static_cast<float>(cos(-M_PI / 6.)), 0, static_cast<float>(-sin(M_PI / 6.)), 0,
        0, 1, 0, 0,
        static_cast<float>(-sin(-M_PI / 6.)), 0, static_cast<float>(cos(-M_PI / 6.)), 0,
        0, 0, 0, 1
    };

//    for (auto i = 0; i < vw->fig1.points_x.size(); i++) {
//        vw->fig1.points_x[i] = vw->fig1.points_x[i] * cos(-M_PI / 6.) + vw->fig1.points_z[i] * sin(-M_PI / 6.);
//        vw->fig2.points_x[i] = vw->fig2.points_x[i] * cos(-M_PI / 6.) + vw->fig2.points_z[i] * sin(-M_PI / 6.);
//        vw->fig2.points_z[i] = -vw->fig2.points_x[i] * sin(-M_PI / 6.) + vw->fig2.points_z[i] * cos(-M_PI / 6.);
//        vw->fig1.points_z[i] = -vw->fig1.points_x[i] * sin(-M_PI / 6.) + vw->fig1.points_z[i] * cos(-M_PI / 6.);
//        vw->update();
//    }
    double prev_x1_1, prev_x2_1, prev_x3_1, prev_x4_1, prev_x1_2, prev_x2_2, prev_x3_2, prev_x4_2;
    prev_x1_1 = vw->mPoint1_1.x();
    prev_x2_1 = vw->mPoint2_1.x();
    prev_x3_1 = vw->mPoint3_1.x();
    prev_x4_1 = vw->mPoint4_1.x();
    prev_x1_2 = vw->mPoint1_2.x();
    prev_x2_2 = vw->mPoint2_2.x();
    prev_x3_2 = vw->mPoint3_2.x();
    prev_x4_2 = vw->mPoint4_2.x();
    vw->mPoint1_1.rx() = vw->mPoint1_1.x() * cos(-M_PI / 8.) + vw->z1_1 * sin(-M_PI / 8.);
    vw->mPoint2_1.rx() = vw->mPoint2_1.x() * cos(-M_PI / 8.) + vw->z1_2 * sin(-M_PI / 8.) ;
    vw->mPoint3_1.rx() = vw->mPoint3_1.x() * cos(-M_PI / 8.) + vw->z1_3 * sin(-M_PI / 8.);
    vw->mPoint4_1.rx() = vw->mPoint4_1.x() * cos(-M_PI / 8.) + vw->z1_4 * sin(-M_PI / 8.) ;

    vw->z1_1 = -prev_x1_1 * sin(-M_PI / 8.) + vw->z1_1 * cos(-M_PI / 8.);
    vw->z1_2 = -prev_x2_1 * sin(-M_PI / 8.) + vw->z1_2 * cos(-M_PI / 8.);
    vw->z1_3 = -prev_x3_1 * sin(-M_PI / 8.) + vw->z1_3 * cos(-M_PI / 8.);
    vw->z1_4 = -prev_x4_1 * sin(-M_PI / 8.) + vw->z1_4 * cos(-M_PI / 8.);

    vw->mPoint1_2.rx() = vw->mPoint1_2.x() * cos(-M_PI / 8.) + vw->z2_1 * sin(-M_PI / 8.);
    vw->mPoint2_2.rx() = vw->mPoint2_2.x() * cos(-M_PI / 8.) + vw->z2_2 * sin(-M_PI / 8.);
    vw->mPoint3_2.rx() = vw->mPoint3_2.x() * cos(-M_PI / 8.) + vw->z2_3 * sin(-M_PI / 8.);
    vw->mPoint4_2.rx() = vw->mPoint4_2.x() * cos(-M_PI / 8.) + vw->z2_4 * sin(-M_PI / 8.);

    vw->z2_1 = -prev_x1_2 * sin(-M_PI / 8.) + vw->z2_1 * cos(-M_PI / 8.);
    vw->z2_2 = -prev_x2_2 * sin(-M_PI / 8.) + vw->z2_2 * cos(-M_PI / 8.);
    vw->z2_3 = -prev_x3_2 * sin(-M_PI / 8.) + vw->z2_3 * cos(-M_PI / 8.);
    vw->z2_4 = -prev_x4_2 * sin(-M_PI / 8.) + vw->z2_4 * cos(-M_PI / 8.);
    vw->update();
//    vw->mPoint1_1.rx() = vw->mPoint1_1.x() * cos(-M_PI / 8.) + vw->fig1.z1 * sin(-M_PI / 8.);
//    vw->mPoint2_1.rx() = vw->mPoint2_1.x() * cos(-M_PI / 8.) + vw->fig1.z2 * sin(-M_PI / 8.);
//    vw->mPoint3_1.rx() = vw->mPoint3_1.x() * cos(-M_PI / 8.) + vw->fig1.z3 * sin(-M_PI / 8.);
//    vw->mPoint4_1.rx() = vw->mPoint4_1.x() * cos(-M_PI / 8.) + vw->fig1.z4 * sin(-M_PI / 8.);
//    vw->fig1.z1 = -vw->mPoint1_1.x() * sin(-M_PI / 8.) + vw->fig1.z1 * cos(-M_PI / 8.);
//    vw->fig1.z2 = -vw->mPoint2_1.x() * sin(-M_PI / 8.) + vw->fig1.z2 * cos(-M_PI / 8.);
//    vw->fig1.z3 = -vw->mPoint3_1.x() * sin(-M_PI / 8.) + vw->fig1.z3 * cos(-M_PI / 8.);
//    vw->fig1.z4 = -vw->mPoint4_1.x() * sin(-M_PI / 8.) + vw->fig1.z4 * cos(-M_PI / 8.);

//    vw->mPoint1_2.rx() = vw->mPoint1_2.x() * cos(-M_PI / 8.) + vw->fig2.z1 * sin(M_PI / 8.);
//    vw->mPoint2_2.rx() = vw->mPoint2_2.x() * cos(-M_PI / 8.) + vw->fig2.z2 * sin(-M_PI / 8.);
//    vw->mPoint3_2.rx() = vw->mPoint3_2.x() * cos(-M_PI / 8.) + vw->fig2.z3 * sin(-M_PI / 8.);
//    vw->mPoint4_2.rx() = vw->mPoint4_2.x() * cos(-M_PI / 8.) + vw->fig2.z4 * sin(-M_PI / 8.);
//    vw->fig2.z1 = -vw->mPoint1_2.x() * sin(-M_PI / 8.) + vw->fig2.z1 * cos(-M_PI / 8.);
//    vw->fig2.z2 = -vw->mPoint2_2.x() * sin(-M_PI / 8.) + vw->fig2.z2 * cos(-M_PI / 8.);
//    vw->fig2.z3 = -vw->mPoint3_2.x() * sin(-M_PI / 8.) + vw->fig2.z3 * cos(-M_PI / 8.);
//    vw->fig2.z4 = -vw->mPoint4_2.x() * sin(-M_PI / 8.) + vw->fig2.z4 * cos(-M_PI / 8.);
}
void MainWindow::turn_right() {

    double prev_x1_1, prev_x2_1, prev_x3_1, prev_x4_1, prev_x1_2, prev_x2_2, prev_x3_2, prev_x4_2;
    prev_x1_1 = vw->mPoint1_1.x();
    prev_x2_1 = vw->mPoint2_1.x();
    prev_x3_1 = vw->mPoint3_1.x();
    prev_x4_1 = vw->mPoint4_1.x();
    prev_x1_2 = vw->mPoint1_2.x();
    prev_x2_2 = vw->mPoint2_2.x();
    prev_x3_2 = vw->mPoint3_2.x();
    prev_x4_2 = vw->mPoint4_2.x();
    vw->mPoint1_1.rx() = vw->mPoint1_1.x() * cos(M_PI / 8.) + vw->z1_1 * sin(M_PI / 8.);
    vw->mPoint2_1.rx() = vw->mPoint2_1.x() * cos(M_PI / 8.) + vw->z1_2 * sin(M_PI / 8.) ;
    vw->mPoint3_1.rx() = vw->mPoint3_1.x() * cos(M_PI / 8.) + vw->z1_3 * sin(M_PI / 8.);
    vw->mPoint4_1.rx() = vw->mPoint4_1.x() * cos(M_PI / 8.) + vw->z1_4 * sin(M_PI / 8.) ;

    vw->z1_1 = -prev_x1_1 * sin(M_PI / 8.) + vw->z1_1 * cos(M_PI / 8.);
    vw->z1_2 = -prev_x2_1 * sin(M_PI / 8.) + vw->z1_2 * cos(M_PI / 8.);
    vw->z1_3 = -prev_x3_1 * sin(M_PI / 8.) + vw->z1_3 * cos(M_PI / 8.);
    vw->z1_4 = -prev_x4_1 * sin(M_PI / 8.) + vw->z1_4 * cos(M_PI / 8.);

    vw->mPoint1_2.rx() = vw->mPoint1_2.x() * cos(M_PI / 8.) + vw->z2_1 * sin(M_PI / 8.);
    vw->mPoint2_2.rx() = vw->mPoint2_2.x() * cos(M_PI / 8.) + vw->z2_2 * sin(M_PI / 8.);
    vw->mPoint3_2.rx() = vw->mPoint3_2.x() * cos(M_PI / 8.) + vw->z2_3 * sin(M_PI / 8.);
    vw->mPoint4_2.rx() = vw->mPoint4_2.x() * cos(M_PI / 8.) + vw->z2_4 * sin(M_PI / 8.);

    vw->z2_1 = -prev_x1_2 * sin(M_PI / 8.) + vw->z2_1 * cos(M_PI / 8.);
    vw->z2_2 = -prev_x2_2 * sin(M_PI / 8.) + vw->z2_2 * cos(M_PI / 8.);
    vw->z2_3 = -prev_x3_2 * sin(M_PI / 8.) + vw->z2_3 * cos(M_PI / 8.);
    vw->z2_4 = -prev_x4_2 * sin(M_PI / 8.) + vw->z2_4 * cos(M_PI / 8.);
    vw->update();
}

void MainWindow::turn_up() {
    QMatrix4x4 matrix_Rx{
        1, 0, 0, 0,
        0, static_cast<float>(cos(M_PI / 6.)), static_cast<float>(-sin(M_PI / 6.)), 0,
        0, static_cast<float>(sin(M_PI / 6.)), static_cast<float>(cos(M_PI / 6.)), 0,
        0, 0, 0, 1
    };
    double prev_y1_1, prev_y2_1, prev_y3_1, prev_y4_1, prev_y1_2, prev_y2_2, prev_y3_2, prev_y4_2;
    prev_y1_1 = vw->mPoint1_1.y();
    prev_y2_1 = vw->mPoint2_1.y();
    prev_y3_1 = vw->mPoint3_1.y();
    prev_y4_1 = vw->mPoint4_1.y();
    prev_y1_2 = vw->mPoint1_2.y();
    prev_y2_2 = vw->mPoint2_2.y();
    prev_y3_2 = vw->mPoint3_2.y();
    prev_y4_2 = vw->mPoint4_2.y();
    vw->mPoint1_1.ry() = vw->mPoint1_1.y() * cos(M_PI / 8.) - vw->z1_1 * sin(M_PI / 8.);
    vw->mPoint2_1.ry() = vw->mPoint2_1.y() * cos(M_PI / 8.) - vw->z1_2 * sin(M_PI / 8.) ;
    vw->mPoint3_1.ry() = vw->mPoint3_1.y() * cos(M_PI / 8.) - vw->z1_3 * sin(M_PI / 8.);
    vw->mPoint4_1.ry() = vw->mPoint4_1.y() * cos(M_PI / 8.) - vw->z1_4 * sin(M_PI / 8.) ;

    vw->z1_1 = prev_y1_1 * sin(M_PI / 8.) + vw->z1_1 * cos(M_PI / 8.);
    vw->z1_2 = prev_y2_1 * sin(M_PI / 8.) + vw->z1_2 * cos(M_PI / 8.);
    vw->z1_3 = prev_y3_1 * sin(M_PI / 8.) + vw->z1_3 * cos(M_PI / 8.);
    vw->z1_4 = prev_y4_1 * sin(M_PI / 8.) + vw->z1_4 * cos(M_PI / 8.);

    vw->mPoint1_2.ry() = vw->mPoint1_2.y() * cos(M_PI / 8.) - vw->z2_1 * sin(M_PI / 8.);
    vw->mPoint2_2.ry() = vw->mPoint2_2.y() * cos(M_PI / 8.) - vw->z2_2 * sin(M_PI / 8.);
    vw->mPoint3_2.ry() = vw->mPoint3_2.y() * cos(M_PI / 8.) - vw->z2_3 * sin(M_PI / 8.);
    vw->mPoint4_2.ry() = vw->mPoint4_2.y() * cos(M_PI / 8.) - vw->z2_4 * sin(M_PI / 8.);

    vw->z2_1 = prev_y1_2 * sin(M_PI / 8.) + vw->z2_1 * cos(M_PI / 8.);
    vw->z2_2 = prev_y2_2 * sin(M_PI / 8.) + vw->z2_2 * cos(M_PI / 8.);
    vw->z2_3 = prev_y3_2 * sin(M_PI / 8.) + vw->z2_3 * cos(M_PI / 8.);
    vw->z2_4 = prev_y4_2 * sin(M_PI / 8.) + vw->z2_4 * cos(M_PI / 8.);

    //vw->fig.fullTransformation = matrix_Rx * vw->fig.fullTransformation;
    vw->update();
}

void MainWindow::turn_down() {
    QMatrix4x4 matrix_Rx{
        1, 0, 0, 0,
        0, static_cast<float>(cos(-M_PI / 6.)), static_cast<float>(-sin(-M_PI / 6.)), 0,
        0, static_cast<float>(sin(-M_PI / 6.)), static_cast<float>(cos(-M_PI / 6.)), 0,
        0, 0, 0, 1
    };
    double prev_y1_1, prev_y2_1, prev_y3_1, prev_y4_1, prev_y1_2, prev_y2_2, prev_y3_2, prev_y4_2;
    prev_y1_1 = vw->mPoint1_1.y();
    prev_y2_1 = vw->mPoint2_1.y();
    prev_y3_1 = vw->mPoint3_1.y();
    prev_y4_1 = vw->mPoint4_1.y();
    prev_y1_2 = vw->mPoint1_2.y();
    prev_y2_2 = vw->mPoint2_2.y();
    prev_y3_2 = vw->mPoint3_2.y();
    prev_y4_2 = vw->mPoint4_2.y();
    vw->mPoint1_1.ry() = vw->mPoint1_1.y() * cos(-M_PI / 8.) - vw->z1_1 * sin(-M_PI / 8.);
    vw->mPoint2_1.ry() = vw->mPoint2_1.y() * cos(-M_PI / 8.) - vw->z1_2 * sin(-M_PI / 8.) ;
    vw->mPoint3_1.ry() = vw->mPoint3_1.y() * cos(-M_PI / 8.) - vw->z1_3 * sin(-M_PI / 8.);
    vw->mPoint4_1.ry() = vw->mPoint4_1.y() * cos(-M_PI / 8.) - vw->z1_4 * sin(-M_PI / 8.) ;

    vw->z1_1 = prev_y1_1 * sin(-M_PI / 8.) + vw->z1_1 * cos(-M_PI / 8.);
    vw->z1_2 = prev_y2_1 * sin(-M_PI / 8.) + vw->z1_2 * cos(-M_PI / 8.);
    vw->z1_3 = prev_y3_1 * sin(-M_PI / 8.) + vw->z1_3 * cos(-M_PI / 8.);
    vw->z1_4 = prev_y4_1 * sin(-M_PI / 8.) + vw->z1_4 * cos(-M_PI / 8.);

    vw->mPoint1_2.ry() = vw->mPoint1_2.y() * cos(-M_PI / 8.) - vw->z2_1 * sin(-M_PI / 8.);
    vw->mPoint2_2.ry() = vw->mPoint2_2.y() * cos(-M_PI / 8.) - vw->z2_2 * sin(-M_PI / 8.);
    vw->mPoint3_2.ry() = vw->mPoint3_2.y() * cos(-M_PI / 8.) - vw->z2_3 * sin(-M_PI / 8.);
    vw->mPoint4_2.ry() = vw->mPoint4_2.y() * cos(-M_PI / 8.) - vw->z2_4 * sin(-M_PI / 8.);

    vw->z2_1 = prev_y1_2 * sin(-M_PI / 8.) + vw->z2_1 * cos(-M_PI / 8.);
    vw->z2_2 = prev_y2_2 * sin(-M_PI / 8.) + vw->z2_2 * cos(-M_PI / 8.);
    vw->z2_3 = prev_y3_2 * sin(-M_PI / 8.) + vw->z2_3 * cos(-M_PI / 8.);
    vw->z2_4 = prev_y4_2 * sin(-M_PI / 8.) + vw->z2_4 * cos(-M_PI / 8.);

    //vw->fig.fullTransformation = matrix_Rx * vw->fig.fullTransformation;
    vw->update();
}

void MainWindow::change_appr(int sliderValue) {
    QTextStream out(stdout);
//    vw->fig.set_step(sliderValue / 10.);
//    vw->fig.clear_polygons();
//    vw->fig.create();
//    vw->fig.change_sphere(vw->fig.fullTransformation);
//    pan->set_cnt_polygons(static_cast<int>(vw->fig.polygons.size()));
    vw->s1 = sliderValue / 100.;
    vw->update();
}
