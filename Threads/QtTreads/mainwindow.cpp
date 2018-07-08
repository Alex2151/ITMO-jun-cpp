#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include "readfile.h"
#include <qtconcurrentrun.h>
#include <QThread>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);

    connect(ui->read_button, SIGNAL(clicked(bool)), this, SLOT(readFile()));
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    timer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

static void MyReadFile(const QString file_name, QTextEdit *text_edit)
{
    if(!file_name.isEmpty())
    {

        QFile file(file_name);
        if (file.open(QIODevice::ReadOnly))
        {
           QString temp(file.readAll());
           text_edit ->append(temp);
           Sleep(10000);
        }
    }
}


void MainWindow::readFile()
{

    QString file_name;
    QString file_filter;

    file_name = QFileDialog::getOpenFileName(0, tr("Open file"),
                                             QDir::currentPath(),
                                             "*.txt ;; *.cpp ;; *.h",
                                             &file_filter
                                             );


    /*
     * Первый вариант.
     * Запускаем чтение файла в том же потоке, делаем паузу на 10 секунд
     * и наблюдаем как программа зависает
     */
//    if(!file_name.isEmpty())
//    {

//        QFile file(file_name);
//        if (file.open(QIODevice::ReadOnly))
//        {
//           QString temp(file.readAll());
//           ui ->textEdit ->append(temp);
//           Sleep(10000);
//        }
//    }

    /*
     * Второй вариант.
     * Создаем класс MyThread, который наследуется от QThread  и переопределяем для него метод run()
     * Программа больше не зависает, так как чтение файла и пауза происходит в другом потоке
     */
//    MyThread *thread= new MyThread(file_name, ui->textEdit);
//    thread->start();

    /*
     * Третий вариант.
     * Создадим класс MyReadFile, который наследуется только от QObject
     * и имеет слот read, выполняющий чтение и вывод файла
     * Создадим QThread *thread и отправим в него выполнения функции read класса MyReadFile
     *
     */

//    QThread *thread= new QThread;
//    MyReadFile *my = new MyReadFile(file_name, ui->textEdit);
//    my->moveToThread(thread);
//    connect(thread, SIGNAL(started()), my, SLOT(read()));
//    thread->start();

    /*
     * Четвертый вариант.
     * Вообще не создаем никаких классов.
     * Выносим чтения файла в отдельную функцию и запускаем ее отдельным потоком
     */

    QFuture<void> future = QtConcurrent::run(MyReadFile, file_name, ui->textEdit);
//    future.waitForFinished();

}


void MainWindow::clearOutput()
{

}

void MainWindow::updateTimer()
{
    ui->lcdNumber->display(timer_count);
    timer_count++;
}

