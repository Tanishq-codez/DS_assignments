#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {

        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int data)
{

    Node *temp = new Node(data);

    temp->next = head;

    head = temp;
}
void Print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Reverse(Node *&head);
int main()
{
    Node *l1 = new Node(4);
    Node *head = l1;

    for (int i = 3; i >= 1; i--)
    {

        InsertAtHead(head, i);
    }

    cout << "before reversal : ";
    Print(head);
    cout << "after reversal : ";
    Reverse(head);
    return 0;
}

void Reverse(Node *&head)
{

    Node *current = head;

    Node *previous = NULL;
    Node *nextnode = NULL;

    while (current != NULL)
    {

        nextnode = current->next;

        current->next = previous;

        previous = current;

        current = nextnode;
    }
    head = previous;
    Print(head);
}