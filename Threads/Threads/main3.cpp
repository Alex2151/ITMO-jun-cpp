#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <exception>

using namespace std;

/**
 * @brief The MyException class
 * класс описывающий исключение,
 * в случае исключения может вывести текст ошибки вызовом функции what()
 * Текст ошибки передается в указатель
 */
class MyException : public  std::exception{
public:
    MyException(const string &name)
        :ex_name(name){}

    MyException(const MyException &e):
        ex_name(e.ex_name)
    {}

    virtual const char* what() const throw()
    {
        return ex_name.c_str();
    }

private:
    string ex_name;
};



/**
 * Функция, которая выбрасывает исключение в случае если x равен нулю
 */
void threadFunctionWithExeption(int x, const std::string &name)
{
    if(x == 0)
    {
        throw MyException("null happend");
    }

    cout << name << endl;
}


std::vector<const MyException*>  my_exceptions;

void threadWrapper(int x, const std::string &name)
{
    try
    {
        threadFunctionWithExeption(x, name);
    }

    catch (const MyException &ex)
    {
         my_exceptions.push_back(&ex);
    }
}

int main()
{
//    try
//    {

//        threadFunctionWithExeption(0, "heeey");
//    }
//    catch (const MyException &ex)
//    {
//         std::cout << ex.what() << std::endl;
//    }


//    try
//    {
//        string name("1");
//        std::thread thr1(threadFunctionWithExeption, 2, ref(name));
//        name.assign("2");
//        std::thread thr2(threadFunctionWithExeption, 0, ref(name));

//        thr1.join();
//        thr2.join();
//    }

//    catch (const MyException &ex)
//    {
//         std::cout << ex.what() << std::endl;
//    }


    string name("1");
    std::thread thr(threadWrapper, 0, ref(name));
    thr.join();

    for(auto &e: my_exceptions)
    {
        try
        {
            if(e != nullptr)

                std::throw_with_nested(e);
        }
        catch (...)
        {
            cout << "catch any";
        }
    }

    return 0;
}
