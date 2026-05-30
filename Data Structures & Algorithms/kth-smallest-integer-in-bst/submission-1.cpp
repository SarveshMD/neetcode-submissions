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
    void inorder(TreeNode* root, vector<int>& traversal, int k) {
        if (!root) return;
        inorder(root->left, traversal, k);
        traversal.push_back(root->val);
        if (traversal.size() == k) return;
        inorder(root->right, traversal, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder_traversal = {};
        inorder(root, inorder_traversal, k);
        return inorder_traversal[k-1];
    }
};
