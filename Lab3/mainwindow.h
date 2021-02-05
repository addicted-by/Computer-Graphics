#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view.h"
#include "panel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Panel *pan;
    view *vw;
private slots:
    void turn_left();
    void turn_right();
    void turn_up();
    void turn_down();
    void change_appr(int);
    void plus_scale();
    void minus_scale();
    void change_lamp();
    void display_carcass(bool);
};

#endif // MAINWINDOW_H
