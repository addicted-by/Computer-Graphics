#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QPointF>
#include "sphere.h"

class view : public QWidget
{
    Q_OBJECT
public:
    int center_x;
    int center_y;
    double step;
    sphere fig;
    QPointF previousPoint;
    bool first;

    explicit view(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
signals:

public slots:
};

#endif // VIEW_H
