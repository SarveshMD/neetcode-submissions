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
        int N = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            N++;
        }
        int k = N - n;
        cout << N << " k: " << k << endl;
        ptr = head;
        int index = 0;
        while (ptr) {
            if (index == k) {
                return ptr->next;
            }
            if (index == k-1) {
                ListNode* tmp = ptr->next;
                ptr->next = ptr->next->next;
                delete tmp;
                break;
            }
            ptr = ptr->next;
            index++;
        }
        return head;
    }
};
