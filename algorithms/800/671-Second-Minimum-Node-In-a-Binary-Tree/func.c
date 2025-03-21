/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root) {
    if (root->left == 0) return -1;
    int leftMin, rightMin;
    int secondMin;
    if (root->left->val > root->right->val) {
        leftMin = root->left->val;
        rightMin = findSecondMinimumValue(root->right);
    } else if (root->left->val < root->right->val) {
        leftMin = findSecondMinimumValue(root->left);
        rightMin = root->right->val;
    } else {
        leftMin = findSecondMinimumValue(root->left);
        rightMin = findSecondMinimumValue(root->right);
    }
    if (leftMin == -1 && rightMin == -1) {
        secondMin = -1;
    } else if(leftMin == -1 || rightMin == -1) {
        secondMin = (leftMin == -1) ? rightMin : leftMin;
    } else {
        secondMin = (leftMin > rightMin) ? rightMin : leftMin;
    }
    return secondMin;
}