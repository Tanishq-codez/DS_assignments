#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node{value, nullptr};

        if (!head)
        {
            head = newNode;
            head->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void displayWithRepeatHead()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;
    }
};
int main()
{
    CircularLinkedList clist;

    clist.insert(20);
    clist.insert(100);
    clist.insert(40);
    clist.insert(80);
    clist.insert(60);

    clist.displayWithRepeatHead();

    return 0;
}