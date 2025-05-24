#include <iostream>
using namespace std;

const int SIZE = 5;
int queue[SIZE], front = -1, rear = -1;

void enqueue(int val)
{
    if ((rear + 1) % SIZE == front)
        cout << "Queue Overflow\n";
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }
}

void dequeue()
{
    if (front == -1)
        cout << "Queue Underflow\n";
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }
    int i = front;
    while (true)
    {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
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
