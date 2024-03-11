#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {

    int len = strlen(s);
    int longestValid = 0;
    int depth = 0, i = 0;    
    int *stack = malloc(sizeof(int) * (len+1));
    stack[0] = 0;
    while (i < len) {
        if (s[i] == ')') {
            if (depth == 0) {
                if (stack[0] > longestValid) longestValid = stack[0];
                stack[0] = 0;
            } else {
                stack[depth-1] += stack[depth] + 2;
                depth--;
            }
        } else {
            depth++;
            stack[depth] = 0;
        }
        i++;
    }

    while(depth >= 0) {
        if (stack[depth] > longestValid) longestValid = stack[depth];
        depth--;
    }

    free(stack);
    return longestValid;
}

int main() {
    return longestValidParentheses("(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(");
}