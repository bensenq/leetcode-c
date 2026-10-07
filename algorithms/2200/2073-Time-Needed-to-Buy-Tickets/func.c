int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int n = ticketsSize;
    int *q = malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) q[i] = tickets[i];
    int head = 0, rear = n;
    int pos = k;
    int time = 0;
    while(true) {
        time++;
        q[head]--;
        if (q[head] != 0) {
            q[rear] = q[head];
            if (head == pos) pos = rear;
            rear = (rear + 1) % (n + 1);
            head = (head + 1) % (n + 1);
        } else {
            if(head == pos) break;
            else head = (head + 1) % (n + 1);
        }
    }
    free(q);
    return time;
}
