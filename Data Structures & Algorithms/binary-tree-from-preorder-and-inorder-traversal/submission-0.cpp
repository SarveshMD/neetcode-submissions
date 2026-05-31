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
    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, int preIndex, int inL, int inR, unordered_map<int, int>& hashmap) {
        if (inL > inR) return nullptr;
        if (inL == inR) return new TreeNode(inorder[inL]);
        TreeNode* new_node = new TreeNode(preorder[preIndex]);
        int in_index = hashmap[preorder[preIndex]];
        int left_size = in_index - inL;
        new_node->left = buildSubtree(preorder, inorder, preIndex+1, inL, in_index-1, hashmap);
        new_node->right = buildSubtree(preorder, inorder, preIndex+left_size+1, in_index+1, inR, hashmap);
        return new_node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> hashmap;
        for (int i=0; i<n; i++) {
            hashmap[inorder[i]] = i;
        }
        return buildSubtree(preorder, inorder, 0, 0, n - 1, hashmap);
    }
};
