/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sumNumberCore(struct TreeNode* root, int base, unsigned int *sum) {
    if (root->left == 0 & root->right == 0) {   //leaf
        *sum = *sum + base * 10 + root->val;
    }

    if (root->left != 0)    //dive into left
        sumNumberCore(root->left, base * 10 + root->val, sum);

    if (root->right != 0)   //dive into right
        sumNumberCore(root->right, base * 10 + root->val, sum);
}

int sumNumbers(struct TreeNode* root){
    unsigned int sum = 0;
    int base = 0;
    sumNumberCore(root, base, &sum);
    return sum;
}
