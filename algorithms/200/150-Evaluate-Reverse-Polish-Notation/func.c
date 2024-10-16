int evalRPN(char** tokens, int tokensSize) {
    long long *stack = calloc(sizeof(long long), (tokensSize / 2 + 1));
    int top = 0, i = 0, value;
    while(i < tokensSize) {
        if (strcmp(tokens[i], "+") == 0) {
            stack[top-2] = stack[top-2] + stack[top-1];
            top--;
        } else if (strcmp(tokens[i], "-") == 0) {
            stack[top-2] = stack[top-2] - stack[top-1];
            top--;
        } else if (strcmp(tokens[i], "*") == 0) {
            stack[top-2] = stack[top-2] * stack[top-1];
            top--;
        } else if (strcmp(tokens[i], "/") == 0) {
            stack[top-2] = stack[top-2] / stack[top-1];
            top--;
        } else {
            value = atoi(tokens[i]);
            stack[top] = value;
            top++;
        }
        i++;
    }
    int ans = stack[0];
    free(stack);
    return ans;
}