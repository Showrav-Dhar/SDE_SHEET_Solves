#include <iostream>
using namespace std;

// ==================== NODE CLASS ====================
// Represents a single node in the linked list
class Node
{
public:
    int data;    // Stores the actual value
    Node *next;  // Pointer to the next node in the list

    // Constructor: Initializes a new node with given value
    // Time Complexity: O(1) - Constant time operation
    Node(int val)
    {
        data = val;
        next = nullptr;  // New node initially points to nothing
    }
};

// ==================== LINKED LIST CLASS ====================
class List
{
    Node *head;  // Pointer to the first node (front of list)
    Node *tail;  // Pointer to the last node (back of list)

public:
    // Constructor: Initializes an empty linked list
    // Time Complexity: O(1)
    List()
    {
        head = tail = NULL;  // Both head and tail are null for empty list
    }

    // ==================== PUSH_FRONT ====================
    // Inserts a new node at the BEGINNING of the list
    // Time Complexity: O(1) - We directly access head
    // Space Complexity: O(1) - Only one new node created
    void push_front(int val)
    {
        // Step 1: Create a new node dynamically on heap
        Node *newNode = new Node(val);

        // Step 2: Check if list is empty
        if (head == NULL)
        {
            // If empty, new node becomes both head and tail
            head = tail = newNode;
            return;
        }
        else
        {
            // Step 3: Link new node to current head
            newNode->next = head;  // New node points to old head
            
            // Step 4: Update head to point to new node
            head = newNode;  // New node becomes the new head
        }
    }

    // ==================== PUSH_BACK ====================
    // Inserts a new node at the END of the list
    // Time Complexity: O(1) - We directly access tail
    // Space Complexity: O(1) - Only one new node created
    void push_back(int val)
    {
        // Step 1: Create a new node
        Node *newNode = new Node(val);

        // Step 2: Check if list is empty
        if (head == NULL)
        {
            // If empty, new node becomes both head and tail
            head = tail = newNode;
        }
        else
        {
            // Step 3: Link current tail to new node
            tail->next = newNode;  // Old tail now points to new node
            
            // Step 4: Update tail to point to new node
            tail = newNode;  // New node becomes the new tail
        }
    }

    // ==================== POP_FRONT ====================
    // Removes the node from the BEGINNING of the list
    // Time Complexity: O(1) - Direct access to head
    // Space Complexity: O(1) - Only using temp pointer
    void pop_front()
    {
        // Step 1: Check if list is empty
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        // Step 2: Store current head in temp (to delete later)
        Node *temp = head;
        
        // Step 3: Move head to next node
        head = head->next;
        
        // Step 4: Disconnect temp from list (optional but good practice)
        temp->next = nullptr;
        
        // Step 5: Delete the old head from memory (prevent memory leak)
        delete temp;
    }

    // ==================== POP_BACK ====================
    // Removes the node from the END of the list
    // Time Complexity: O(n) - Must traverse entire list to find second-last node
    // Space Complexity: O(1) - Only using temp pointer
    void pop_back()
    {
        // Step 1: Check if list is empty
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        // Step 2: Special case - only one node in list
        if (head == tail)
        {
            delete head;           // Delete the only node
            head = tail = NULL;    // Reset both head and tail to NULL
            return;
        }

        // Step 3: Start from head to find second-last node
        Node *temp = head;

        // Step 4: Traverse until temp points to second-last node
        // (second-last node is the one whose next is tail)
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        // Step 5: Disconnect the last node
        temp->next = NULL;
        
        // Step 6: Delete tail from heap memory
        delete tail;
        
        // Step 7: Update tail to second-last node
        tail = temp;
    }

    // ==================== INSERT ====================
    // Inserts a new node at a specific position (0-indexed)
    // Time Complexity: O(n) - May need to traverse up to position
    // Space Complexity: O(1) - Only one new node created
    void insert(int val, int pos)
    {
        // Step 1: Validate position
        if (pos < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        // Step 2: If inserting at position 0, use push_front
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        // Step 3: Start from head to find insertion point
        Node *temp = head;

        // Step 4: Traverse to node at (pos-1) position
        // We stop at pos-1 because we need to insert AFTER this node
        for (int i = 0; i < pos - 1; i++)
        {
            // Check if we've reached end of list before position
            if (temp == NULL)
            {
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->next;
        }

        // Step 5: Create new node
        Node *newNode = new Node(val);
        
        // Step 6: Link new node to next node
        newNode->next = temp->next;
        
        // Step 7: Link previous node to new node
        temp->next = newNode;
    }

    // ==================== SEARCH_ITEM ====================
    // Searches for a value in the list and returns its position
    // Time Complexity: O(n) - May need to traverse entire list
    // Space Complexity: O(1) - Only using temp pointer and counter
    void search_item(int key)
    {
        // Step 1: Start from head
        Node *temp = head;
        int pos = 0;  // Track current position

        // Step 2: Traverse the entire list
        while (temp != NULL)
        {
            // Step 3: Check if current node has the key
            if (temp->data == key)
            {
                cout << "Item found at index = " << pos << endl;
                return;  // Exit once found
            }
            
            // Step 4: Move to next node and increment position
            temp = temp->next;
            pos++;
        }

        // Step 5: If we reach here, item not found
        cout << "Item not found" << endl;
    }

    // ==================== PRINT_LL ====================
    // Prints all elements in the linked list
    // Time Complexity: O(n) - Must visit every node
    // Space Complexity: O(1) - Only using temp pointer
    void print_ll()
    {
        // Step 1: Start from head
        Node *tempNode = head;

        // Step 2: Traverse and print each node's data
        while (tempNode != NULL)
        {
            cout << tempNode->data << " ";  // Print current node data
            tempNode = tempNode->next;       // Move to next node
        }
        cout << endl;  // New line after printing all elements
    }
};

// ==================== MAIN FUNCTION ====================
int main()
{
    // Create an empty linked list
    List ll;

    // Insert elements at front: 3 -> 2 -> 1
    ll.push_front(3);  // List: 3
    ll.push_front(2);  // List: 2 -> 3
    ll.push_front(1);  // List: 1 -> 2 -> 3

    // Search for value 2 in the list
    ll.search_item(2);  // Output: Item found at index = 1

    // Print entire list
    ll.print_ll();  // Output: 1 2 3

    ll.push_back(10);

    ll.print_ll();
    ll.search_item(10);
    

    return 0;
}

/*
==================== QUICK REFERENCE FOR INTERVIEWS ====================

OPERATION          | TIME COMPLEXITY | SPACE COMPLEXITY
-------------------|-----------------|------------------
push_front()       | O(1)           | O(1)
push_back()        | O(1)           | O(1)
pop_front()        | O(1)           | O(1)
pop_back()         | O(n)           | O(1)
insert(val, pos)   | O(n)           | O(1)
search_item(key)   | O(n)           | O(1)
print_ll()         | O(n)           | O(1)

KEY POINTS:
- Singly linked list only moves forward (head -> tail)
- Tail pointer makes push_back O(1) instead of O(n)
- pop_back is O(n) because we need to find second-last node
- No random access - must traverse from head
- Dynamic size - grows/shrinks as needed
- Each node uses extra space for 'next' pointer

COMMON MISTAKES TO AVOID:
1. Forgetting to update head/tail pointers
2. Not checking for empty list (NULL checks)
3. Memory leaks (forgetting to delete nodes)
4. Losing reference to nodes during insertion/deletion
*/