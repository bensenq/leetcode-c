/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) return 0;
    if (high < root->val) return rangeSumBST(root->left, low, high);
    if (low > root->val) return rangeSumBST(root->right, low, high);
    return root->val + rangeSumBST(root->left, low, root->val-1) + rangeSumBST(root->right, root->val+1, high);
}