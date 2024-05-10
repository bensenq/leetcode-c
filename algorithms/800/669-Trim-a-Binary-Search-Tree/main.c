/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
	if (root == NULL)
		return NULL;
	else if (L > root->val)
		return trimBST(root->right, L, R);
	else if (R < root->val)
		return trimBST(root->left, L, R);
	else {
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
}
