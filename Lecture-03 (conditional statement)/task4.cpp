#include <iostream>
using namespace std;
// conditional statement
int main()
{
    int grade;
    cout << "enter your marks\n";
    cin >> grade;
    if (grade >= 90)
    {
        cout << "A+\n";
    }
    else if (grade >= 80 && grade < 90)
    {
        cout << "A\n";
    }
    else
    {
        cout << "A-\n";
    }
    return 0;
};