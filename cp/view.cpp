#include "view.h"
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QResizeEvent>

view::view(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(0, 0, 0));
    setPalette(pal);

    setAutoFillBackground(true);
    //fig(mPoint1, mPoint2, mPoint3, mPoint4);
    this->resize(800,800);

    //bezie.create();
    time = 0;

    flag1 = false;
    flag2 = false;
    flag3 = false;
    flag4 = false;
    z1_1 = 100;
    z1_2 = 110;
    z1_3 = 50;
    z1_4 = 12;
    z2_1 = 100;
    z2_2 = 110;
    z2_3 = 50;
    z2_4 = 12;
    mPoint1_1 = QPointF(-60/* - center_x*/,-137/2/* - center_y*/);
    mPoint2_1 = QPointF(-166/* - center_x*/,-159/2/* - center_y*/);
    mPoint3_1 = QPointF(118/* - center_x*/,-12/* - center_y*/);
    mPoint4_1 = QPointF(112/* - center_x*/,115/* - center_y*/);
    mPoint1_2 = QPointF(32/* - center_x*/, 123/* - center_y*/);
    mPoint2_2 = QPointF(330/* - center_x*/, 75/* - center_y*/);
    mPoint3_2 = QPointF(120/* - center_x*/, 18/* - center_y*/);
    mPoint4_2 = QPointF(50/* - center_x*/, 120/* - center_y*/);
//    mPoint1_1 = QPointF(center_x,center_y);
//    mPoint2_1 = QPointF(-600 + center_x,-25 + center_y);
//    mPoint3_1 = QPointF(660 + center_x,-200 + center_y);
//    mPoint4_1 = QPointF(180 + center_x,10 + center_y);
//    mPoint1_2 = QPointF(86 + center_x, 95 + center_y);
//   mPoint2_2 = QPointF(320 + center_x, -120 + center_y);
//    mPoint3_2 = QPointF(30 + center_x, -400 + center_y);
//    mPoint4_2 = QPointF(100 + center_x, 180 + center_y);
    flag = false;
    s1 = 0.01;

    //fig1 = bezie(mPoint1_1, mPoint2_1, mPoint3_1, mPoint4_1, s1, this->width(), this->height());
    //fig2 = bezie(mPoint1_2, mPoint2_2, mPoint3_2, mPoint4_2, s1, this->width(), this->height());

//    mPoint3 = QPointF();
//    mPoint4 = QPointF();

}

void view::paintEvent(QPaintEvent *)
{
    QPainter ptr{this};
    center_x = this->width() ;
    center_y = this->height() ;
    //QPainter ptr1{this};
    dot1_1_x = mPoint1_1.x() + center_x / 2;
    dot1_1_y = mPoint1_1.y() + center_y / 2;
    dot2_1_x = mPoint2_1.x() + center_x / 2;
    dot2_1_y = mPoint2_1.y() + center_y / 2;
    dot3_1_x = mPoint3_1.x() + center_x / 2;
    dot3_1_y = mPoint3_1.y() + center_y / 2;
    dot4_1_x = mPoint4_1.x() + center_x / 2;
    dot4_1_y = mPoint4_1.y() + center_y / 2;

    dot1_2_x = mPoint1_2.x() + center_x / 2;
    dot1_2_y = mPoint1_2.y() + center_y / 2;
    dot2_2_x = mPoint2_2.x() + center_x / 2;
    dot2_2_y = mPoint2_2.y() + center_y / 2;
    dot3_2_x = mPoint3_2.x() + center_x / 2;
    dot3_2_y = mPoint3_2.y() + center_y / 2;
    dot4_2_x = mPoint4_2.x() + center_x / 2;
    dot4_2_y = mPoint4_2.y() + center_y / 2;

    ptr.setPen(QColor(0,0,255,255));
    ptr.drawLine(this->width()-60, this->height() - 50, this->width() -30, this->height() - 50);
    ptr.setPen(QColor(255,0,0,255));
    ptr.drawLine(this->width()-60, this->height() - 50, this->width()-60, this->height() - 80);
    ptr.setPen(QColor(0,255,0,255));
    ptr.drawLine(this->width()-60, this->height() - 50, this->width()-75, this->height() - 40);
    //ptr.setPen(QColor(0,0,255,255));
    ptr.drawEllipse(static_cast<int>(dot1_1_x),static_cast<int>(dot1_1_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot4_1_x), static_cast<int>(dot4_1_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot2_1_x), static_cast<int>(dot2_1_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot3_1_x), static_cast<int>(dot3_1_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot1_2_x),static_cast<int>(dot1_2_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot4_2_x), static_cast<int>(dot4_2_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot2_2_x), static_cast<int>(dot2_2_y), 15, 15);
    ptr.drawEllipse(static_cast<int>(dot3_2_x), static_cast<int>(dot3_2_y), 15, 15);
    ptr.setPen(QColor(255, 255, 255, 255));
    //    if (!flag){
//        if (flag1) {
//            ptr.drawRect(static_cast<int>(mPoint1.x()),static_cast<int>(mPoint1.y()), 10, 10);
//        }
//        if (flag2) {
//            ptr.drawRect(static_cast<int>(mPoint2.x()), static_cast<int>(mPoint2.y()), 10, 10);
//        }
//        if (flag3) {
//            ptr.drawRect(static_cast<int>(mPoint3.x()), static_cast<int>(mPoint3.y()), 10, 10);
//        }
//        if (flag4) {
//            ptr.drawRect(static_cast<int>(mPoint4.x()), static_cast<int>(mPoint4.y()), 10, 10);
//        }
//    }
//    else {
//        ptr.drawRect(static_cast<int>(mPoint1.x()),static_cast<int>(mPoint1.y()), 10, 10);
//        ptr.drawRect(static_cast<int>(mPoint4.x()), static_cast<int>(mPoint4.y()), 10, 10);
//        ptr.drawRect(static_cast<int>(mPoint2.x()), static_cast<int>(mPoint2.y()), 10, 10);
//        ptr.drawRect(static_cast<int>(mPoint3.x()), static_cast<int>(mPoint3.y()), 10, 10);
//        ptr.drawLine(static_cast<int>(mPoint1.x()), static_cast<int>(mPoint1.y()),
//                     static_cast<int>(mPoint2.x()), static_cast<int>(mPoint2.y()));
//       // ptr.drawLine(static_cast<int>(mPoint2.x()), static_cast<int>(mPoint2.y()),
         //            static_cast<int>(mPoint3.x()), static_cast<int>(mPoint3.y()));
        //ptr.drawLine(static_cast<int>(mPoint3.x()), static_cast<int>(mPoint3.y()),
          //           static_cast<int>(mPoint4.x()), static_cast<int>(mPoint4.y()));
        //update();


    fig1 = bezie(mPoint1_1, mPoint2_1, mPoint3_1, mPoint4_1, s1, this->width() , this->height() , z1_1, z1_2, z1_3, z1_4);
    fig2 = bezie(mPoint1_2, mPoint2_2, mPoint3_2, mPoint4_2, s1, this->width() , this->height() , z2_1, z2_2, z2_3, z2_4);
        fig2.draw(&ptr);
        fig1.draw(&ptr);
        ptr.setPen(QColor(255,255,255,255));

        for (int i = 0; i<static_cast<int>(fig1.points_x.size()); i++)
            ptr.drawLine(static_cast<int>(fig1.points_x[i] + center_x / 2), static_cast<int>(fig1.points_y[i] + center_y / 2),
                         static_cast<int>(fig2.points_x[i] + center_x / 2),
                         static_cast<int>(fig2.points_y[i] + center_y / 2));
        //fig1.draw();

}

void view::resizeEvent(QResizeEvent *e)
{
    if (e->oldSize().width() == -1 || e->oldSize().height() == -1) {
        return;
    }
    double coef_x = width() / static_cast<double>(e->oldSize().width());
    double coef_y = height() / static_cast<double>(e->oldSize().height());

//    double coef_z = sqrt(std::pow(width(), 2) + std::pow(height(), 2)) /
//            sqrt(std::pow(static_cast<double>(e->oldSize().width()), 2) + std::pow(static_cast<double>(e->oldSize().height()), 2));

    mPoint1_1.rx() *= coef_x;
    mPoint1_1.ry() *= coef_y;
    mPoint2_1.rx() *= coef_x;
    mPoint2_1.ry() *= coef_y;
    mPoint3_1.rx() *= coef_x;
    mPoint3_1.ry() *= coef_y;
    mPoint4_1.rx() *= coef_x;
    mPoint4_1.ry() *= coef_y;

    mPoint1_2.rx() *= coef_x;
    mPoint1_2.ry() *= coef_y;
    mPoint2_2.rx() *= coef_x;
    mPoint2_2.ry() *= coef_y;
    mPoint3_2.rx() *= coef_x;
    mPoint3_2.ry() *= coef_y;
    mPoint4_2.rx() *= coef_x;
    mPoint4_2.ry() *= coef_y;
    update();
}
void view::mouseMoveEvent(QMouseEvent *e)
{

//    if (e->pos().x() <= mPoint2_1.x() + 15 && e->pos().x()+center_x / 2 >= mPoint2_1.x() - 15 &&
//            e->pos().y() +center_y / 2<= mPoint2_1.y() + 15 && e->pos().y() +center_y / 2>= mPoint2_1.y() - 15) {
//        QPointF newPoint = e->pos();
//        double deltaX = newPoint.x() - mPoint2_1.x();
//        double deltaY = newPoint.y() - mPoint2_1.y();
//        mPoint2_1.rx() += deltaX;
//        mPoint2_1.ry() += deltaY;
//        update();
//        return;
//    }

//    if (e->pos().x()+center_x / 2 <= mPoint3_1.x() + 15 && e->pos().x()+center_x / 2 >= mPoint3_1.x() - 15 &&
//            e->pos().y() +center_y / 2<= mPoint3_1.y() + 15 && e->pos().y() +center_y / 2>= mPoint3_1.y() - 15) {
//        QPointF newPoint = e->pos();
//        double deltaX = newPoint.x() - mPoint3_1.x();
//        double deltaY = newPoint.y() - mPoint3_1.y();
//        mPoint3_1.rx() += deltaX;
//        mPoint3_1.ry() += deltaY;
//        update();
//        return;
//    }
    if (e->pos().x() <= dot1_1_x + 15 && e->pos().x() >= dot1_1_x - 15 &&
            e->pos().y()<= dot1_1_y + 15 && e->pos().y() >= dot1_1_y - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - dot1_1_x;
        double deltaY = newPoint.y() - dot1_1_y;
        mPoint1_1.rx() += deltaX;
        mPoint1_1.ry() += deltaY;
        dot1_1_x+= deltaX;
        dot1_1_y+= deltaY;
        update();
        return;
    }
    if (e->pos().x() <= dot2_1_x + 15 && e->pos().x() >= dot2_1_x - 15 &&
            e->pos().y()<= dot2_1_y + 15 && e->pos().y() >= dot2_1_y - 15) {
           QPointF newPoint = e->pos();
            double deltaX = newPoint.x() - dot2_1_x;
            double deltaY = newPoint.y() - dot2_1_y;
            mPoint2_1.rx() += deltaX;
            mPoint2_1.ry() += deltaY;
            dot2_1_x+= deltaX;
            dot2_1_y+= deltaY;
            update();
            return;
    }
    if (e->pos().x() <= dot3_1_x + 15 && e->pos().x() >= dot3_1_x - 15 &&
            e->pos().y()<= dot3_1_y + 15 && e->pos().y() >= dot3_1_y - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - dot3_1_x;
        double deltaY = newPoint.y() - dot3_1_y;
        mPoint3_1.rx() += deltaX;
        mPoint3_1.ry() += deltaY;
        dot3_1_x+= deltaX;
        dot3_1_y+= deltaY;
        update();
        return;
    }
    if (e->pos().x() <= dot4_1_x + 15 && e->pos().x() >= dot4_1_x - 15 &&
            e->pos().y()<= dot4_1_y + 15 && e->pos().y() >= dot4_1_y - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - dot4_1_x;
        double deltaY = newPoint.y() - dot4_1_y;
        mPoint4_1.rx() += deltaX;
        mPoint4_1.ry() += deltaY;
        dot4_1_x+= deltaX;
        dot4_1_y+= deltaY;
        update();
        return;
    }
    /*

    if (e->pos().x()+center_x / 2 <= mPoint4_1.x() + 15 && e->pos().x() +center_x / 2>= mPoint4_1.x() - 15 &&
            e->pos().y() +center_y / 2<= mPoint4_1.y() + 15 && e->pos().y() +center_y / 2>= mPoint4_1.y() - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - mPoint4_1.x();
        double deltaY = newPoint.y() - mPoint4_1.y();
        mPoint4_1.rx() += deltaX;
        mPoint4_1.ry() += deltaY;
        update();
        return;
    }*/
    if (e->pos().x() <= dot1_2_x + 15 && e->pos().x() >= dot1_2_x - 15 &&
            e->pos().y()<= dot1_2_y + 15 && e->pos().y() >= dot1_2_y - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - dot1_2_x;
        double deltaY = newPoint.y() - dot1_2_y;
        mPoint1_2.rx() += deltaX;
        mPoint1_2.ry() += deltaY;
        dot1_2_x+= deltaX;
        dot1_2_y+= deltaY;
        update();
        return;
    }
    if (e->pos().x() <= dot2_2_x + 15 && e->pos().x() >= dot2_2_x - 15 &&
            e->pos().y()<= dot2_2_y + 15 && e->pos().y() >= dot2_2_y - 15) {
           QPointF newPoint = e->pos();
            double deltaX = newPoint.x() - dot2_2_x;
            double deltaY = newPoint.y() - dot2_2_y;
            mPoint2_2.rx() += deltaX;
            mPoint2_2.ry() += deltaY;
            dot2_2_x+= deltaX;
            dot2_2_y+= deltaY;
            update();
            return;
    }
    if (e->pos().x() <= dot3_2_x + 15 && e->pos().x() >= dot3_2_x - 15 &&
            e->pos().y()<= dot3_2_y + 15 && e->pos().y() >= dot3_2_y - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - dot3_2_x;
        double deltaY = newPoint.y() - dot3_2_y;
        mPoint3_2.rx() += deltaX;
        mPoint3_2.ry() += deltaY;
        dot3_2_x+= deltaX;
        dot3_2_y+= deltaY;
        update();
        return;
    }
    if (e->pos().x() <= dot4_2_x + 15 && e->pos().x() >= dot4_2_x - 15 &&
            e->pos().y()<= dot4_2_y + 15 && e->pos().y() >= dot4_2_y - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - dot4_2_x;
        double deltaY = newPoint.y() - dot4_2_y;
        mPoint4_2.rx() += deltaX;
        mPoint4_2.ry() += deltaY;
        dot4_2_x+= deltaX;
        dot4_2_y+= deltaY;
        update();
        return;
    }/*
    if (e->pos().x() +center_x / 2<= mPoint1_2.x() + 15 && e->pos().x()+center_x / 2 >= mPoint1_2.x() - 15 &&
            e->pos().y() +center_y / 2 <= mPoint1_2.y() + 15 && e->pos().y()+center_y / 2 >= mPoint1_2.y() - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - mPoint1_2.x();
        double deltaY = newPoint.y() - mPoint1_2.y();
        mPoint1_2.rx() += deltaX;
        mPoint1_2.ry() += deltaY;
        update();
        return;
    }

    if (e->pos().x() +center_x / 2<= mPoint2_2.x() + 15 && e->pos().x() +center_x / 2>= mPoint2_2.x() - 15 &&
            e->pos().y() +center_y / 2<= mPoint2_2.y() + 15 && e->pos().y() +center_y / 2>= mPoint2_2.y() - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - mPoint2_2.x();
        double deltaY = newPoint.y() - mPoint2_2.y();
        mPoint2_2.rx() += deltaX;
        mPoint2_2.ry() += deltaY;
        update();
        return;
    }

    if (e->pos().x() +center_x / 2<= mPoint3_2.x() + 15 && e->pos().x() +center_x / 2>= mPoint3_2.x() - 15 &&
            e->pos().y()+center_y / 2 <= mPoint3_2.y() + 15 && e->pos().y() +center_y / 2>= mPoint3_2.y() - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - mPoint3_2.x();
        double deltaY = newPoint.y() - mPoint3_2.y();
        mPoint3_2.rx() += deltaX;
        mPoint3_2.ry() += deltaY;
        update();
        return;
    }

    if (e->pos().x() +center_x / 2<= mPoint4_2.x() + 15 && e->pos().x() +center_x / 2>= mPoint4_2.x() - 15 &&
            e->pos().y() +center_y / 2<= mPoint4_2.y() + 15 && e->pos().y() +center_y / 2>= mPoint4_2.y() - 15) {
        QPointF newPoint = e->pos();
        double deltaX = newPoint.x() - mPoint4_2.x();
        double deltaY = newPoint.y() - mPoint4_2.y();
        mPoint4_2.rx() += deltaX;
        mPoint4_2.ry() += deltaY;
        update();
        return;
    }*/
}
