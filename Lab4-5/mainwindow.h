#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view.h"
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    View *vw;
    Panel *pan;
    float pr_val[9];

public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:
    void turn_left();
    void turn_right();
    void turn_up();
    void turn_down();
    void change_appr(int sliderValue);
    void plus_scale();
    void minus_scale();
    void change_pos_lamp();
    void display_carcass(bool);
    void change_pos_fig_x(int);
    void change_pos_fig_y(int);
    void change_pos_fig_z(int);
};

#endif // MAINWINDOW_H
