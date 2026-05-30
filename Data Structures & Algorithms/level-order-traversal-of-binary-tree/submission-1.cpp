/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> bfs_queue;
        vector<vector<int>> res;

        if (!root) return res;
        bfs_queue.push(root);

        while (!bfs_queue.empty()) {
            int n = bfs_queue.size();
            vector<int> level;

            for (int i=0; i<n; i++) {
                TreeNode* front = bfs_queue.front();
                if (front) {
                    level.push_back(front->val);
                    if (front->left) bfs_queue.push(front->left);
                    if (front->right) bfs_queue.push(front->right);
                }
                bfs_queue.pop();
            }

            res.push_back(level);
        }
        return res;
    }
};
