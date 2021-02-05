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
    void set_cnt_polygons(int cnt);
    void set_lamp_position(const QVector3D &v);
    QVector3D get_lamp_position();
    void set_lamp_power(int p);
    int get_lamp_power();
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
public slots:
};

#endif // PANEL_H
