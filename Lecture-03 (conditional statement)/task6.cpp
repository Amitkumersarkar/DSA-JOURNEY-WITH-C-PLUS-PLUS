#include <iostream>
using namespace std;
// conditional statement
// Find The ASCII Value
// ASCII = American standard code for information interchange
int main()
{
    char ch;
    cout << "Enter your charater\n";
    cin >> ch;
    if (ch >= 65 && ch <= 96)
    {
        cout << "Uppercase letter\n";
    }
    else if (ch >= 97 && ch <= 129)
    {
        cout << "Lowercase letter\n";
    }
    else
    {
        cout << "Not a number\n";
    }
    return 0;
};