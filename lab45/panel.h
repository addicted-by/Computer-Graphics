#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QVector3D>
#include <QCheckBox>

class Panel : public QWidget
{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = nullptr);
    void set_cnt_polygons(size_t cnt);
    float get_lamp_pos_x();
    float get_lamp_pos_y();
    float get_lamp_pos_z();
    void set_lamp_pos_x(float x);
    void set_lamp_pos_y(float y);
    void set_lamp_pos_z(float z);
//    void set_lamp_power(int p);
//    int get_lamp_power();
private:
    QPushButton *left;
    QPushButton *right;
    QPushButton *up;
    QPushButton *down;
    QSlider *approximation;
    QLabel *cntPolygons;
    QPushButton *plusScale;
    QPushButton *minusScale;
    QLabel *lamp_x;
    QLineEdit *lamp_x_input;
    QLabel *lamp_y;
    QLineEdit *lamp_y_input;
    QLabel *lamp_z;
    QLineEdit *lamp_z_input;
    QLabel *lamp_power;
    QLineEdit *lamp_power_input;
    QPushButton *apply;
    QCheckBox *display_carcass;
    QSlider *pos_fig_x;
    QSlider *pos_fig_y;
    QSlider *pos_fig_z;
signals:
    void push_left();
    void push_right();
    void push_up();
    void push_down();
    void approximation_changed(int);
    void plus_scale();
    void minus_scale();
    void push_apply();
    void clicked_display_carcass(bool);
    void pos_fig_x_changed(int);
    void pos_fig_y_changed(int);
    void pos_fig_z_changed(int);
public slots:
};

#endif // PANEL_H
