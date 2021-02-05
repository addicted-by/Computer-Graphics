#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QDoubleSpinBox>
#include <QMainWindow>
class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow(QMainWindow *parent = 0);
        ~MainWindow();
    private:
        QDoubleSpinBox* X1;
        QDoubleSpinBox* Y1;
        QDoubleSpinBox* K;
        QDoubleSpinBox* X2;
        QDoubleSpinBox* Y2;
        QDoubleSpinBox* X3;
        QDoubleSpinBox* Y3;
        QDoubleSpinBox* X4;
        QDoubleSpinBox* Y4;
    protected:
        void paintEvent(QPaintEvent*);
    private slots:
        void redrawOnValueChange(double);
};
#endif
