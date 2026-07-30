/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> hashmap;
        Node* tmp = head;
        Node* res = new Node(tmp->val);
        Node* tmp2 = res;
        hashmap[tmp] = tmp2;
        tmp = tmp->next;
        while (tmp) {
            tmp2->next = new Node(tmp->val);
            hashmap[tmp] = tmp2->next;
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
        tmp = head;
        tmp2 = res;
        while (tmp) {
            tmp2->random = hashmap[tmp->random];
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        return res;
    }
};
