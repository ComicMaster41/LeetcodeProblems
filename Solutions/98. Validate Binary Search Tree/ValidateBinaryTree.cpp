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
    
    bool validateHelper(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == nullptr) return true;
        // if we have a bigger value in the left or small in the right,
        // return false
        if (min && node->val <= min->val) return false;
        if (max && node->val >= max->val) return false;

    
        // return small -> mid -> large
        return validateHelper(node->left, min, node) && validateHelper(node->right, node, max);
    }

    bool isValidBST(TreeNode* root) {
        return validateHelper(root, nullptr, nullptr);
    }
};
