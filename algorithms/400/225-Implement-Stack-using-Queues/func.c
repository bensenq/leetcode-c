typedef struct _queue {
    int size;
    int head, tail;
    int data[100];
} queue;

queue* queueCreate () {
    queue *q = calloc(sizeof(queue), 1);
    return q;
}

void queueDelete (queue *q) {
    free(q);
}

void queuePush (queue *q, int val) {
    q->size++;
    q->data[q->tail] = val;
    q->tail = (q->tail+1) % 100;
}

int queuePeek (queue *q) {
    return q->data[q->head];
}

int queuePop (queue *q) {
    int ret;
    q->size--;
    ret = q->data[q->head];
    q->head = (q->head+1) % 100; 
    return ret;
}

int queueSize (queue *q) {
    return q->size;
}

bool queueIsEmpty (queue *q) {
    return q->size == 0;
}


typedef struct {
    queue *s;   //in order: bottom->top
    queue *r;   //reverse order: top->bottom
} MyStack;


MyStack* myStackCreate() {
    MyStack *myStack = malloc(sizeof(MyStack));
    myStack->s = queueCreate();
    myStack->r = queueCreate();
    return myStack;
}

void myStackPush(MyStack* obj, int x) {
    int i = 0;
    queuePush(obj->s, x);
    queuePush(obj->r, x);
    while (i < obj->s->size-1) {
        queuePush(obj->r, queuePop(obj->r));
        i++;
    }
}

int myStackPop(MyStack* obj) {
    int i = 0;
    while (i < obj->r->size-1) {
        queuePush(obj->s, queuePop(obj->s));
        i++;
    }
    queuePop(obj->s);
    return queuePop(obj->r);
}

int myStackTop(MyStack* obj) {
    return queuePeek(obj->r);  
}

bool myStackEmpty(MyStack* obj) {
    return queueIsEmpty(obj->s);
}

void myStackFree(MyStack* obj) {
    queueDelete(obj->s);
    queueDelete(obj->r);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/