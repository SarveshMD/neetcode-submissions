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
        ListNode* res = head;
        ListNode* tmp = head;
        int count = 0;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        int secondCount = (count - 1)/2;
        ListNode* secondStart = head;
        for (int i=0; i<(count-secondCount-1); i++) {
            secondStart = secondStart->next;
        }
        tmp = secondStart->next;
        secondStart->next = nullptr;
        secondStart = tmp;
        // secondStart holds second list
        ListNode* prev = nullptr;
        ListNode* curr = secondStart;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        secondStart = prev;
        // second list is reversed (hopefully)
        // to weave first and second lists: second list <= first list
        ListNode* ptr1 = head;
        ListNode* ptr2 = secondStart;
        for (int i=0; i<secondCount; i++) {
            ListNode* nextPtr1 = ptr1->next;
            ListNode* nextPtr2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = nextPtr1;
            ptr1 = nextPtr1;
            ptr2 = nextPtr2;
        }
    }
};
