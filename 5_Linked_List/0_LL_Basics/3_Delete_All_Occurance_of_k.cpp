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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // FIX 1: Use POINTER to dummy node (not a regular object)
        // Why? The dummy node needs to persist and be accessible via pointers
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head; // connected with the main linked list

        // FIX 2: Use POINTER to current node
        ListNode* currentNode = dummyNode; // CurrentNode Pointer

        // FIX 3: Check currentNode->next (pointer syntax)
        while (currentNode->next != NULL) {
            if (currentNode->next->val == val) {
                // this handles if the val is in 1st index too
                currentNode->next = currentNode->next->next;
            } else {
                // FIX 4: Use pointer assignment
                currentNode = currentNode->next;
            }
        }

        // FIX 5: Get the new head from dummy's next
        head = dummyNode->next;
        // because dummy node was temporary head,
        // so dummynode->next points to the original head;

        // FIX 6: Clean up dummy node to avoid memory leak
        delete dummyNode;

        return head;
    }
};