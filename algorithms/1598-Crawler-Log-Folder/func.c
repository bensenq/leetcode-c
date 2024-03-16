int minOperations(char** logs, int logsSize) {
    int depth = 0;
    int i = 0;
    while (i < logsSize) {
        if(!strcmp(logs[i], "./")) {
            /* do nothing */
        } else if (!strcmp(logs[i], "../")) {
            if (depth > 0) depth--;
        } else {
            depth++;
        }
        i++;
    }
    return depth;
}