int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int n = studentsSize;
    int *q = malloc(sizeof(int) * (n+1));
    for(int i = 0; i < n; i++) q[i] = students[i];
    int head = 0, rear = n;
    int i = 0;
    int eaten = 0;
    int cnt = 0;
    while(i < n) {
        if(q[head] != sandwiches[i]) {
            q[rear] = q[head];
            rear = (rear + 1) % (n + 1);
            head = (head + 1) % (n + 1);
            cnt++;
        } else {
            head = (head + 1) % (n + 1);
            eaten++;
            cnt = 0;
            i++;
        }
        if(cnt == n - eaten) break;
    }
    free(q);
    return n - eaten;
}
