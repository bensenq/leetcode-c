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
        if(!root) return 0;
        int ret;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if (minLeft == 0) ret = minRight + 1;
        else if (minRight == 0) ret = minLeft + 1;
        else ret = min(minLeft, minRight) + 1;
        return ret;
}
