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
        ListNode* head = nullptr;
        ListNode* res;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                if (head) {
                    head->next = list1;
                    head = head->next;
                }
                else {
                    head = list1;
                    res = head;
                }
                list1 = list1->next;
            }
            else {
                if (head) {
                    head->next = list2;
                    head = head->next;
                }
                else {
                    head = list2;
                    res = head;
                }
                list2 = list2->next;
            }
        }
        if (list1) {
            if (head) head->next = list1;
            else {
                head = list1;
                res = head;
            }
        }
        if (list2) {
            if (head) head->next = list2;
            else {
                head = list2;
                res = head;
            }
        }    
        return res;
    }
};
