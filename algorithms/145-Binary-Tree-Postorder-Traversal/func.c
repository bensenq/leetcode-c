/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorderTraversalCore(struct TreeNode* root, int* size, int** result) {
    if (!root) return;
    postorderTraversalCore(root->left, size, result);
    postorderTraversalCore(root->right, size, result);
    *size += 1;
    *result = realloc(*result, sizeof(int) * (*size));
    (*result)[*size-1] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 0;
    int *result = malloc(sizeof(int) * (size));
    postorderTraversalCore(root, &size, &result);
    *returnSize = size;
    return result;
}