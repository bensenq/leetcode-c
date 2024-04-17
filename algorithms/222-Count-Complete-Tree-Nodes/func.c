//https://leetcode.com/problems/count-complete-tree-nodes/solutions/61953/easy-short-c-recursive-solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(!root) return 0;
    int hl=0, hr=0;
    struct TreeNode *l=root, *r=root;
    while(l) {hl++;l=l->left;}
    while(r) {hr++;r=r->right;}
    if(hl==hr) return pow(2,hl)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}