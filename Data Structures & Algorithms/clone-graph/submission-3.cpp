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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*,Node*> mapping;
        Node* clone_node_root = new Node(node->val);
        mapping[node] = clone_node_root;

        queue<Node*> bfs_queue;
        bfs_queue.push(node);

        while (!bfs_queue.empty()) {
            Node* curr_node = bfs_queue.front();
            for (Node* neighbor: curr_node->neighbors) {
                Node* clone_node;
                if (!mapping.contains(neighbor)) {
                    clone_node = new Node(neighbor->val);
                    mapping[neighbor] = clone_node;
                    bfs_queue.push(neighbor);
                }
                else {
                    clone_node = mapping[neighbor];
                }
                clone_node->neighbors.push_back(mapping[curr_node]);
            }
            bfs_queue.pop();
        }

        return clone_node_root;
    }
};
