/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    struct TreeNode * node = malloc(sizeof(struct TreeNode));
    int center, leftSize, rightSize;
    center = numsSize / 2;
    leftSize = center;
    rightSize = numsSize - center - 1;
    node->val = nums[center];
    node->left = sortedArrayToBST(nums, leftSize);
    node->right = sortedArrayToBST(nums+center+1, rightSize);
    return node;
}