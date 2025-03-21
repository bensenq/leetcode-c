/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    struct TreeNode ** buffer[2];
    int capicity[2] = {64, 64};
    int size[2];
    buffer[0] = malloc(sizeof(void *)* capicity[0]);
    buffer[1] = malloc(sizeof(void *)* capicity[1]);
    buffer[0][0] = root;
    size[0] = 1;
    int maxSum = INT_MIN, sum, maxLevel;
    int cur = 0, next = 1, level = 1;
    while (size[cur] != 0) {
        sum = 0;
        if (capicity[next] < size[cur] * 2) {
            capicity[next] = size[cur] * 2;
            buffer[next] = realloc(buffer[next], sizeof(void *)*capicity[next]);
        }
        size[next] = 0;
        for (int i = 0; i < size[cur]; i++) {
            sum += buffer[cur][i]->val;
            if (buffer[cur][i]->left != 0) {
                buffer[next][size[next]] = buffer[cur][i]->left;
                size[next]++;
            }
            if (buffer[cur][i]->right != 0) {
                buffer[next][size[next]] = buffer[cur][i]->right;
                size[next]++;
            }
        }
        if (sum > maxSum) { maxSum = sum; maxLevel = level; }
        cur = (cur + 1) % 2;
        next = (next + 1) % 2;
        level++;
    }
    free(buffer[0]);
    free(buffer[1]);
    return maxLevel;
}