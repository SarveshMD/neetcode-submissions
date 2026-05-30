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
    ListNode* mergeK(vector<ListNode*>& lists, int l, int r) { // divide
        if (r - l == 1) return mergeTwo(lists[l], lists[r]);
        else if (r == l) return lists[l];
        int m = (l+r)/2;
        ListNode* left = mergeK(lists, l, m);
        ListNode* right = mergeK(lists, m+1, r);
        return mergeTwo(left, right);
    }
    ListNode* mergeTwo(ListNode* list1, ListNode* list2) { // conquer
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if (list1) {
            tail->next = list1;
        }
        if (list2) {
            tail->next = list2;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* result = mergeK(lists, 0, lists.size()-1);
        return result;
    }
};
