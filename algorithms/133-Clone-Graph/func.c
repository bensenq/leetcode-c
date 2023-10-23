/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *cloneGraph(struct Node *s) {
    if (s == 0) return 0;
    struct Node *ret;

    //traversal and clone
    int *visited = calloc(101, sizeof(int));
    struct Node **cloned = calloc(101, sizeof(struct Node*));
    struct Node **queue = calloc(100, sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = s;
    visited[s->val] = 1;
    while (head < tail) {
        struct Node *t = queue[head++];     //dequeue
        for (int i = 0; i < t->numNeighbors; i++) {
            int val = (t->neighbors)[i]->val;
            if (visited[val] == 0) {
                queue[tail++] = (t->neighbors)[i];  //enqueue
                visited[val] = 1;
            }
        }
        cloned[t->val] = malloc(sizeof(struct Node));
        memcpy(cloned[t->val], t, sizeof(struct Node));
        cloned[t->val]->neighbors = malloc(sizeof(struct Node*) * t->numNeighbors);
    }

    //update neighbors to cloned
    head = 0;
    while (head < tail) {
        struct Node *t = queue[head++];
        int val = t->val;
        struct Node *clone = cloned[t->val];
        clone->neighbors = malloc(sizeof(struct Node*) * t->numNeighbors);
        for (int i = 0; i < t->numNeighbors; i++) {
            int val = (t->neighbors)[i]->val;
            clone->neighbors[i] = cloned[val];
        }
    }
    printf("here3\n");
    ret = cloned[queue[0]->val];

    free(visited);
    free(queue);
    free(cloned);

    return ret;
}