#include "compare.h"

Compare::Compare(QObject *parent) :
    QObject(parent)
{}

int Compare::max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int Compare::min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}
