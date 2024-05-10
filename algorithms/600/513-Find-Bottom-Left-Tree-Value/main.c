int findBottomLeft(struct TreeNode* root, int *depth)
{
	if (root == 0) {
		*depth = 0;
		return -1; /* no meaning */
	} else  {
		int dl, dr;
		int vl, vr;
		vl = findBottomLeft(root->left, &dl);
		vr = findBottomLeft(root->right, &dr);
		if (dl == 0 && dr == 0) {
			*depth = 1;
			return root->val;
		} else {
			if (dl >= dr) {
				*depth = dl + 1;
				return vl;
			} else {
				*depth = dr + 1;
				return vr;
			}
		}
	}

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findBottomLeftValue(struct TreeNode* root) {
	int d;
	return findBottomLeft(root, &d);
}
