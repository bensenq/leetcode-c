/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == 0) return 0;
    int depth = 0;
    struct Node * tmp = root;
    while(tmp) {
        depth++;
        tmp = tmp->left;
    }
    struct Node ** array = malloc(sizeof(struct Node *) * (1<<depth));
    array[0] = root;
    int level = 0;
    while (level < depth-1) {
        int j = 0;
        int total = 1 << level;
        int base_index = (1 << level) - 1;
        int next_index = (1 << (level+1)) - 1;
       
        //append next level
        while (j < total) { 
            array[next_index+j*2] = array[base_index+j]->left;
            array[next_index+j*2+1] = array[base_index+j]->right;
            
            j++;
        }
        level++;
    }

    level = 1;
    while(level < depth) {
        int j = 0;
        int total = (1 << level);
        int base_index = (1 << level) - 1;
        //connect current level
        while (j < total-1) {
            array[base_index+j]->next = array[base_index+j+1];           
            j++;
        }
        level++;
    }
    free(array);
    return root;
}
