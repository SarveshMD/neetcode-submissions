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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(); // dummy node
        ListNode* ptr = head;
        int k = lists.size();
        while (true) {
            int minListIndex = -1;
            int minListHead = INT_MAX;
            for (int i=0; i<k; i++) {
                if (lists[i] && lists[i]->val < minListHead) {
                    minListHead = lists[i]->val;
                    minListIndex = i;
                }
            }
            if (minListIndex == -1) break;
            ListNode* minHeadList = lists[minListIndex];
            ptr->next = minHeadList;
            lists[minListIndex] = lists[minListIndex]->next;
            minHeadList->next = nullptr;
            ptr = ptr->next;
        }
        return head->next;
    }
};
