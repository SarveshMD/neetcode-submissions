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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;

        int carryOver = 0;
        while (l1 && l2) {
            int sumOfNodes = l1->val + l2->val + carryOver;
            carryOver = 0;
            if (sumOfNodes >= 10) {
                carryOver = 1;
                sumOfNodes -= 10;   
            }
            curr->next = new ListNode(sumOfNodes);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            while (l1) {
                int sumOfNodes = l1->val + carryOver;
                carryOver = 0;
                if (sumOfNodes >= 10) {
                    carryOver = 1;
                    sumOfNodes -= 10;
                }
                curr->next = new ListNode(sumOfNodes);
                curr = curr->next;
                l1 = l1->next;
            }
        }
        if (l2) {
            while (l2) {
                int sumOfNodes = l2->val + carryOver;
                carryOver = 0;
                if (sumOfNodes >= 10) {
                    carryOver = 1;
                    sumOfNodes -= 10;
                }
                curr->next = new ListNode(sumOfNodes);
                curr = curr->next;
                l2 = l2->next;
            }
        }
        if (carryOver) {
            curr->next = new ListNode(carryOver);
        }
        return res->next;
    }
};
