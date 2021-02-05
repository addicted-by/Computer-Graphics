#include "panel.h"
#include <QGridLayout>

Panel::Panel(QWidget *parent) : QWidget(parent)
{
//    left = new QPushButton("left", this);
//    right = new QPushButton("right", this);
//    up = new QPushButton("up", this);
//    down = new QPushButton("down", this);
    approximation = new QSlider(Qt::Horizontal);
    approximation->setMinimum(1);
    approximation->setMaximum(9);
    approximation->setTickPosition(QSlider::TicksAbove);
    approximation->setTickInterval(1);
    approximation->setValue(4);
    cntPolygons = new QLabel(this);
    cntPolygons->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    cntPolygons->setFrameStyle(QFrame::Box);
    plusScale = new QPushButton("+", this);
    minusScale = new QPushButton("-", this);
    lamp_x = new QLabel("Lamp position x:", this);
    lamp_x_input = new QLineEdit(this);
    lamp_y = new QLabel("Lamp position y:", this);
    lamp_y_input = new QLineEdit(this);
    lamp_z = new QLabel("Lamp position z:", this);
    lamp_z_input = new QLineEdit(this);
//    lamp_power = new QLabel("Power lamp:", this);
//    lamp_power_input = new QLineEdit(this);
    apply = new QPushButton("Apply", this);
    display_carcass = new QCheckBox("Display carcass", this);
    pos_fig_x = new QSlider(Qt::Horizontal);
    pos_fig_x->setMinimum(0);
    pos_fig_x->setMaximum(360);
    pos_fig_x->setTickPosition(QSlider::TicksAbove);
    pos_fig_x->setTickInterval(5);
    pos_fig_x->setValue(0);
    pos_fig_y = new QSlider(Qt::Horizontal);
    pos_fig_y->setMinimum(0);
    pos_fig_y->setMaximum(360);
    pos_fig_y->setTickPosition(QSlider::TicksAbove);
    pos_fig_y->setTickInterval(5);
    pos_fig_y->setValue(0);
    pos_fig_z = new QSlider(Qt::Horizontal);
    pos_fig_z->setMinimum(0);
    pos_fig_z->setMaximum(360);
    pos_fig_z->setTickPosition(QSlider::TicksAbove);
    pos_fig_z->setTickInterval(5);
    pos_fig_z->setValue(0);
    animation = new QPushButton("animate", this);

    QGridLayout *grid = new QGridLayout();
//    grid->addWidget(left, 1, 0);
//    grid->addWidget(down, 1, 1);
//    grid->addWidget(up, 0, 1);
//    grid->addWidget(right, 1, 2);
    grid->addWidget(approximation, 0, 0, 2, 0);
    grid->addWidget(cntPolygons, 2, 0);
    grid->addWidget(plusScale, 3, 0);
    grid->addWidget(minusScale, 3, 2);
    grid->addWidget(lamp_x, 4, 0);
//    grid->addWidget(lamp_power, 4, 2);
    grid->addWidget(lamp_x_input, 5, 0);
//    grid->addWidget(lamp_power_input, 5, 2);
    grid->addWidget(apply, 5, 2);
    grid->addWidget(lamp_y, 6, 0);
    grid->addWidget(lamp_y_input, 7, 0);
    grid->addWidget(lamp_z, 8, 0);
    grid->addWidget(lamp_z_input, 9, 0);
    grid->addWidget(animation, 16,0);
    grid->addWidget(display_carcass, 10, 0);
    grid->addWidget(pos_fig_x, 11, 0, 1, 0);
    grid->addWidget(pos_fig_y, 13, 0, 1, 0);
    grid->addWidget(pos_fig_z, 15, 0, 1, 0);
    QVBoxLayout *stretchLout = new QVBoxLayout();
    stretchLout->addStretch();

    grid->addLayout(stretchLout, 17, 0);
    setLayout(grid);

//    connect(left, SIGNAL(pressed()),
//            this, SIGNAL(push_left()));
//    connect(right, SIGNAL(pressed()),
//            this, SIGNAL(push_right()));
//    connect(up, SIGNAL(pressed()),
//            this, SIGNAL(push_up()));
//    connect(down, SIGNAL(pressed()),
//            this, SIGNAL(push_down()));
    connect(approximation, SIGNAL(valueChanged(int)),
            this, SIGNAL(approximation_changed(int)));
    connect(plusScale, SIGNAL(pressed()),
            this, SIGNAL(plus_scale()));
    connect(minusScale, SIGNAL(pressed()),
            this, SIGNAL(minus_scale()));
    connect(apply, SIGNAL(pressed()),
            this, SIGNAL(push_apply()));
    connect(display_carcass, SIGNAL(clicked(bool)),
            this, SIGNAL(clicked_display_carcass(bool)));
    connect(pos_fig_x, SIGNAL(valueChanged(int)),
            this, SIGNAL(pos_fig_x_changed(int)));
    connect(pos_fig_y, SIGNAL(valueChanged(int)),
            this, SIGNAL(pos_fig_y_changed(int)));
    connect(pos_fig_z, SIGNAL(valueChanged(int)),
            this, SIGNAL(pos_fig_z_changed(int)));
    connect(animation, SIGNAL(pressed()), this, SIGNAL(on_off_animation()));
}

void Panel::set_cnt_polygons(size_t cnt) {
    cntPolygons->setNum(static_cast<int>(cnt));
}

float Panel::get_lamp_pos_x() {
    return lamp_x_input->text().toFloat();
}

float Panel::get_lamp_pos_y() {
    return lamp_y_input->text().toFloat();
}

float Panel::get_lamp_pos_z() {
    return lamp_z_input->text().toFloat();
}

void Panel::set_lamp_pos_x(float x) {
    lamp_x_input->setText(QString::number(static_cast<double>(x)));
}

void Panel::set_lamp_pos_y(float y) {
    lamp_y_input->setText(QString::number(static_cast<double>(y)));
}

void Panel::set_lamp_pos_z(float z) {
    lamp_z_input->setText(QString::number(static_cast<double>(z)));
}
