/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* pruneTree(struct TreeNode* root) 
{
	if (root == 0) {
		return root;
	}
	

	if (root->left != 0) {
		root->left = pruneTree(root->left);
	} else if (root->right != 0) {
		root->right = pruneTree(root->left);
	}

	else if (root->left == 0 && root->right == 0) {
		if (root->value == 0)
			return NULL;
		else
			return root;
	} 
}
