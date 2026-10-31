/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(int *data, int pos, struct TreeNode *node, char **result, int *cap, int *size) {
    data[pos] = node->val;
    if(node->left == 0 && node->right == 0) {
        if(*size == *cap) {
            *cap *= 2;
            result = realloc(result, sizeof(char*) * (*cap));
        }
        char* path = calloc(1, sizeof(char*) * 500);
        for(int i = 0, j = 0; i <= pos; i++) {
            if(i != 0) {
                path[j++] = '-';
                path[j++] = '>';
            }
            int n = sprintf(path+j, "%d", data[i]);
            j += n;
        }
        result[*size] = path;
        *size += 1;
        return;
    }

    if (node->left != 0) dfs(data, pos+1, node->left, result, cap, size);
    if (node->right != 0) dfs(data, pos+1, node->right, result, cap, size);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int cap = 100;
    *returnSize = 0;
    char **result = malloc(sizeof(char *) * cap);
    int *data = malloc(sizeof(int) * 100);
    dfs(data, 0, root, result, &cap, returnSize);
    result = realloc(result, sizeof(char*) * (*returnSize));
    return result;
}
