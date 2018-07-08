#include "mythread.h"
#include <QFile>

void MyThread::run()
{
    if(!file_name.isEmpty())
    {

        QFile file(file_name);
        if (file.open(QIODevice::ReadOnly))
        {
           QString temp(file.readAll());
           t_edit->append(temp);
           Sleep(10000);
        }
    }

}
