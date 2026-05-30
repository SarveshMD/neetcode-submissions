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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            int rv = root->val;
            int pv = p->val;
            int qv = q->val;
            if (rv > pv && rv > qv) {
                root = root->left;
            }
            else if (rv < pv & rv < qv) {
                root = root->right;
            }
            else return root;
        }
        return nullptr;
    }
};
