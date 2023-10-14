/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (!root) return false;
    int ret;
    if (!root->left && !root->right && root->val == targetSum) return true;
    int newTarget = targetSum - root->val;
    return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
}
