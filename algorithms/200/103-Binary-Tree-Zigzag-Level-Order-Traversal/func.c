/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    struct TreeNode *circle[1024];
    int size = 0;
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int)*size);
    int head = 0, tail = 0;
    bool reverse = false;
    if(root != 0) {
        circle[tail] = root;
        tail = 1;
    }
    while (head != tail) {
        int len = tail > head ? tail - head : (tail + 1024 - head);
        result = realloc(result, sizeof(int *)*(size+1));
        result[size] = malloc(sizeof(int)*len);
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(size+1));
        (*returnColumnSizes)[size] = len;
        for (int i = 0; i < len; i++) {
            if (reverse) {
                result[size][len-i-1] = circle[head]->val;
            } else {
                result[size][i] = circle[head]->val;
            }
            if (circle[head]->left != 0){
                circle[tail] = circle[head]->left;
                tail = (tail + 1) % 1024;
            }
            if (circle[head]->right != 0){
                circle[tail] = circle[head]->right;
                tail = (tail + 1) % 1024;
            }
            head = (head + 1) % 1024;
        }
        size++;
        reverse = !reverse;
    }    
    *returnSize = size;
    return result;    
}