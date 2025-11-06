#include <iostream>
using namespace std;

class Queue
{
    int size;
    int *a;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        a = new int[size];
        front = rear = 0;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "queue is full" << endl;
        }
        else
        {
            a[rear] = x;
            rear++;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        else
        {
            int ans = a[front];

            front++;
            if (front == rear)
            {
                front = rear = 0;
            }
            return 1;
        }
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            cout << "peek element is : " << a[front] << endl;
        }
    }
};

int main()
{
    int n;
    cout << "enter size of the queue : ";
    cin >> n;
    int choice;
    Queue q1(n);
    int x = 1;
    while (x == 1)
    {
        cout << "queue created! " << endl;
        cout << "enter your choice " << endl;
        cout << "1.ENQUEUE " << endl;
        cout << "2.DEQUEUE" << endl;
        cout << "3.PEEK" << endl;
        cout << "4.DISPLAY" << endl;
        cout << "5.Check if full" << endl;
        cout << "6. Check if empty" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "performing enqueue" << endl;
            int element;
            cout << "enter element you want to insert : ";
            cin >> element;
            q1.enqueue(element);
            cout << "opertion performed ! " << endl;

            break;

        case 2:
            cout << "performing dequeue" << endl;
            cout << " before : ";
            q1.display();
            q1.dequeue();
            cout << "after : ";
            q1.display();

        case 3:
            cout << "peek" << endl;
            q1.peek();

        case 4:
            cout << "displaying" << endl;
            q1.display();

            break;

        case 5:
            cout << "checking for FULL " << endl;
            if (q1.isFull())
            {
                cout << "full" << endl;
            }

            break;

        case 6:
            cout << "checking for EMPTY " << endl;
            if (q1.isEmpty())
            {
                cout << "empty" << endl;
            }

            break;
        }
    }
}