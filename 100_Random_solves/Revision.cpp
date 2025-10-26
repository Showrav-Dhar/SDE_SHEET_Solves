#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            // linked list is empty
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {

        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        Node *tempNode = head;
        head = head->next;
        tempNode->next = nullptr;
        delete tempNode;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *tempNode = head;

        while (tempNode->next != tail)
        {
            tempNode = tempNode->next;
        }

        tempNode->next = nullptr;
        delete tail;
        tail = tempNode;
    }

    void insert_item(int val, int position)
    {
        if (position < 0)
        {
            cout << "Invalid position";
        }

        if (position == 0)
        {
            push_front(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *tempNode = head;

        for (int i = 0; i < position - 1; i++)
        {
            if (tempNode == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }

    int search_item(int key)
    {

        Node *tempNode = head;
        int position = 0;

        while (tempNode != NULL)
        {
            if (tempNode->data == key)
            {
                return position;
            }
            tempNode = tempNode->next;
            position++;
        }

        return -1;
    }

    void print_LL()
    {
        Node *tempNode = head;

        while (tempNode != nullptr)
        {
            cout << tempNode->data << "  ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }

    void mod_print_LL()
    {
        Node *tempNode = head;

        while (tempNode != nullptr)
        {
            cout << tempNode->data << " at index no " << search_item(tempNode->data) << endl;
            tempNode = tempNode->next;
        }
        cout << endl;
    }
};

int main()
{
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(10);

    // ll.print_LL();

    ll.insert_item(5, 2);

    ll.print_LL();
    cout<<"Modified printing\n";
    
    ll.mod_print_LL();
}