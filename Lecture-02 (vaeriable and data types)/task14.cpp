#include <iostream>
using namespace std;
// unary operator (a++,++a,a--,--a)
// post increment operator = (a--)
// pre increment operator = (--a)
int main()
{
    int a = 20;
    int b = --a;       // fist update value then task done
    cout << b << endl; // 21 (update value and decrement 1)
    cout << a << endl; // 21 (update value and decrement 1)
    return 0;
}