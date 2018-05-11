/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int nodecount(struct TreeNode* root)
{
        if (root == 0)
                return 0;
        else
                return nodecount(root->left) + nodecount(root->right) + 1;
}

void inorder(struct TreeNode* root, int *array, int *pos)
{
        if (root == 0)
            return;
        if (root->left != 0) {
                inorder(root->left, array, pos);
        }
        array[*pos] = root->val;
        *pos = *pos + 1;
        if (root->right != 0) {
                inorder(root->right, array, pos);
        }
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
        int pos = 0;
        int count = nodecount(root);
        int *ret = malloc(count * sizeof(int));
        *returnSize = count;

        inorder(root, ret, &pos);

        return ret;
}
