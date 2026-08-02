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
        ListNode* tmp = head;
        int count = 0;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        if (count == 1) return nullptr;
        int nFromStart = count - n - 1;
        if (nFromStart == -1) return head->next;
        tmp = head;
        while (nFromStart--) {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};
