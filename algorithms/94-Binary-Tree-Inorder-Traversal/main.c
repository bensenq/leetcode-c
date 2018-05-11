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

#define MAX(a, b) (a > b ? a : b)
int treeheight(struct TreeNode* root)
{
	if (root == 0) 
		return 0;
	else
		return MAX(treeheight(root->left), treeheight(root->left)) + 1;
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
        int pos = 0;
	int height = treeheight(root);
        int count = nodecount(root);
	struct TreeNode *temp;
	struct TreeNode *parent[height];
	int top = 0;
        int *ret = malloc(count * sizeof(int));
        *returnSize = count;
	while(1) {
		while (temp->left != 0) {
			parent[top++] = temp;
			temp = temp->left;
		}

		ret[pos] = temp->val;
		if (temp->right !=0) {
			parent[top++] = temp;
			temp = temp->right;
			continue;
		}
		
		temp = parent[top--];
		if(top == -1)
			break;
	}

        return ret;
}
