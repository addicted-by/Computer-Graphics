#include "panel.h"
#include <QGridLayout>

Panel::Panel(QWidget *parent) : QWidget(parent)
{
    left = new QPushButton("+", this);
    right = new QPushButton("-", this);
    up = new QPushButton("+", this);
    down = new QPushButton("-", this);
    approximation = new QSlider(Qt::Horizontal);
    approximation->setMinimum(1);
    approximation->setMaximum(9);
    approximation->setTickPosition(QSlider::TicksAbove);
    approximation->setTickInterval(1);
    approximation->setValue(1);

    QGridLayout *grid = new QGridLayout();
    grid->addWidget(left, 11, 1);
    grid->addWidget(down, 12, 2);
    grid->addWidget(up, 10, 2);
    grid->addWidget(right, 11, 3);
    grid->addWidget(approximation, 2, 0, 2, 0);
    //grid->addWidget(nextPoint, 0, 12);
    QVBoxLayout *stretchLout = new QVBoxLayout();
    stretchLout->addStretch();
    grid->addLayout(stretchLout, 13, 0);
    setLayout(grid);

    connect(left, SIGNAL(pressed()),
            this, SIGNAL(push_left()));
    connect(right, SIGNAL(pressed()),
            this, SIGNAL(push_right()));
    connect(up, SIGNAL(pressed()),
            this, SIGNAL(push_up()));
    connect(down, SIGNAL(pressed()),
            this, SIGNAL(push_down()));
    connect(approximation, SIGNAL(valueChanged(int)),
            this, SIGNAL(approximation_changed(int)));
    //connect(nextPoint, SIGNAL(pressed()),
      //      this, SIGNAL(next_point()));
//    connect(apply, SIGNAL(pressed()),
//            this, SIGNAL(push_apply()));

}

//void Panel::set_cnt_polygons(int cnt) {
//    cntPolygons->setNum(cnt);
//}

