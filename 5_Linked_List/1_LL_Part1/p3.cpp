// #include <bits/stdc++.h>
// using namespace std;
// vector<int> ara;
// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int val)
//     {
//         data = val;
//         next = nullptr;
//     }
// };

// class List
// {
//     Node *Head;
//     Node *Tail;

// public:
//     List()
//     {
//         Head = Tail = nullptr;
//     }

//     void push_front(int val)
//     {
//         Node *newNode = new Node(val);

//         if (Head == NULL)
//         {
//             Head = Tail = newNode;
//             return;
//         }
//         else
//         {
//             newNode->next = Head;
//             Head = newNode;
//         }
//     }

//     void LL_to_array()
//     {
//         Node *tempNode1 = Head;

//         while (tempNode1 != NULL)
//         {
//             ara.push_back(tempNode1->data);
//             tempNode1 = tempNode1->next;
//         }
//     }

//     void print_LL()
//     {
//         Node *tempNode = Head;

//         while (tempNode != NULL)
//         {
//             cout << tempNode->data << " ";
//             tempNode = tempNode->next;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     List ll1;

//     ll1.push_front(5);
//     ll1.push_front(3);
//     ll1.push_front(1);

//     List ll2;

//     ll2.push_front(6);
//     ll2.push_front(4);
//     ll2.push_front(2);

//     ll1.LL_to_array();
//     ll2.LL_to_array();

//     for (auto it : ara)
//     {
//         cout << it << " ";
//     }
//     cout<<endl;

//     sort(ara.begin(), ara.end());

//     List ll3;

//     for (int i = ara.size() - 1; i >= 0; i--)
//     {
//         ll3.push_front(ara[i]);
//     }

//     ll3.print_LL();

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Better -

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *tempNode1 = list1; // head of the first list
        ListNode *tempNode2 = list2; // head of the second list

        ListNode *dummyHead = new ListNode(-1); // dummy node for the new list
        ListNode *tempHead = dummyHead;         // storing the dummy node in a temp node

        while (tempNode1 != NULL and tempNode2 != NULL)
        {
            if (tempNode1->val < tempNode2->val)
            {
                tempHead->next = tempNode1; // connecting tempNode to list1

                tempHead = tempNode1; // moving the tempNode forward

                tempNode1 = tempNode1->next; // moving the temp Head of first list forward
            }
            else
            {
                tempHead->next = tempNode2; // connecting tempNode to list2

                tempHead = tempNode2; // moving temoNode forward

                tempNode2 = tempNode2->next; // moving temp head of second list forward
            }
        }

        if (tempNode1 == NULL) // means list 1 is finished, list 2 is not finished yet
        { // getting the rest of the items
            tempHead->next = tempNode2;
        }
        else
        { // means list 2 is finished, list 1 is not finished yet
            tempHead->next = tempNode1;
        }

        return dummyHead->next; // returing the head of the new LL
    }
};