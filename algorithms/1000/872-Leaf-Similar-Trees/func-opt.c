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

bool genLeavesAndCompare(struct TreeNode *root, int *leaves, int *start, int *leavesc, int lenc) {
    if (root->left == NULL && root->right == NULL) {
        if (root->val != leavesc[*start] || *start >= lenc) return false;
        leaves[*start] = root->val;
        (*start)++;
    }
    
    if (root->left != NULL) {
        if(!genLeavesAndCompare(root->left, leaves, start, leavesc, lenc))return false;
    }
    
    if (root->right != NULL) {
        if(!genLeavesAndCompare(root->right, leaves, start, leavesc, lenc))return false;
    }
    return true;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int leaves1[200];
    int leaves2[200];
    int size1 = 0, size2 = 0;
    genLeaves(root1, leaves1, &size1);
    bool ret = genLeavesAndCompare(root2, leaves2, &size2, leaves1, size1);
    if (ret && size2 == size1) return true;
    else return false;
}