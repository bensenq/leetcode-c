/* DFS */

#define min(a,b) (a>=b?b:a)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int ret;
    int minLeft, minRight;
    if (!root->left) 
        ret = minDepth(root->right) + 1;
    else if (!root->right) 
        ret = minDepth(root->left) + 1;
    else {
        minLeft = minDepth(root->left);
        if (minLeft == 1) ret = 2;  // found leaf and no need to get minRight
        else {
            minRight = minDepth(root->right);
            ret = min(minLeft, minRight) + 1;
        }
    }
    return ret;
}
