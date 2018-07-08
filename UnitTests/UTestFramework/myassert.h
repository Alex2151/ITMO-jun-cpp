#ifndef MYASSERT_H
#define MYASSERT_H
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <map>

template <typename T>
std::ostream& operator << (std::ostream &os, const std::set<T>& s)
{
    os << "{";
    bool first = true;
    for (const auto & item: s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << item;
    }

    return os << "}";
}


template <typename K, typename V>
std::ostream& operator << (std::ostream &os, const std::map<K, V>& m)
{
    os << "{";
    bool first = true;
    for (const auto & item: m)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << item.first << ": " << item.second;
    }

    return os << "}";
}

template <typename T, typename U>
void AssertEqual(const T &t, const U &u, const std::string &hint)
{
    if (t != u)
    {
        std::ostringstream os;
        os << "Assertion faild: " << t << "!=" << u << std::endl <<
              "Hint " << hint;
        throw std::runtime_error(os.str());
    }
}

void Assert(bool b, const std::string &hint)
{
    AssertEqual(b, true, hint);
}


//template <typename TF>
//void runTest(TF func, const std::string &test_name)
//{
//    try
//    {
//        func();
////        std::cout << "Test " << test_name << " Ok" << std::endl;
//        std::cerr << "Test " << test_name << " Ok" << std::endl;
//    }
//    catch (std::runtime_error& e)
//    {
////        std::cout << "Test " << test_name << " fail" << std::endl;
//        std::cerr << "Test " << test_name << " fail" << std::endl;
//    }

//}

class TestRunner
{
public:
    ~TestRunner()
    {
        if (fail_count > 0)
        {
            std::cerr << "tests failed";
            exit(1);
        }
    }

    template <typename TF>
    void runTest(TF func, const std::string &test_name)
    {
        try
        {
            func();
    //        std::cout << "Test " << test_name << " Ok" << std::endl;
            std::cerr << "Test " << test_name << " Ok" << std::endl;
        }
        catch (std::runtime_error& e)
        {
            fail_count++;
    //        std::cout << "Test " << test_name << " fail" << std::endl;
            std::cerr << "Test " << test_name << " fail" << std::endl;
        }

    }
private:
    int fail_count = 0;
};


#endif // MYASSERT_H
