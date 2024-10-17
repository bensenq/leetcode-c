/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode* root){
    if(!root)return 0;
    return depth(root->left)+depth(root->right)+1;
}

typedef struct {
    void **stack;
    int size;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *iterator = malloc(sizeof(BSTIterator));
    iterator->stack = malloc(sizeof(void*)*depth(root));
    iterator->size = 0;
    struct TreeNode* p = root;
    while(p) {
        iterator->stack[iterator->size] = p;
        iterator->size++;
        p = p->left;
    }
    return iterator;
}

int bSTIteratorNext(BSTIterator* obj) {
    BSTIterator* iterator = obj;
    struct TreeNode *top = (struct TreeNode*)obj->stack[obj->size-1], *p;
    obj->size--;
    int val = top->val;
    p = top->right;
    while(p) {
        iterator->stack[iterator->size] = p;
        iterator->size++;
        p = p->left;
    }    
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->size > 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/