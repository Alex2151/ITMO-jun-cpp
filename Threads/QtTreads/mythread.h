#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QString>
#include <QtWidgets>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(const QString &file_name, QTextEdit *edit):
        file_name(file_name),
        t_edit(edit)
    {}
    void run();
private:
    QString file_name;
    QTextEdit *t_edit;
};

#endif // MYTHREAD_H
