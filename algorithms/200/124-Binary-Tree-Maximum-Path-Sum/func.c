#define MAX(a,b) (a>b?a:b)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSumCore(struct TreeNode *root, int *maxTotal) {
    if (!root) return 0;
    int left_max, right_max, max, ret, sum;
    ret = root->val;
    left_max = maxPathSumCore(root->left, maxTotal);
    right_max = maxPathSumCore(root->right, maxTotal);
    max = MAX(left_max, right_max);
    if (max > 0) ret += max;
    max = MAX(ret, root->val + left_max + right_max);
    if (max > *maxTotal) *maxTotal = max;
    return ret;
}

int maxPathSum(struct TreeNode* root){
    int sum = INT_MIN;
    maxPathSumCore(root, &sum);
    return sum;
}
