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
int FindLength(Node *&head)
{

    Node *temp = head;

    int length = 0;

    while (temp != NULL)
    {
        length += 1;
        temp = temp->next;
    }

    return length;
}
void FindMiddle(Node *&head)
{

    Node *temp = head;

    int l = FindLength(head) - 1;
    int i = 0;

    while (temp != NULL)
    {
        i++;
        if (i == l / 2 + 1)
        {
            cout << temp->data << endl;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}
int main()
{
    Node *ll = new Node(5);
    Node *head = ll;
    for (int i = 4; i >= 1; i--)
    {
        InsertAtHead(head, i);
    }
    FindMiddle(head);
    return 0;
}