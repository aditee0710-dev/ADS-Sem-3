#include <bits/stdc++.h>
using namespace std;
#define SIZE 5
class CircularQueue
{
    int queue[SIZE];
    int front, rear;
public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int value)
    {
        if ((rear + 1) % SIZE == front)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        cout << value << " inserted" << endl;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Circular Queue: ";
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
};
int main()
{
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.enqueue(60);
    return 0;
}