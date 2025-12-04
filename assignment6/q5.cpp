#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *prev;
    Node *next;

    Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node **head, Node **tail, char data)
{
    Node *newNode = new Node(data);
    if (*head == nullptr)
    {
        *head = *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

bool isPalindrome(Node *head, Node *tail)
{
    if (head == nullptr)
        return true;

    Node *left = head;
    Node *right = tail;

    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void deleteList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

int main()
{
    Node *head1 = nullptr;
    Node *tail1 = nullptr;

    string word1 = "LEVEL";
    for (char c : word1)
    {
        insertAtEnd(&head1, &tail1, c);
    }

    cout << "Word 1: " << word1 << endl;
    cout << "Linked List: ";
    printList(head1);

    if (isPalindrome(head1, tail1))
        cout << "Result: True (It's a palindrome)" << endl;
    else
        cout << "Result: False (Not a palindrome)" << endl;

    Node *head2 = nullptr;
    Node *tail2 = nullptr;

    string word2 = "HELLO";
    for (char c : word2)
    {
        insertAtEnd(&head2, &tail2, c);
    }

    cout << "Word 2: " << word2 << endl;
    cout << "Linked List: ";
    printList(head2);

    if (isPalindrome(head2, tail2))
        cout << "Result: True (It's a palindrome)" << endl;
    else
        cout << "Result: False (Not a palindrome)" << endl;

    deleteList(head1);
    deleteList(head2);

    return 0;
}