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
        queue<pair<int, TreeNode*>> bfs_queue;
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> levelRes;
        int currLevel = 0;
        bfs_queue.push({0, root});
        while (bfs_queue.size() != 0) {
            auto [level, explore] = bfs_queue.front();
            if (level != currLevel) {
                currLevel = level;
                res.push_back(levelRes);
                levelRes = {};
            }
            levelRes.push_back(explore->val);
            bfs_queue.pop();
            if (explore->left) bfs_queue.push({level+1, explore->left});
            if (explore->right) bfs_queue.push({level+1, explore->right});
        }
        if (!levelRes.empty()) res.push_back(levelRes);
        return res;
    }
};
