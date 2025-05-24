#include <iostream>
using namespace std;

const int SIZE = 5;
int queue[SIZE], front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == SIZE - 1)
        cout << "Queue Overflow\n";
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else
        front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(12);
    enqueue(25);
    enqueue(30);
    dequeue();
    enqueue(14);
    display();
    return 0;
}
