#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* return length that could be add to previous */
int longestValidParenthesesInner(char* s, int len, int *depth, int *index, int *longest) {
    int count = 0;
    int ret;
    while (*index < len) {
        char c = s[*index];
        *index += 1;
        if (c == ')' && *depth == 0) {  //top level seperator
            if (count > *longest) *longest = count;
            count = 0;
            continue;
        } else {
            if (c == '(') {
                int org_depth = *depth;
                *depth += 1;
                ret = longestValidParenthesesInner(s, len, depth, index, longest);
                if (org_depth == *depth)
                    count += ret;
                else break;
            } else {
                count += 2;
                *depth -= 1;
                break;
            }
        }
    }

    if (count > *longest) *longest = count;
    return count;
}

int longestValidParentheses(char* s) {
    int i = 0;
    int len = strlen(s);
    int longestValid = 0;
    int depth = 0;
    int ret;

    longestValidParenthesesInner(s, len, &depth, &i, &longestValid);
    return longestValid;
}

int main() {
    return longestValidParentheses("(()");
}