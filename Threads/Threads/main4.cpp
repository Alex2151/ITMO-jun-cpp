#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>

using namespace std;
mutex g_lock;

void threadFunctionArgs(vector<int> &vc, int min, int max)
{
    for(int i = min; i < max; i++) {
        cout << i << endl;
        g_lock.lock();
        vc.push_back(i);
        g_lock.unlock();
    }
}

int main()
{

    vector<int> test_thr;
    thread thr(threadFunctionArgs, ref(test_thr), 0, 10000);
    thread thr1(threadFunctionArgs, ref(test_thr), 10, 20000);
    thread thr2(threadFunctionArgs, ref(test_thr), 20, 30000);

    thr.join();
    thr1.join();
    thr2.join();

    for(auto item:test_thr)
    {
        cout << "value " << item << endl;
    }

    return 0;
}
