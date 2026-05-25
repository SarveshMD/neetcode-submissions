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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* head = nullptr;
        ListNode* headPtr = nullptr;
        bool first = true;
        while (ptr1 && ptr2) {
            if (ptr1->val <= ptr2->val) {
                if (first) {
                    head = ptr1;
                    headPtr = head;
                    first = false;
                }
                else {
                    headPtr->next = ptr1;
                    headPtr = headPtr->next;
                }
                ptr1 = ptr1->next;
            }
            else {
                if (first) {
                    head = ptr2;
                    headPtr = head;
                    first = false;
                }
                else {
                    headPtr->next = ptr2;
                    headPtr = headPtr->next;
                }
                ptr2 = ptr2->next;
            }
        }
        if (ptr1) {
            if (headPtr) headPtr->next = ptr1;
            else head = ptr1;
        }
        if (ptr2) {
            if (headPtr) headPtr->next = ptr2;
            else head = ptr2;
        }
        return head;
    }
};
