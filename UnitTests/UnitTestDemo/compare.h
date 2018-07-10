#ifndef COMPARE_H
#define COMPARE_H

#include <QObject>
#include <QStringList>

class Compare : public QObject
{
    Q_OBJECT
public:
    explicit Compare(QObject *parent = 0);

    public slots:
        int max(int a, int b);
        int min(int a, int b);
};

#endif // COMPARE_H
