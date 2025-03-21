
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    int capacity = 10;
    int size = 0;
    void **stack = malloc(sizeof(void *)*capacity);
    struct ListNode* p = head, *t;
    while(p) {
        stack[size++] = (void *)p;
        if (size == capacity) {
            capacity *= 2;
            stack = realloc(stack, sizeof(void *)*capacity);
        }
        p = p->next;
    }
    p = head;
    int count = size / 2, i = 0;
    while (i < count) {
        t = p->next;
        p->next = stack[--size];
        p->next->next = t;
        p = t;
        i++;
    }
    if (p) p->next = 0;
    free(stack);
}