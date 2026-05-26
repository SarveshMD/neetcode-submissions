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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        for (int i=0; i<n && first; i++) {
            first = first->next;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* second = dummy;
        while (first) {
            first = first->next;
            second = second->next;
        }
        ListNode* tmp = second->next;
        second->next = second->next->next;
        delete tmp;
        return dummy->next;
    }
};
