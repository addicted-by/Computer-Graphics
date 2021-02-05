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
    lamp_power = new QLabel("Power lamp:", this);
    lamp_power_input = new QLineEdit(this);
    apply = new QPushButton("Apply", this);
    display_carcass = new QCheckBox("Display carcass", this);

    QGridLayout *grid = new QGridLayout();
    grid->addWidget(left, 11, 1);
    grid->addWidget(down, 12, 2);
    grid->addWidget(up, 10, 2);
    grid->addWidget(right, 11, 3);
    grid->addWidget(approximation, 2, 0, 2, 0);
    grid->addWidget(cntPolygons, 4, 0);
    grid->addWidget(plusScale, 5, 0);
    grid->addWidget(minusScale, 5, 2);
    grid->addWidget(lamp_x, 6, 0);
    grid->addWidget(lamp_power, 6, 2);
    grid->addWidget(lamp_x_input, 7, 0);
    grid->addWidget(lamp_power_input, 7, 2);
    grid->addWidget(lamp_y, 8, 0);
    grid->addWidget(apply, 8, 2);
    grid->addWidget(lamp_y_input, 9, 0);
    grid->addWidget(lamp_z, 10, 0);
    grid->addWidget(lamp_z_input, 11, 0);
    grid->addWidget(display_carcass, 12, 0);
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
    connect(plusScale, SIGNAL(pressed()),
            this, SIGNAL(plus_scale()));
    connect(minusScale, SIGNAL(pressed()),
            this, SIGNAL(minus_scale()));
    connect(apply, SIGNAL(pressed()),
            this, SIGNAL(push_apply()));
    connect(display_carcass, SIGNAL(clicked(bool)),
            this, SIGNAL(clicked_display_carcass(bool)));
}

void Panel::set_cnt_polygons(int cnt) {
    cntPolygons->setNum(cnt);
}

void Panel::set_lamp_position(const QVector3D &v) {
    lamp_x_input->setText(QString::number(static_cast<int>(v.x())));
    lamp_y_input->setText(QString::number(static_cast<int>(v.y())));
    lamp_z_input->setText(QString::number(static_cast<int>(v.z())));
}

QVector3D Panel::get_lamp_position() {
    return QVector3D{
        lamp_x_input->text().toFloat(),
        lamp_y_input->text().toFloat(),
        lamp_z_input->text().toFloat()
    };
}

void Panel::set_lamp_power(int p) {
    lamp_power_input->setText(QString::number(p));
}

int Panel::get_lamp_power() {
    return lamp_power_input->text().toInt();
}
