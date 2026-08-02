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
    ListNode* reverseList(ListNode* head)
    {
        if (!head) return nullptr;
        ListNode* back = head;
        ListNode* front = head->next;
        while (front) {
            ListNode* next = front->next;
            front->next = back;
            if (back == head) back->next = nullptr;
            back = front;
            front = next;
        }
        return back;
    }
};
