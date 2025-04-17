#include <iostream>
using namespace std;
// unary operator (a++,++a,a--,--a)
// pre decrement operator = (a--)
// pre decrement operator = (--a)
int main()
{
    int a = 20;
    int b = a--;       // fist  task done update value then
    cout << b << endl; // 21 (update value and decrement 1)
    cout << a << endl; // 21 (update value and decrement 1)
    return 0;
}