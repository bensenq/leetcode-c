#define max(a, b) (a) > (b) ? (a) : (b)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode* root) {
    if (root == 0) return 0;
    int left, right;
    left = depth(root->left) + 1;
    right = depth(root->right) + 1;
    return max(left, right);
}
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    int left = depth(root->left);
    int right = depth(root->right);
    if (left == right) return root;
    if (left > right) return lcaDeepestLeaves(root->left);
    return lcaDeepestLeaves(root->right);
}