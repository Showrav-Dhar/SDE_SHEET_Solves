#include <bits/stdc++.h>
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

    Node *Head;
    Node *Tail;

public:
    List()
    {
        Head = Tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (Head == NULL)
        {
            Head = Tail = newNode;
            return;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
    }

    void insert_at_k(int val, int position)
    {
        Node *newNode = new Node(val);
        Node *tempNode = Head;

        // position corner case check
        if (position < 0)
        {
            cout << "Invalid position" << endl;
        }

        if (position == 1) // 1 based indexing
        {
            push_front(val);
            return;
        }

        int pos = 2;
        int f = 0;
        while (tempNode != NULL)
        {
            if (pos == position)
            {
                newNode->next = tempNode->next;
                tempNode->next = newNode;
                f = 1;
                break;
            }
            pos++;
            tempNode = tempNode->next;
        }

        if (f == 0)
        {
            cout << "Invalid Position\n";
        }
    }

    void insert_before_k(int CurrentValue, int newVal)
    {
        Node *currentNode = Head;
        Node *newNode = new Node(newVal);
        Node *prevNode = NULL;
        int f = 0;

        if (Head->data == CurrentValue)
        {
            push_front(newVal);
            return;
        }

        while (currentNode != NULL)
        {
            if (currentNode->data == CurrentValue)
            {
                newNode->next = currentNode;
                prevNode->next = newNode;
                f = 1;
                break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        if (f == 0)
        {
            cout << "Current Value " << CurrentValue << " not present in List\n";
        }
    }

    void print_ll()
    {
        Node *tempNode = Head;

        while (tempNode != NULL)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List ll;

    ll.push_front(40);
    ll.push_front(30);
    ll.push_front(20);
    ll.push_front(10);

    ll.print_ll();

    ll.insert_before_k(20, 100); // (CurrentValue, NewValue)

    ll.print_ll();

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}