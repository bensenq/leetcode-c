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
    int cur_level = 1;
    int next_level = 0;
    int head = 0, tail = 1;
    int array_size = 1;
    struct Node ** array = malloc(sizeof(struct Node *) * array_size);
    array[0] = root;
    while (cur_level > 0) {
        array = realloc(array, sizeof(struct Node *) * (array_size + cur_level * 2));
        int j = 0;       
        //append next level
        while (j < cur_level) { 
            if (array[head+j]->left != 0) {     //left child
                array[tail++] = array[head+j]->left;
                next_level++;
            }
            if (array[head+j]->right != 0) {   //right child
                array[tail++] = array[head+j]->right;
                next_level++;
            } 
            j++;
        }

        //connect current level
        j = 0;
        while (j < cur_level - 1) {
            array[head+j]->next = array[head+j+1];
            j++;
        }
        head += cur_level;
        array_size += next_level;
        cur_level = next_level;
        next_level = 0;    
    }

    free(array);
    return root;
}
