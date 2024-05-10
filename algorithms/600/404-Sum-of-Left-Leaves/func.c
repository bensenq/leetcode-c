/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    if (root->left != 0) {
        if (root->left->left == 0 && root->left->right == 0) 
            sum += root->left->val;
        else {
            sum += sumOfLeftLeaves(root->left);
        }
    }
    if (root->right != 0) {
        sum += sumOfLeftLeaves(root->right);
    }

    return sum;
}