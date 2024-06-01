typedef struct qnode {
    int pos;
    struct qnode * next;
} Qnode;

typedef struct {
    Qnode *head;
    Qnode *tail;
} Queue;

Queue * createQueue() {
    Queue * queue = malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void enqueue(Queue *q, int pos) {
    if (q->tail != 0) {
        q->tail->next = malloc(sizeof(Qnode));
        q->tail->next->pos = pos;
        q->tail->next->next = 0;
        q->tail = q->tail->next;
    } else {
        q->tail = malloc(sizeof(Qnode));
        q->tail->pos = pos;
        q->tail->next = 0;
        q->head = q->tail;
    }
}

int peek(Queue *q) {
    return q->head->pos;
}

void dequeue(Queue *q) {
    Qnode * next = q->head->next;
    free(q->head);
    q->head = next;
    if (next == 0) q->tail = 0;
}

bool empty(Queue *q) {
    return (q->head == 0);
}

void freeQueue(Queue * q) {
    while(q->head != 0) {
        dequeue(q);
    }
}

char* predictPartyVictory(char* senate) {
    Queue *qr = createQueue();
    Queue *qd = createQueue();
    int i = 0;
    int ans = 0;
    while (senate[i] != 0) {
        if (senate[i] == 'R')
            enqueue(qr, i);
        else
            enqueue(qd, i);
        i++;
    }
    while (!empty(qr) && !empty(qd)) {
        int pr = peek(qr);
        int pd = peek(qd);
        dequeue(qr);
        dequeue(qd);
        if (pr < pd) enqueue(qr, i++);
        else   enqueue(qd, i++);
    }
    if (empty(qr)) ans = 1;
    freeQueue(qr);
    freeQueue(qd);
    if (ans == 1) return "Dire";
    else return "Radiant";
}
