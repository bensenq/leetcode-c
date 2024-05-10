/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(x, y) (x > y ? x : y)

int findMaxPath(struct TreeNode* root, int withRoot)
{
	int leftMax = 0, rightMax = 0;
	if (root->left != 0 && root->left->val == root->val) {
		leftMax = 1 + findMaxPath(root->left, 0);
	}

	if (root->right != 0 && root->right->val == root->val) {
		rightMax = 1 + findMaxPath(root->right, 0);
	}
	if (withRoot == 0)
		return MAX(leftMax, rightMax);
	else
		return leftMax + rightMax;
}

int longestUnivaluePath(struct TreeNode* root) {
    	int max = 0;
	int t;
	if (root == 0)
		return 0;
	t = findMaxPath(root, 1);
	if (t > max)
		max = t;
	if (root->left != 0) {
		t = longestUnivaluePath(root->left); 
		if (t > max)
			max = t;
	}

	if (root->right != 0) {
		t = longestUnivaluePath(root->right);
		if (t > max)
			max = t;
	}
	return max;
}
