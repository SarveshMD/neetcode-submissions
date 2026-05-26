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
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
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
        printList(head);
        printList(secondHalf);

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
        ListNode* list1 = head;
        ListNode* list2 = prev; // redefine

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        // merge two lists
        ListNode *tmp1 = nullptr, *tmp2 = nullptr;
        while (ptr1 && ptr2) {
            tmp1 = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = ptr1->next;
            ptr2 = tmp1;
        }
    }
};
