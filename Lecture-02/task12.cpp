#include <iostream>
using namespace std;
// unary operator (a++,++a,a--,--a)
int main()
{
    int a = 20;
    int b = a++;       // fist task done then update value
    cout << b << endl; // 20
    cout << a << endl; // 21 (update value and increment 1)
    return 0;
}