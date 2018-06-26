#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(800,800);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(800,800);    // Фиксируем размеры виджета


    QWidget *base = new QWidget();

    body = new QVBoxLayout(base);

    this->setCentralWidget(base);

    start_button = new QPushButton("START");
    connect(start_button, SIGNAL(clicked()), this, SLOT(start_handler()));

    graphicsView = new QGraphicsView();
    graphicsView->setDisabled(true);


    body->addWidget(graphicsView);
    body->addWidget(start_button);


    scene = new QGraphicsScene();   // инициализация графической сцены
    graphicsView->setScene(scene);  // установка графической сцены в graphicsView
    graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали


    pacman = new Pacman();      // Инициализируем пакмана будущего
    pacman->setEnabled(false);

    scene->setSceneRect(-250,-250,500,500); // Устанавливаем область графической сцены

    scene->addLine(-250,0,250,0,QPen(Qt::black));   // Добавляем горизонтальную линию через центр
    scene->addLine(0,-250,0,250,QPen(Qt::black));   // Добавляем вертикальную линию через центр

    /* Дополнительно нарисуем органичение территории в графической сцене */
    scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    scene->addItem(pacman);   // Добавляем на сцену квадрат
    pacman->setPos(0,0);      // Устанавливаем квадрат в центр сцены
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_handler()
{

    //создаем диалоговое  окно и просим подтвердить
    QMessageBox* confirm_start = new QMessageBox(QMessageBox::Information, "Test dialog",
                                             "Are you sure?",
                                             QMessageBox::Yes | QMessageBox::Cancel);
//                                        | QDialogButtonBox::Cancel);

    //если пользователь нажал Yes скрываем кнопку и продолжаем
    if (confirm_start->exec() == QMessageBox::Yes)
    {

        pacman->setEnabled(true);
        start_button->setDisabled(true);
        start_button->setHidden(true);
        return;
    }

    //если пользователь отказался, завершаем программу
    else
    {
        exit(0);
    }

}


void MainWindow::keyPressEvent(QKeyEvent *ke)
{

    switch(ke->key())
    {
    case Qt::Key_W:
        pacman->moving(0, -5);
        break;

    case Qt::Key_S:
        pacman->moving(0, 5);
        break;

    case Qt::Key_A:
        pacman->moving(-5, 0);
        break;

    case Qt::Key_D:
        pacman->moving(5, 0);
        break;

    }
}
