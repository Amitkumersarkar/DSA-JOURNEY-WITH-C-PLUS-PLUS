#include <iostream>
using namespace std;

const int SIZE = 5;
int stack[SIZE], top = -1;

void push(int val)
{
    if (top < SIZE - 1)
        stack[++top] = val;
    else
        cout << "Stack Overflow\n";
}

void pop()
{
    if (top >= 0)
        top--;
}

void display()
{
    for (int i = 0; i <= top; i++)
        cout << stack[i] << " ";
    cout << endl;
}

int main()
{
    push(4);
    push(7);
    push(9);
    push(12);
    push(21);
    push(30);
    cout << "Stack before pop: ";
    display();
    pop();
    pop();
    cout << "Stack after pop: ";
    display();
    return 0;
}
