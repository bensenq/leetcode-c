/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void genLeaves(struct TreeNode *root, int *leaves, int *start) {
    if (root->left == NULL && root->right == NULL) {
        leaves[*start] = root->val;
        (*start)++;
    }
    
    if (root->left != NULL) {
        genLeaves(root->left, leaves, start);
    }
    
    if (root->right != NULL) {
        genLeaves(root->right, leaves, start);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int leaves1[200];
    int leaves2[200];
    int size1 = 0, size2 = 0;
    genLeaves(root1, leaves1, &size1);
    genLeaves(root2, leaves2, &size2);
    int i;
    
    if (size1 == size2) {
        for (i = 0; i < size1; i++) {
            if (leaves1[i] != leaves2[i])
                break;
        }
    }
    
    if (i == size1) return true;
    
    return false;
}