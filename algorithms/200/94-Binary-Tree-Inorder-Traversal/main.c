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
	int left_over;	/* indicate processing left or right */
} _stack;

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
        struct TreeNode *temp;
        int *ret;
        int count;
        _stack *stack;
        int pos = 0;
        int top;
        int pop;
	if (root == NULL) {
		*returnSize = 0;
		return 0;
	}
	count = nodecount(root);
        *returnSize = count;
	ret =  malloc(count * sizeof(int));
	stack = malloc(count * sizeof(_stack));
        temp = root;
        top = -1;
	pop = 0;
        while(1) {
                /* push logic */
                if (pop == 0) {
			top++;
			stack[top].node = temp;
			stack[top].left_over = 0;
			if (stack[top].node->left != 0) {
				temp = stack[top].node->left;
				pop = 0;
				continue;
			} else {
				stack[top].left_over = 1;       /* left handle over */
				/* inorder: middle */
				ret[pos++] = stack[top].node->val;
			}

			/* inorder: right */
			if (stack[top].node->right != 0) {
				temp = stack[top].node->right;
				pop = 0;
				continue;
			}
			pop = 1;
                } /* pop logic */
                else {
                        top--;
                        if (top == -1) 
                            	break;  /* stop traverse */
                        if (stack[top].left_over == 0) {
				stack[top].left_over = 1;       /* left handle over */
				/* inorder: middle */
				ret[pos++] = stack[top].node->val;
				/* inorder: right */
				if (stack[top].node->right != 0) {
					temp = stack[top].node->right;
					pop = 0;
					continue;
				}
			} else {
				pop = 1;
			}
                }
        }

	free(stack);
        return ret;
}


int main()
{
	int count;
	struct TreeNode t1, t2, t3;
	t1.val = 1;
	t1.left = 0;
	t1.right = &t2;

	t2.val = 2;
	t2.left = &t3;
	t2.right = 0;

	t3.val = 3;
	t3.left = t3.right = 0;

	inorderTraversal(&t1, &count);
}
