/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* ret;
    if (root->val == val) return root;
    if (root->val > val) {
        if (root->left != 0) {
            return searchBST(root->left, val);
        }
    } else {
        if (root->right != 0) {
            return searchBST(root->right, val);
        }
    }
    return 0;
}