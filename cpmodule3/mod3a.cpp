#include <iostream>
using namespace std;

int main ()
{
    int result;

    result = 6-3*2+7-1+17%2;
    cout << "\nResult 1: " << result;

    result = (6-3)*2+(7-1)+17%2;
    cout << "\nResult 2: " << result;

    return 0;
}