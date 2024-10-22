int evalRPN(char** tokens, int tokensSize) {
    int *stack = malloc(sizeof(int)*(tokensSize/2+1));
    int top = 0, ans;
    for(int i = 0; i<tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0 || 
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {
            if (strcmp(tokens[i], "+") == 0) {
                ans = stack[top-2] + stack[top-1];
            } else if (strcmp(tokens[i], "-") == 0) {
                ans = stack[top-2] - stack[top-1];
            } else if (strcmp(tokens[i], "*") == 0) {
                ans = stack[top-2] * stack[top-1];
            } else {
                ans = stack[top-2] / stack[top-1];
            }
            top -= 2;
            stack[top++] = ans;
        } else {
            stack[top++] = atoi(tokens[i]);
        }
    }
    ans = stack[0];
    free(stack);
    return ans;
}