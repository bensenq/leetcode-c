/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 != NULL && t2 != NULL) {
        return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
    
    if (t1 == NULL && t2 == NULL)
        return true;
    
    return false;
}


bool isSymmetric(struct TreeNode* root){
    return isMirror(root->left, root->right);
}