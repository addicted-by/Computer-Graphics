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
private:
    QPushButton *left;
    QPushButton *right;
    QPushButton *up;
    QPushButton *down;
    QSlider *approximation;
    //QPushButton *nextPoint;
    //QPushButton *apply;
signals:
    void push_left();
    void push_right();
    void push_up();
    void push_down();
    void approximation_changed(int);
    //void nextpoint();
    //void push_apply();
public slots:
};

#endif // PANEL_H
