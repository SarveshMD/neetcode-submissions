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
    ListNode* mergeK(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (r - l == 1) return mergeTwo(lists[l], lists[r]);
        int m = (l+r)/2;
        ListNode* left = mergeK(lists, l, m);
        ListNode* right = mergeK(lists, m+1, r);
        return mergeTwo(left, right);
    }

    ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
        ListNode dummy = ListNode();
        ListNode* head = &dummy;
        ListNode* res = head;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while (ptr1 && ptr2) {
            ListNode* newNode = new ListNode();
            if (ptr1->val <= ptr2->val) {
                newNode->val = ptr1->val;
                ptr1 = ptr1->next;
            }
            else {
                newNode->val = ptr2->val;
                ptr2 = ptr2->next;
            }
            head->next = newNode;
            head = head->next;
        }
        if (ptr1) {
            head->next = ptr1;
        }
        if (ptr2) {
            head->next = ptr2;
        }
        if (res == nullptr) return nullptr;
        return res->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* res = mergeK(lists, 0, lists.size()-1);
        return res;
    }
};
