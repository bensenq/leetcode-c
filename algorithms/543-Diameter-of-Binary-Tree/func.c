/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(x, y) (x > y ? x : y) 


int heightOfBinaryTree(struct TreeNode* root, int *max) {
    if (root == 0) return 0;

    int hl, hr, dia;
    hl = heightOfBinaryTree(root->left, max);
    hr = heightOfBinaryTree(root->right, max);
    dia = hl + hr;
    if(dia > *max) *max = dia;
    return MAX(hl, hr) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int max = 0;
    heightOfBinaryTree(root, &max);
    return max;
}