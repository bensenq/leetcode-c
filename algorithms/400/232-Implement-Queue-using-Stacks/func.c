typedef struct _stack {
    int top;
    int data[100];
} stack;

stack *stackCreate() {
    stack *s = calloc(sizeof(stack), 1);
    return s;
}

void stackDelete(stack *s) {
    free(s);
}

void stackPush(stack *s, int x) {
    s->data[s->top] = x;
    s->top++;
}

int stackPeek(stack *s) {
    return s->data[s->top-1];
}

int stackPop(stack *s) {
    s->top--;
    return s->data[s->top];
}

int stackSize(stack *s) {
    return s->top;
}

bool stackEmpty(stack *s) {
    return s->top == 0;
}

typedef struct {
    stack *s;   //inorder: top is new val
    stack *r;   //reverse: top is old val
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *myQueue = malloc(sizeof(MyQueue));
    myQueue->s = stackCreate();
    myQueue->r = stackCreate();
    return myQueue;    
}

void myQueuePush(MyQueue* obj, int x) {
    int i = 0, size = stackSize(obj->s);
    stackPush(obj->s, x);
    while(i < size) {
        stackPush(obj->s, stackPop(obj->r));
        i++;
    }
    stackPush(obj->r, x);
    i = 0;
    while(i < size) {
        stackPush(obj->r, stackPop(obj->s));
        i++;
    }
}

int myQueuePop(MyQueue* obj) {
    int i = 0, size = stackSize(obj->s);
    while(i < size-1) {
        stackPush(obj->r, stackPop(obj->s));
        i++;
    }
    stackPop(obj->s);
    i = 0;
    while(i < size-1) {
        stackPush(obj->s, stackPop(obj->r));
        i++;
    }
    return stackPop(obj->r);
}

int myQueuePeek(MyQueue* obj) {
    return stackPeek(obj->r);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->s);
}

void myQueueFree(MyQueue* obj) {
    stackDelete(obj->s);
    stackDelete(obj->r);
    free(obj);    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/