/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverseTree(struct TreeNode* root, int *seq, int *index) {
    if (root->left != 0) traverseTree(root->left, seq, index);
    seq[*index] = root->val;
    *index += 1;
    if (root->right != 0) traverseTree(root->right, seq, index);
}

void traverseAndSwap(struct TreeNode* root, int first, int second) {
    if (root->left != 0) traverseAndSwap(root->left, first, second);
    if (root->val == first) root->val = second;
    else if (root->val == second) root->val = first;
    if (root->right != 0) traverseAndSwap(root->right, first, second);
}

void recoverTree(struct TreeNode* root){
    int count = 0;
    int seq[1000];
    int first, second;
    traverseTree(root, seq, &count);
    for (int i = 0; i < count-1; i++) {
        if (seq[i] > seq[i+1]) {
            first = seq[i];
            break;
        }
    }
    for (int i = count-1; i > 0; i--) {
        if (seq[i] < seq[i-1]) {
            second = seq[i];
            break;
        }
    }

    traverseAndSwap(root, first, second);
}