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

    // push_front

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

    void pop_front()
    {
        if (Head == NULL)
        {
            cout << "Linked List Is Empty" << endl;
            return;
        }
        Node *tempNode = Head;
        Head = Head->next;

        tempNode->next = nullptr;
        delete tempNode;
    }

    void pop_back()
    {
        if (Head == NULL)
        {
            cout << "Linked List Is Empty" << endl;
            return;
        }

        Node *tempNode = Head;

        while (tempNode->next != Tail)
        {
            tempNode = tempNode->next;
        }

        tempNode->next = NULL;

        delete Tail;

        Tail = tempNode;
    }

    // delete kth element of a list

    void delete_item(int position)
    {
        if (Head == NULL)
        {
            return;
        }

        if (position == 0)
        { // first item, pop front
            Node *temp = Head;
            Head = Head->next;
            delete temp;
        }

        int pos = 0;
        Node *tempNode = Head;
        Node *prevNode = NULL;

        while (tempNode != NULL)
        {

            if (pos == position)
            {
                prevNode->next = prevNode->next->next;
                delete tempNode;
                break;
            }
            prevNode = tempNode;
            tempNode = tempNode->next;
            pos++;
        }
    }


    void delete_item_by_val(int value) // one occurance
    {

        if (Head->data == value)
        {
            Node *tempNode = Head;
            Head = Head->next;
            tempNode->next = nullptr;
            delete tempNode;
            return;
        }

        Node *tempNode = Head;
        Node *prevNode = NULL;

        while (tempNode != NULL)
        {

            if (tempNode->data == value)
            {
                prevNode->next = prevNode->next->next;
                delete tempNode;
                break;
            }
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
    }

    void print_ll()
    {
        Node *TempNode = Head;
        while (TempNode != NULL)
        {
            cout << TempNode->data << " ";
            TempNode = TempNode->next;
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    cout << "Linked List - " << endl;
    ll.print_ll();
    cout << "Delete At index 1\n";
    ll.delete_item(1); // index
    ll.print_ll();

    // Delete last node and then push_back to verify tail is updated correctly

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}