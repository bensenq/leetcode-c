/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
/* return path number include root node */
long pathSumInclude(struct TreeNode* root, long long targetSum) {
    int sum = 0;
    if (root->val == targetSum) {
        sum++;
    }
    if (root->left) sum += pathSumInclude(root->left, targetSum - root->val);
    if (root->right) sum += pathSumInclude(root->right, targetSum - root->val);
    return sum;
}

int pathSum(struct TreeNode* root, int targetSum) {
    int sum;
    if (root == 0) return 0;
    sum = pathSumInclude(root, targetSum);
    if (root->left) sum += pathSum(root->left, targetSum); 
    if (root->right) sum += pathSum(root->right, targetSum);
    return sum; 
}