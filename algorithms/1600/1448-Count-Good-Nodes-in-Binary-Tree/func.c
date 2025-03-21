/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countGoodNodes(struct TreeNode *root, int max) {
    int ret = 0;
    if (root->val >= max) {
        ret++;
        max = root->val;
    }
    if (root->left != 0) {
        ret += countGoodNodes(root->left, max);
    }

    if (root->right != 0) {
        ret += countGoodNodes(root->right, max);
    }
    return ret;
}

int goodNodes(struct TreeNode* root){
    return countGoodNodes(root, root->val);
}