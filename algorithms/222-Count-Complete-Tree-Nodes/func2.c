/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == 0) return 0;
    int count = 1, current = 1, expect = 2;
    struct TreeNode ** prevarray = malloc(sizeof(struct TreeNode*) * 1);
    struct TreeNode ** nextarray = malloc(sizeof(struct TreeNode*) * expect);
    prevarray[0] = root;
    while (1) {
        int size = 0;
        for (int i = 0; i < current; i++) {
            if(prevarray[i]->left != 0) {
                nextarray[size] = prevarray[i]->left;
                size++;
            } else break;

            if(prevarray[i]->right != 0) {
                nextarray[size] = prevarray[i]->right;
                size++;
            } else break;
        }
        count += size;
        if(size == expect) {
            current = size;
            expect *= 2;
            free(prevarray);
            prevarray = nextarray;
            nextarray = malloc(sizeof(struct TreeNode*) * expect);
        } else break;
    }
    free(prevarray);
    free(nextarray);
    return count;
}