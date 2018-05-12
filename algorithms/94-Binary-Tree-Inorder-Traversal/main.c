/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define NULL 0
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
int nodecount(struct TreeNode* root)
{
        if (root == 0)
                return 0;
        else
                return nodecount(root->left) + nodecount(root->right) + 1;
}

typedef struct 
{
	struct TreeNode *node;
	int left;	/* indicate processing left or right */
} _stack;

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
        int pos = 0;
        int count = nodecount(root);
	struct TreeNode *temp;
	_stack stack[count];
	int top;
        int *ret = malloc(count * sizeof(int));
        *returnSize = count;
	int pop = 0;
	temp = root;
	top = -1;
	while(1) {

//		/* leaf logic */
//		if (temp->left == 0 && temp->right == 0) {
//			ret[pos++] = temp->val;
//			pop = 1;
//			continue;
//		}

		/* push logic */
		if (temp != 0) {
			top++;
			stack[top].node = temp;
			stack[top].left = 1;
		}
		
		/* inorder: left */
		if (stack[top].left == 1 && temp->left != 0) {
			temp = temp->left;
			continue;
		} else {
			stack[top].left = 0;	/* left handle over */
		}

		/* inorder: middle */
		ret[pos++] = temp->val;
		
		/* inorder: right */
		if (temp->right != 0) {
			temp = temp->right;
			continue;
		}

		top--;
		if (top == -1) {
			break;	/* over */
		} else {
			if(stack[top].left == 0) {
				goto pop;
			} else {
				ret[pos++] = stack[top].node->val;
			}
		}

		if (stack[top].left == 0) {
			top--;
			if (top == -1)
				break;
			pop = 1;
			temp = stack[top].node;
		}
	}

        return ret;
}
