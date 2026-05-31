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
    int res = INT_MIN;
    int maxPathSumm(TreeNode* root) {
        if (!root) return 0;
        int left = maxPathSumm(root->left);
        int right = maxPathSumm(root->right);
        int with_split = max(left, 0) + max(right, 0) + root->val;
        int without_split = max(0, max(left, right)) + root->val;
        res = max(with_split, res);
        return without_split;
    }
    int maxPathSum(TreeNode* root) {
        res = root->val;
        maxPathSumm(root);
        return res;
    }
};
