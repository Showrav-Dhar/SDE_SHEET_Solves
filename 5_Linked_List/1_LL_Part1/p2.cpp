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
    ListNode* middleNode(ListNode* head) {
        ListNode* SlowPointer = head;
        ListNode* FastPointer = head;

        while (FastPointer != NULL and FastPointer->next != NULL) {
            SlowPointer = SlowPointer->next;
            FastPointer = FastPointer->next->next;
        }
        
        return SlowPointer;
    }
};