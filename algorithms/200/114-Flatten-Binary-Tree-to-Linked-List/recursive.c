/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* return last element after flattened */
struct TreeNode* flattenCore(struct TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root;   /* leaf */
    struct TreeNode *leftlast, *rightfirst, *rightlast;
    leftlast = flattenCore(root->left);
    rightlast = flattenCore(root->right);
    if (!rightlast) {
        root->right = root->left;
        root->left = 0;
        rightlast = leftlast;
    }
    else if(leftlast) {
        rightfirst = root->right;
        root->right = root->left;
        root->left = 0;
        leftlast->right = rightfirst;
    }
    return rightlast;
}

void flatten(struct TreeNode* root){
    flattenCore(root);
}
