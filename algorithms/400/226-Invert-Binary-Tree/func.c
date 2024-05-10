/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == 0) return 0;
    struct TreeNode *left, *right;
    left = invertTree(root->left);
    right = invertTree(root->right);
    root->right = left;
    root->left = right;
    return root;
}