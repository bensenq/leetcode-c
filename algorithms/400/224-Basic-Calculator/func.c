//https://leetcode.com/problems/basic-calculator/solutions/62362/java-easy-version-to-understand/?envType=problem-list-v2&envId=stack
int calculate(char* s) {
    int n = strlen(s), result = 0, sign = 1;
    int capacity = n / 4 + 1; 
    int *stack = malloc(sizeof(int) * capacity);
    int top = 0;
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            while (i + 1 < n && isdigit(s[i + 1])) {
                num = num * 10 + (s[++i] - '0');
            }
            result += sign * num;
        } else if (s[i] == '+') {
            sign = 1;
        } else if (s[i] == '-') {
            sign = -1;
        } else if (s[i] == '(') {
            stack[top++] = result;
            if (top+1 >= capacity) {
                capacity += 2;
                stack = realloc(stack, sizeof(int)*capacity);
            }
            stack[top++] = sign;
            result = 0;
            sign = 1;
        } else if (s[i] == ')') {
            result *= stack[--top];
            result += stack[--top];
        }
    }
    free(stack);
    return result;
}