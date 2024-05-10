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


int findBottomLeftValue(struct TreeNode* root) {
	struct List *head = malloc(sizeof(struct List));
	struct List *tmp, *th, *tt;
	struct List *head_nextlevel = 0;
	struct List *tail_nextlevel;
	int ret;
	head->node = root;
	head->next = 0;
	
	tmp = head;

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
			}
		} 
	} while(1);

	ret = head->node->val;
	
	freeList(head);

	return ret;
}
