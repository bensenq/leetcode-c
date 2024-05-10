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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    struct TreeNode *circle[8192];
    int size = 0;
    double *result = malloc(sizeof(double)*size);
    int head = 0, tail = 0;
    if(root != 0) {
        circle[tail] = root;
        tail = 1;
    }
    while (head != tail) {
        int len = tail > head ? tail - head : (tail + 8192 - head);
        double sum = 0;
        result = realloc(result, sizeof(double)*(size+1));
        for (int i = 0; i < len; i++) {
            sum += circle[head]->val;
            if (circle[head]->left != 0){
                circle[tail] = circle[head]->left;
                tail = (tail + 1) % 8192;
            }
            if (circle[head]->right != 0){
                circle[tail] = circle[head]->right;
                tail = (tail + 1) % 8192;
            }
            head = (head + 1) % 8192;
        }
        result[size] = sum / len;
        size++;
    }    
    *returnSize = size;
    return result;    
}