// strtok + stack

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack {
    int top;
    int data[1500];
} stack;

stack *stackCreate() {
    stack *s = calloc(sizeof(stack), 1);
    return s;
}

void stackDelete(stack *s) {
    free(s);
}

void stackPush(stack *s, int x) {
    s->data[s->top] = x;
    s->top++;
}

int stackPeek(stack *s) {
    return s->data[s->top-1];
}

int stackPop(stack *s) {
    s->top--;
    return s->data[s->top];
}

int stackSize(stack *s) {
    return s->top;
}

bool stackEmpty(stack *s) {
    return s->top == 0;
}

char * simplifyPath(char *path){
    stack *s = stackCreate();
    int i = 0;
    int offset = 0;
    int len = strlen(path);
    char *result = malloc(len+1);
    char *saveptr, *token;
    char *str = strdup(path);
    token = strtok_r(str, "/", &saveptr);
    while (token != 0) {
        if(strcmp(token, ".") != 0) {
            if (strcmp(token, "..") == 0) {
                if (stackSize(s) > 1) {
                    offset = stackPop(s);
                } else {
                    offset = 0;
                }
            } else {
                int len = strlen(token);
                result[offset] = '/';
                stackPush(s, offset);
                offset++;
                strcpy(result+offset, token);
                offset += len;
            }
        }
        token = strtok_r(0, "/", &saveptr);
    }
    if (offset == 0) {
        result[0] = '/';
        offset = 1;
    }
    result[offset] = 0;
    result = realloc(result, offset+1);
    stackDelete(s);
    free(str);
    return result;
}

int main() {
    simplifyPath("/home/../foo/");
    return 0;
}