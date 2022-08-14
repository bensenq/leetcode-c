// use a stack to reverse the list

#include <stdbool.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct _stack {
    int top;
    int size;
    unsigned long *data;
} stack;

stack *stackCreate() {
    stack *s = calloc(sizeof(stack), 1);
    s->size = 1000;
    s->data = malloc(sizeof(unsigned long) * s->size);
    return s;
}

void stackDelete(stack *s) {
    free(s->data);
    free(s);
}

void stackPush(stack *s, unsigned long x) {
    if (s->top == s->size) {    //expand it
        s->size *= 2;
        s->data = realloc(s->data, sizeof(unsigned long) * s->size);
    }
    s->data[s->top] = x;
    s->top++;
}

unsigned long stackPeek(stack *s) {
    return s->data[s->top-1];
}

void stackPop(stack *s) {
    s->top--;
}

int stackSize(stack *s) {
    return s->top;
}

bool stackEmpty(stack *s) {
    return s->top == 0;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    stack *sa = stackCreate();
    stack *sb = stackCreate();
    struct ListNode *r = 0;
    for (struct ListNode *i = headA; i != 0; i = i->next) {
        stackPush(sa, (unsigned long)i);
    }
    for (struct ListNode *i = headB; i != 0; i = i->next) {
        stackPush(sb, (unsigned long)i);
    }

    while(!stackEmpty(sa) && !stackEmpty(sb) && (stackPeek(sa) == stackPeek(sb))) {
        r = stackPeek(sa);
        stackPop(sa); 
        stackPop(sb);
    }

    stackDelete(sa);
    stackDelete(sb);

    return r;
}