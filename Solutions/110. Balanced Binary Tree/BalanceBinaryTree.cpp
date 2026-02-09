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
    // write a function to get the height of left or right of the tree
    int height(TreeNode* node) {
        // base case, if the node is null
        if (node == nullptr) return 0;
        // grab the height of the left
        int nodeLeft = height(node->left);
        if (nodeLeft == -1) return -1; // if 
        int nodeRight = height(node->right);
        if (nodeRight == -1) return -1;
        if (abs(nodeLeft - nodeRight) > 1)
            return -1;
        return 1 + max(nodeLeft, nodeRight);
    }

    bool isBalanced(TreeNode* root) {
        return (height(root) != -1);        
    }
};
