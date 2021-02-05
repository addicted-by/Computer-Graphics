#ifndef VIEW_H
#define VIEW_H
#include "bezie.h"
#include <QWidget>

class view : public QWidget
{
    Q_OBJECT
public:
    int center_x;
    int center_y;
    double time;

    explicit view(QWidget *parent = nullptr);
    QPointF mPoint1_1;
    QPointF mPoint2_1;
    QPointF mPoint3_1;
    QPointF mPoint4_1;
    QPointF mPoint1_2;
    QPointF mPoint2_2;
    QPointF mPoint3_2;
    QPointF mPoint4_2;
    double z1_1;
    double z1_2;
    double z1_3;
    double z1_4;
    double z2_1;
    double z2_2;
    double z2_3;
    double z2_4;
    bezie fig1;
    bezie fig2;
    bool flag1;
    bool flag2;
    bool flag3;
    bool flag4;
    bool flag;
    double dot1_1_x;
    double dot1_1_y;
    double dot2_1_x;
    double dot2_1_y;
    double dot3_1_x;
    double dot3_1_y;
    double dot4_1_x;
    double dot4_1_y;

    double dot1_2_x;
    double dot1_2_y;
    double dot2_2_x;
    double dot2_2_y;
    double dot3_2_x;
    double dot3_2_y;
    double dot4_2_x;
    double dot4_2_y;
    double s1;

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);
    //void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // VIEW_H
