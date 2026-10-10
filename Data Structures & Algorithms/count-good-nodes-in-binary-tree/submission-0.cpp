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
    void countGoodNodes(TreeNode* root, int pathMax, int& res) {
        if (!root) return;
        if (root->val >= pathMax) {
            res++;
            pathMax = root->val;
        }
        countGoodNodes(root->left, pathMax, res);
        countGoodNodes(root->right, pathMax, res);
    }

    int goodNodes(TreeNode* root) {
        int res = 0;
        countGoodNodes(root, INT_MIN, res);
        return res;
    }
};
