#include <stdbool.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    if (p == 0 && q == 0)
        return true;
    if (p != 0 && q != 0)
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
    return false;
}