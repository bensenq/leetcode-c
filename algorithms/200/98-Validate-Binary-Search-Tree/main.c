/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
int max(struct TreeNode* root)
{
	int max_left, max_right;
	if(root->left)
		max_left = max(root->left);
	if(root->right)
		max_right = max(root->right);
	if (root->left == 0 && root->right == 0)
		return root->val;
	else if (root->left == 0)
		return MAX(root->val, max_right);
	else if (root->right == 0)
		return MAX(root->val, max_left);
	else
		return MAX(MAX(max_left, max_right), root->val);

}

int min(struct TreeNode* root)
{
	int min_left, min_right;
	if(root->left)
		min_left = min(root->left);
	if(root->right)
		min_right = min(root->right);
	if (root->left == 0 && root->right == 0)
		return root->val;
	else if (root->left == 0)
		return MIN(root->val, min_right);
	else if (root->right == 0)
		return MIN(root->val, min_left);
	else
		return MIN(MIN(min_left, min_right), root->val);

}
bool isValidBST(struct TreeNode* root) {
	if (root == 0)
		return false;
	if (root->left != 0 && isValidBST(root->left) == false)
		return false;
	if (root->right != 0 && isValidBST(root->right) == false)
		return false;
	if (root->left != 0 && max(root->left) >= root->val)
		return false;
	if (root->right != 0 && min(root->right) <= root->val)
		return false;

	return true;
}
