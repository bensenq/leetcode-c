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

void preorderTraversalCore(struct TreeNode* root, int* size, int** result) {
    if (!root) return;
    *size += 1;
    *result = realloc(*result, sizeof(int) * (*size));
    (*result)[*size-1] = root->val;
    preorderTraversalCore(root->left, size, result);
    preorderTraversalCore(root->right, size, result);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 0;
    int *result = malloc(sizeof(int) * (size));
    preorderTraversalCore(root, &size, &result);
    *returnSize = size;
    return result;
}