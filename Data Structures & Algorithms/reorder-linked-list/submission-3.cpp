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
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        /*
        int count = 0;
        ListNode* tmp = head;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        tmp = head;
        int splitPoint = count - (count-1)/2;
        ListNode* secondHalf = nullptr;
        for (int i=0; i<splitPoint-1; i++) {
            tmp = tmp->next;
        }
        secondHalf = tmp->next;
        tmp->next = nullptr;
        */
        // reverse secondHalf
        ListNode* curr = secondHalf;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        secondHalf = prev;
        ListNode* first = head;
        while (secondHalf) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = secondHalf->next;
            first->next = secondHalf;
            secondHalf->next = tmp1;
            secondHalf = tmp2;
            first = tmp1;
        }
    }
};
