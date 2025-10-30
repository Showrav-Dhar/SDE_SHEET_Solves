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

    Node *reverse_list()
    {
        Node *prevNode = NULL;
        Node *currentNode = Head;
        Node *nextNode = NULL;

        while (currentNode != NULL)
        {
            nextNode = currentNode->next;
            currentNode->next = prevNode;

            prevNode = currentNode;
            currentNode = nextNode;
        }

        return prevNode;
        cout << "Reversal Done\n";
    }

    void print_ll_default()
    {
        Node *tempNode = Head;

        while (tempNode != NULL)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }
    void print_ll(Node *Head)
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

    ll.print_ll_default();
    // ll.reverse_list();
    ll.print_ll(ll.reverse_list());

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}