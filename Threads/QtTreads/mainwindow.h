#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTimer>

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
    void readFile();
    void clearOutput();
    void updateTimer();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int timer_count = 0;

//    MyReadFile(const QString file_name);
};

#endif // MAINWINDOW_H
