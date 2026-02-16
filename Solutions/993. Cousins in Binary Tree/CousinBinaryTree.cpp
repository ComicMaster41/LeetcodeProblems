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
    int depthX = -1;
    int depthY = -1;

    TreeNode* parentX = nullptr;
    TreeNode* parentY = nullptr;

    void traverse(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (!node) return;

        traverse(node->left, node, depth + 1, x, y);

        if (node->val == x) {
            depthX = depth;
            parentX = parent;
        }

        if (node->val == y) {
            depthY = depth;
            parentY = parent;
        }

        traverse(node->right, node, depth + 1, x, y);
    }

    public:
        bool isCousins(TreeNode* root, int x, int y) {
            if (!root) return false;

            traverse(root, nullptr, 0, x, y);

            return (depthX != -1 && depthY != -1) && (parentX != parentY) && (depthX == depthY);
        }
};
