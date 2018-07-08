#include <iostream>
#include <thread>
#include <string>

using namespace std;

void threadFunctionArgs(int x, double &y, std::string &name)
{


    cout << "x = " << x << "y = " << y
         << "name -" << name << endl;

    y++;
}

int main()
{
    double value = 13.54;
    string s_value = "tmp";

    /* Передача аргументов в функцию.
     * По умолчанию все аргументы передаются по значения
     * чтобы передать по ссылке необходимо использовать
     * std::ref
     * Передать можно любое количество аргументов
     * Нельзя получить то что вернет функция по завершению
     */
    thread thr(threadFunctionArgs, 5, ref(value), ref(s_value));
    thr.join();

    cout << "value " << value << endl;
    return 0;
}
