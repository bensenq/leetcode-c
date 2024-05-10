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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    struct TreeNode *circle[1024];
    int size = 0;
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int)*size);
    int head = 0, tail = 0;
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
            result[size][i] = circle[head]->val;
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
    }    
    *returnSize = size;

    int *tmp, t;
    for (int i = 0; i < size/2; i++) {
        tmp = result[i];
        result[i] = result[size-i-1];
        result[size-i-1] = tmp;
        t = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[size-i-1];
        (*returnColumnSizes)[size-i-1] = t;
    }
    return result;    
}