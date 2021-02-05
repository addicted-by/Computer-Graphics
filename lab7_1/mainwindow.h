#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "bezie.h"
#include <QMainWindow>
#include "view.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
private:
    Ui::MainWindow *ui;
    //Panel *pan;
    view *vw;
};
#endif // MAINWINDOW_H
