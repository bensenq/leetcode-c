/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode* root = NULL;
    if (preorderSize) {
        int leftSize, rightSize;
        int k = 0;
        root = malloc(sizeof(struct TreeNode));
        root->val = preorder[0];
        while (k < inorderSize) {
            if (inorder[k] == preorder[0]) break;
            k++;
        }
        leftSize = k;
        rightSize = inorderSize - k - 1;
        if (leftSize == 0) root->left = NULL;
        else {
            root->left = buildTree(preorder+1, leftSize, inorder, leftSize);
        }

        if (rightSize == 0) root->right = NULL;
        else {
            root->right = buildTree(preorder+1+leftSize, rightSize, inorder+leftSize+1, rightSize);
        }
    }
    return root;
}