/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestorCore(struct TreeNode* root, int pval, int qval, int *count) {
    int oldcount = *count;
    struct TreeNode * ret;
    if (root == 0) return 0;
    if (root->val == pval || root->val == qval) (*count)++;
    ret = lowestCommonAncestorCore(root->left, pval, qval, count);   //left
    if (ret != 0) return ret;
    ret = lowestCommonAncestorCore(root->right, pval, qval, count);  //right
    if (ret != 0) return ret;
    if (oldcount == 0 && *count == 2) return root;
    return 0;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int count = 0;
    return lowestCommonAncestorCore(root, p->val, q->val, &count);
}