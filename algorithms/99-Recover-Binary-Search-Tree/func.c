/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverseFindFirst(struct TreeNode* root, struct TreeNode** first, struct TreeNode** temp) {
    if (root->left != 0) traverseFindFirst(root->left, first, temp);
    if (*first != 0) return;

    if (*temp == 0 || root->val > (*temp)->val) { 
        *temp = root; 
    } else {
        *first = *temp;
        return;
    }
    if (root->right != 0) traverseFindFirst(root->right, first, temp);
}

void traverseFindSecond(struct TreeNode* root, struct TreeNode** second, struct TreeNode** temp) {
    if (root->right != 0) traverseFindSecond(root->right, second, temp);
    if (*second != 0) return;

    if (*temp == 0 || root->val < (*temp)->val) { 
        *temp = root; 
    } else {
        *second = *temp;  
        return;
    }
    if (root->left != 0) traverseFindSecond(root->left, second, temp);
}

void recoverTree(struct TreeNode* root){
    struct TreeNode *first = 0, *second = 0, *temp = 0;
    int swap;
    traverseFindFirst(root, &first, &temp);
    temp = 0;
    traverseFindSecond(root, &second, &temp);
    swap = first->val;
    first->val = second->val;
    second->val = swap;
}