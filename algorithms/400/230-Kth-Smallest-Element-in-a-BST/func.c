/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int inoderTraverse(struct TreeNode *root, int *index, int target) {
    if (root == 0) return -1;
    int ret = inoderTraverse(root->left, index, target);   //left
    if (ret >= 0) return ret;
    if (*index == target) return root->val;     //mid
    *index += 1;
    ret = inoderTraverse(root->right, index, target);      //right
    if (ret >= 0) return ret;
    return -1;
}

int kthSmallest(struct TreeNode* root, int k) {
    int index = 0;
    return inoderTraverse(root, &index, k-1);
}