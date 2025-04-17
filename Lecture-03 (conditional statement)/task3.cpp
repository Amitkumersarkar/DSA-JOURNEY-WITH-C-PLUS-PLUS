#include <iostream>
using namespace std;
// conditional statement
int main()
{
    int num;
    cout << "enter your number = " << endl;
    cin >> num;
    if (num % 2 == 0)
    {

        cout << "the number is even " << endl;
    }
    else
    {
        cout << "the number is odd" << endl;
    }
    return 0;
};