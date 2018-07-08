#ifndef THREAD_VECTOR_H
#define THREAD_VECTOR_H
#include <mutex>
#include <vector>

template <typename T>
class TVector
{

public:

     void add(T element)
     {
          std::lock_guard<std::recursive_mutex> locker(_lock);
          _elements.push_back(element);
     }

     void add(const std::vector<T> &vect)
     {
         for(auto item:vect)
         {
             std::lock_guard<std::recursive_mutex> locker(_lock);
             add(item);
         }
     }

     void print()
     {
         std::lock_guard<std::recursive_mutex> locker(_lock);
          for(auto e: _elements)
             std::cout << e << std::endl;
     }

private:

     std::recursive_mutex  _lock; //мьютекс для защиты данных
     std::vector<T> _elements;
};


#endif // THREAD_VECTOR_H
