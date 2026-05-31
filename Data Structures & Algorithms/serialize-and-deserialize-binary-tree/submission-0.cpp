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
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs_s(TreeNode* root, string& serial) {
        if (!root) {
            serial += "N,";
            return;
        }
        serial += to_string(root->val) + ",";
        dfs_s(root->left, serial);
        dfs_s(root->right, serial);
    }
    string serialize(TreeNode* root) {
        string serial = "";
        dfs_s(root, serial);
        return serial;
    }

    vector<string> preorder = {};
    int i = 0;
    TreeNode* dfs_d() {
        if (preorder[i] == "N") {
            i++;
            return nullptr;
        }
        int num = stoi(preorder[i]);
        i++;
        TreeNode* node = new TreeNode(num);
        node->left = dfs_d();
        node->right = dfs_d();
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            preorder.push_back(token);
        }
        TreeNode* head = dfs_d();
        return head;
    }
};
