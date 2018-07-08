#ifndef READFILE_H
#define READFILE_H
#include <QString>
#include <QtWidgets>

class MyReadFile : public QObject
{
    Q_OBJECT
public:
    MyReadFile(const QString &file_name, QTextEdit *edit):
        file_name(file_name), t_edit(edit)
    {}

public slots:

    void read();

private:
    QString file_name;
    QTextEdit *t_edit;
};

#endif // READFILE_H
