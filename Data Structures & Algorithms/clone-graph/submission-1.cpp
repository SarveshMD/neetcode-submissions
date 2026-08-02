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

    Node* dfs(Node* node) {
        if (!node) return nullptr;
        if (hashmap.contains(node)) return hashmap[node];
        Node* new_node = new Node(node->val);
        hashmap[node] = new_node;
        vector<Node*> new_neighbors;
        for (Node* neighbor: node->neighbors) {
            new_neighbors.push_back(dfs(neighbor));
        }
        new_node->neighbors = new_neighbors;
        return new_node;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
