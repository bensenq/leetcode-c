#define abs(a, b) (a >= b ? a - b : b - a)
#define max(a, b) (a >= b ? a : b)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
}

bool isBalanced(struct TreeNode* root){
    if(!root) return true;
    if (!isBalanced (root->left) || !isBalanced(root->right))
        return false;
    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);
    return abs(left_height, right_height) < 2;
}
