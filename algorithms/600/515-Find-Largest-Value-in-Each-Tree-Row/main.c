/*
 * queue
 */
struct List {
	struct TreeNode *node;
	struct List *next;
};

void freeList(struct List* head) {
	struct List *th = head;
	struct List *tt;
	while (th != 0) {
		tt = th->next;
		free(th);	
		th = tt;
	};
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
	    
	struct List *head;
	struct List *tmp, *th, *tt;
	struct List *head_nextlevel = 0;
	struct List *tail_nextlevel;
	int *ret;
	int size;
	int max_flag;
	int max;

	if (root == 0) {
		*returnSize = 0;
		return 0;
	}

	head = malloc(sizeof(struct List));
	ret = malloc(sizeof(int) * 1000);
	head->node = root;
	head->next = 0;
	
	tmp = head;

	ret[0] = root->val;
	size = 1;

	max_flag = 0;
	do {
		if (tmp->node->left != 0) {
			struct List * t = malloc(sizeof(struct List));
			t->node = tmp->node->left;
			t->next = 0;
			if (head_nextlevel == 0) {
				head_nextlevel = t;
				tail_nextlevel = head_nextlevel;
			}
			else {
				tail_nextlevel->next = t;
				tail_nextlevel = t;
			}
			if (max_flag == 0) {
				max = tmp->node->left->val; 
				max_flag = 1;
			}
			else if (tmp->node->left->val > max)
				max = tmp->node->left->val;
		}

		if (tmp->node->right != 0) {
			struct List * t = malloc(sizeof(struct List));
			t->node = tmp->node->right;
			t->next = 0;
			if (head_nextlevel == 0) {
				head_nextlevel = t;
				tail_nextlevel = head_nextlevel;
			}
			else {
				tail_nextlevel->next = t;
				tail_nextlevel = t;
			}

			if (max_flag == 0) {
				max = tmp->node->right->val; 
				max_flag = 1;
			}
			else if (tmp->node->right->val > max)
				max = tmp->node->right->val;
		}
		
		tmp = tmp->next;
		if (tmp == 0) {
			if (head_nextlevel == 0)
				break;
			else {
				freeList(head);
				head = head_nextlevel;
				tmp = head;
				head_nextlevel = 0;
				ret[size] = max;
				size++;
				max_flag = 0;
			}
		} 
	} while(1);
	
	freeList(head);
	*returnSize = size;

	return ret;
}
