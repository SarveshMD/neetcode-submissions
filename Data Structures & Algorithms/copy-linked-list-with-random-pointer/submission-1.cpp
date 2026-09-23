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
        unordered_map<Node*, Node*> hashmap;
        Node* newHead = new Node(0);
        Node* oldHead = head;
        Node* curr = newHead;
        while (head) {
            curr->next = new Node(head->val);
            hashmap[head] = curr->next;
            head = head->next;
            curr = curr->next;
        }
        head = oldHead;
        curr = newHead->next;
        while (head) {
            curr->random = hashmap[head->random];
            head = head->next;
            curr = curr->next;
        }
        return newHead->next;
    }
};
