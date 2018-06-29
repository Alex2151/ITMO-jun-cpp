#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->resize(400, 400);
    this->setFixedSize(400, 400);

    QWidget *base = new QWidget();
    this->setCentralWidget(base);

    body = new QVBoxLayout(base);
    view = new QGraphicsView();
    scene = new QGraphicsScene();

    view->setBackgroundBrush(Qt::black);
    view->setScene(scene);
    body->addWidget(view);

    scene->setSceneRect(0, 0, 200, 200);

    scene->addRect(0, 0, 200, 200, QPen(Qt::white));

    pacman = new Pacman();
    pacman->setEnabled(false);

    scene->addItem(pacman);

    start = new QPushButton("Start");
    connect(start, SIGNAL(clicked()), this, SLOT(startHanler()));

    body->addWidget(start);

    createPoints(20);

    connect(pacman, &Pacman::signalEatPoint, this,
            &MainWindow::pointHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startHanler()
{
    QMessageBox *dialog = new QMessageBox(QMessageBox::Information,
                                          "Dialog", "Sure?",
                                          QMessageBox::Yes | QMessageBox::Cancel);

    if (dialog->exec() == QMessageBox::Yes)
    {
        pacman->setEnabled(true);
        start->setEnabled(false);
        start->setVisible(false);
    }

    else
    {
        this->close();
    }

}

void MainWindow::pointHandler(QGraphicsItem *del_point)
{
    foreach (QGraphicsItem *point, points) {
        if(point == del_point)
        {
            scene->removeItem(point);
            points.removeOne(del_point);
            //? memory leak
            point_count++;
        }

    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        //
        pacman->moving(0, -20, pconsts::direction::UP);
        break;
    case Qt::Key_S:
        //
        pacman->moving(0, 20, pconsts::direction::DOWN);
        break;
    case Qt::Key_A:
        pacman->moving(-20, 0, pconsts::direction::LEFT);
        break;

    case Qt::Key_D:
        pacman->moving(20, 0, pconsts::direction::RIGHT);
        break;
    default:

        break;
    }

}

void MainWindow::createPoints(int amount)
{

//    QPoint base_p;
//    base_p.setX(30);
//    base_p.setY(10);
    QRandomGenerator *gen = new QRandomGenerator();

    int row = 0, col = 0;

    for(int i = 0; i < 100; i++)
    {

        if (row > 9)
        {
            row = 0;
            col++;
        }

        Point *np = new Point();
        np->setPos(col * 20, row * 20);
        row ++;

        if (gen->generate() & 1)
        {
            continue;
        }

        scene->addItem(np);
        points.push_back(np);
    }

}
