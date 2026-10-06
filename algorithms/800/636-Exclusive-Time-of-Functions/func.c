/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int *result = calloc(sizeof(int), n);
    int *stack = malloc(sizeof(int) * logsSize / 2);
    int top = -1;
    int last_time = 0;
    for(int i = 0; i < logsSize; i++) {
        char *pid_str  = strtok(logs[i], ":");
        char *s_str    = strtok(NULL, ":");
        char *time_str = strtok(NULL, ":");
        int p, t;

        if (pid_str && s_str && time_str) {
            p = atoi(pid_str);
            t = atoi(time_str);
            // printf("pid=%d, s=%s, time=%d\n", p, s_str, t);
        }

        if (strcmp(s_str,"start") == 0) {
            if(top != -1) {
                result[stack[top]] += (t - last_time);
            }
            stack[++top] = p;
            last_time = t;
        } else {
            result[stack[top--]] += (t - last_time) + 1;
            last_time = t + 1;
        }
    }
    *returnSize = n;
    return result;
}
