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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == 0) {
        *returnSize = 0;
        return 0;
    }

    int *result = malloc(sizeof(int)*100);
    int size = 0;
    struct TreeNode * array[101];
    int head = 0, tail = 0;
    int len = 1, nextlen;
    array[tail++] = root;
    while(len > 0) {
        result[size] = array[tail-1]->val;
        size++;
        nextlen = 0;
        for (int i = 0; i < len; i++) {
            if (array[head]->left != 0) {
                array[tail++] = array[head]->left;
                nextlen++;
            }
            if (array[head]->right != 0) {
                array[tail++] = array[head]->right;
                nextlen++;
            }
            head++;
        }
        len = nextlen;
    }
    *returnSize = size;
    result = realloc(result, sizeof(int)*size);
    return result;
}