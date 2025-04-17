#include <iostream>
using namespace std;
// conditional statement
// find the character lowercase or uppercase
int main()
{
    char ch;
    cout << "enter a letter\n";
    cin >> ch;
    if (ch >= 'a' && ch <= 'z')
    {
        cout << "lowercase letter\n";
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        cout << "uppercase letter\n";
    }
    else
    {
        cout << "try again\n";
    }
    return 0;
};