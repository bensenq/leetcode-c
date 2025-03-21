/* using hashtable for orginal node and cloned node */

struct hashTable {
    const void *key;          /* key: original addr */
    void *value;              /* value: cloned addr */
    UT_hash_handle hh;         /* makes this structure hashable */
};

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	struct hashTable *hash = NULL, *s, *ss;
    struct Node * tmp, *newtmp, *newhead;
    if(head == NULL) return NULL;
    else {
        newhead = malloc(sizeof(struct Node));
        memcpy(newhead, head, sizeof(struct Node));
        s = malloc(sizeof(struct hashTable));
        s->key = (void *)head;
        s->value = (void *)newhead;
        HASH_ADD_PTR(hash, key, s);
    }

    tmp = head;
    newtmp = newhead; 
    while(tmp->next != NULL) {
        newtmp->next = malloc(sizeof(struct Node));
        memcpy(newtmp->next, tmp->next, sizeof(struct Node));
        tmp = tmp->next;
        newtmp = newtmp->next;
        s = malloc(sizeof(struct hashTable));
        s->key = (void *)tmp;
        s->value = (void *)newtmp;
        HASH_ADD_PTR(hash, key, s);
    }

    /* iterate to redirect random pointer */
    newtmp = newhead;
    while(newtmp != NULL) {
        if(newtmp->random != 0) {
            HASH_FIND_PTR(hash, &newtmp->random, s);
            newtmp->random = s->value;
        }
        newtmp = newtmp->next;
    }
    /* clean up */
    HASH_ITER(hh, hash, s, ss) {
        HASH_DEL(hash, s);
        free(s);
    }
    return newhead;    
}