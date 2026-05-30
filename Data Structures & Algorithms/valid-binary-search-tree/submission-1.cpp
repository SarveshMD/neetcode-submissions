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
    bool isValid(TreeNode* root, int low, int high) {
        if (!root) return true;
        if (!(!root->left || (root->left && root->val > root->left->val))) return false;
        if (!(!root->right || (root->right && root->val < root->right->val))) return false;
        if (!(low < root->val && root->val < high)) return false;
        return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
