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
    // & SUPER IMPORTANT!!! I FORGOT IT AND MY CODE BROKE!!!
    void trav(TreeNode* node, vector<int>& visited) {
        if (node == nullptr) return;
        trav(node->left, visited);
        visited.push_back(node->val);
        trav(node->right, visited);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> visited;
        if (root == nullptr) return {};
        trav(root, visited);
        return visited;
    }
};
