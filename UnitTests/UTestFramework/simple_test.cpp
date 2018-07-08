#include <iostream>
#include <assert.h>

using namespace std;
int division(int x, int y)
{
    if (y == 0)
        return -1;
    return x / y;
}

void testDivision()
{
    assert(division(3, 2) == 1);
    assert(division(0, 6) == 0);

    assert(division(5, 0) == 0);

    cout << "Tests Finished Ok";
}

int main()
{
    testDivision();
    return 0;
}
