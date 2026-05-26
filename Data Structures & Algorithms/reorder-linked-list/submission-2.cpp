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
    void reorderList(ListNode* head) {
        // Split
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        
        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        // prev is the second half's reversed head
        ListNode* ptr1 = head; // list 1 (first half)
        ListNode* ptr2 = prev; // list 2 (reversed second half)

        // merge two lists
        while (ptr1 && ptr2) {
            ListNode* tmp1 = ptr1->next;
            ListNode* tmp2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = tmp1;
            ptr1 = tmp1;
            ptr2 = tmp2;
        }
    }
};
