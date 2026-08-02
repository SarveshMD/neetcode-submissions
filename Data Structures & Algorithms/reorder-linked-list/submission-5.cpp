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
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        // second holds second list
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;
        // second list is reversed (hopefully)
        // to weave first and second lists: second list <= first list
        ListNode* ptr1 = head;
        ListNode* ptr2 = second;
        while (ptr2) {
            ListNode* nextPtr1 = ptr1->next;
            ListNode* nextPtr2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = nextPtr1;
            ptr1 = nextPtr1;
            ptr2 = nextPtr2;
        }
    }
};
