#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
#include "pacman.h"
#include "point.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void startHanler();
    void pointHandler(QGraphicsItem *del_point);

private:
    Ui::MainWindow *ui;

    QVBoxLayout *body;
    QGraphicsView *view;
    QGraphicsScene *scene;

    Pacman *pacman;

    void keyPressEvent(QKeyEvent *event);

    QPushButton *start;

    QVector<QGraphicsItem *> points;
    int point_count;

    void createPoints(int amount);
};

#endif // MAINWINDOW_H
