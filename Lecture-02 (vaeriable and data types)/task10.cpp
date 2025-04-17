#include <iostream>
using namespace std;
// logical operator such as OR,AND,NOT(||,&&,!)
int main()
{

    cout << !(5 > 2) << endl;
    cout << ((5 > 2) || (5 < 2)) << endl;
    cout << ((5 == 2) && (5 != 2)) << endl;
    return 0;
}