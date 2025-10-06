/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* root, int *nodes, int *size) {
    if (root == NULL) return;
    traverse(root->left, nodes, size);
    nodes[*size] = root->val;
    *size += 1;
    traverse(root->right, nodes, size);
}
// two pointers
bool findTarget(struct TreeNode* root, int k) {
    int size = 0;
    int *nodes = malloc(sizeof(int)*10000);
    traverse(root, nodes, &size);
    if (nodes[0] * 2 > k || nodes[size-1] * 2 < k) return false;
    for (int i = 0, j = size - 1; i < j;) {
        int sum = nodes[i] + nodes[j];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            i++;
        } else {
            j--;
        }
    }
    free(nodes);
    return false; 
}
