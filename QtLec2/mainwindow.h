#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>

#include "pacman.h"

//это за нас создал Disigner
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;

    QVBoxLayout *body;

    QGraphicsView *graphicsView;

    QGraphicsScene *scene;     // Объявляем графическую сцену
    Pacman *pacman;  // пакман

    QPushButton *start_button; //кнопка начала игры

public slots:
    void start_handler();
    void keyPressEvent(QKeyEvent *ke);
};

#endif // MAINWINDOW_H
