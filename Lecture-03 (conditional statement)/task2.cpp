#include <iostream>
using namespace std;
// conditional statement
int main()
{
    int age;
    cout << "Enter your age = " << endl;
    cin >> age;
    if (age >= 18)
    {
        cout << "Yes you can vote  " << endl;
    }
    else
    {
        cout << "sorry you cannot vote !! " << endl;
    }
    return 0;
};