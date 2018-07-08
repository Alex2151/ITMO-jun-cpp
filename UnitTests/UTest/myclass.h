#ifndef MYCLASS_H
#define MYCLASS_H


class MyClass
{
public:
    MyClass();

    int min(int x, int y)
    {
        return x < y ? x :y;
    }

    int max(int x, int y)
    {
        return x > y ? x : y;
    }
};

#endif // MYCLASS_H
