#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include "thread_vector.h"

using namespace std;

void threadFunction(TVector<int> &c, int count)
{
//    for(int i = 0; i < count; i++){
//        c.add(rand() % 100);
//    }

    vector<int> tmp;

    for(int i = 0; i < count; i++){
        tmp.push_back(rand() % 100);
    }
    c.add(tmp);

}


int main()
{
     srand((unsigned int)time(0));
     TVector<int> t_vec;
     std::thread t1(threadFunction, std::ref(t_vec), 5);
     std::thread t2(threadFunction, std::ref(t_vec), 7);
     std::thread t3(threadFunction, std::ref(t_vec), 2);
     t1.join();
     t2.join();
     t3.join();
     t_vec.print();
     return 0;
}
