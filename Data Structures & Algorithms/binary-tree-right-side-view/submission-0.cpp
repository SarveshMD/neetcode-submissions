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
    void rightSide(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;
        if (res.size() > level) {
            rightSide(node->right, level+1, res);
            rightSide(node->left, level+1, res);
            return;
        }
        res.push_back(node->val);
        rightSide(node->right, level+1, res);
        rightSide(node->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res = {};
        rightSide(root, 0, res);
        return res;
    }
};
