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
    bezie fig;
    explicit view(QWidget *parent = nullptr);
    QPointF Point;
    bool flag;
//    QPointF mPoint2;
//    QPointF mPoint3;
//    QPointF mPoint4;
    bool flag1;
    bool flag2;
    bool flag3;
    bool flag4;

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // VIEW_H
