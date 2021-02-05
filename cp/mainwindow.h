#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "bezie.h"
#include <QMainWindow>
#include "view.h"
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void turn_left();
    void turn_right();
    void turn_up();
    void turn_down();
    void change_appr(int);
//    void change_appr(int);
//    void turn_left();
//    void turn_right();
//    void turn_up();
//    void turn_down();
private:
    Panel *pan;
    view *vw;
};
#endif // MAINWINDOW_H
