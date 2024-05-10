/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    struct TreeNode* root = NULL;
    if (postorderSize) {
        int leftSize, rightSize;
        int k = 0;
        root = malloc(sizeof(struct TreeNode));
        root->val = postorder[postorderSize-1];
        while (k < inorderSize) {
            if (inorder[k] == postorder[postorderSize-1]) break;
            k++;
        }
        leftSize = k;
        rightSize = inorderSize - k - 1;
        if (leftSize == 0) root->left = NULL;
        else {
            root->left = buildTree(inorder, leftSize, postorder, leftSize);
        }

        if (rightSize == 0) root->right = NULL;
        else {
            root->right = buildTree(inorder+leftSize+1, rightSize, postorder+leftSize, rightSize);
        }
    }
    return root;    
}