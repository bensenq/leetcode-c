
typedef struct request {
    int time;
    struct request *next;
} Request;

typedef struct {
    Request guard;
    Request *tail;
    int count;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *obj = malloc(sizeof(RecentCounter));
    obj->guard.next = 0;
    obj->tail = &obj->guard;
    obj->count = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    Request *head;
    obj->tail->next = malloc(sizeof(Request));
    obj->tail = obj->tail->next;
    obj->tail->time = t;
    obj->tail->next = 0;
    obj->count++;
    head = obj->guard.next;
    while(head->time < (t - 3000)) {
        Request* tmp = head;
        head = head->next;
        free(tmp);
        obj->count--;
    }
    obj->guard.next = head;
    return obj->count;
}

void recentCounterFree(RecentCounter* obj) {
    Request *head = obj->guard.next;
    while(head != 0) {
        Request* tmp = head;
        head = head->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/