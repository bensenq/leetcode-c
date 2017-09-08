/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
	struct TreeNode * n = malloc(sizeof(struct TreeNode));
	int i, index = 0;
	int max = nums[0];
	/* find max index */
	for (i = 1; i < numsSize; i++) {
		if (nums[i] > max) {
			index = i;
			max = nums[i];
		}
	}
	n->val = max;
	if(index == 0)
		n->left = 0;
	else
		n->left = constructMaximumBinaryTree(nums, index); 

	if(index == (numsSize-1))
		n->right = 0;
	else
		n->left = constructMaximumBinaryTree(nums+index+1, numsSize-index-1);

	return n;
}
