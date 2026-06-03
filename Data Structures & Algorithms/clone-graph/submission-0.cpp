/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hashmap;
    
    Node* dfs(Node* curr) {
        if (!curr) return nullptr;
        if (hashmap.contains(curr)) {
            return hashmap[curr];
        }
        Node* newNode = new Node(curr->val);
        hashmap[curr] = newNode;
        for (Node* neighbor: curr->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        Node* cloneRoot = dfs(node);
        return cloneRoot;
    }
};
