/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MIN(a,b)    (a<b?a:b)

void traversal(struct TreeNode *root, int *last, int *min) {
    if(root->left)  traversal(root->left, last, min);
    int diff = root->val - *last;
    *min = MIN(diff, *min);
    *last = root->val;
    if(root->right) traversal(root->right, last, min);
}

int getMinimumDifference(struct TreeNode* root){
    int lastnum = -100000;
    int min = 100000;
    traversal(root, &lastnum, &min);
    return min;
}