#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

public: // constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public: // second constructor so that we don't have to initial nullptr repeatedly
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node firstNode = Node(10); // Creates node on the STACK

    // The node is stored directly in the variable
    // Limited lifetime (destroyed when function ends)
    // Fixed memory location

    Node *firstNode = new Node(10); // Creates node on the HEAP

    // firstNode is a pointer (stores an address/location)
    // new Node(10) creates the actual node in dynamic memory (heap)
    // The node lives until you explicitly delete it
    // You can easily point to different nodes

    // Why We NEED Pointers for Linked Lists:

    // 1. To create links between nodes:

    Node *first = new Node(10);
    Node *second = new Node(20);

    first->next = second; // 'next' stores the ADDRESS of second node

    // 2. Without pointers, we can't link nodes together:

    // Node first = Node(10);
    // Node second = Node(20);

    // This WON'T work for linked lists:

    // first.next = second;  // ERROR! Can't store a whole node in 'next'
    // 'next' is a pointer, needs an address!

    

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}