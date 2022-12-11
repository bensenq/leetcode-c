//backtracking

#include <stdlib.h>
#include <string.h>

void splitIpAddress (char *s, char *data, int offset, int seg, char ***result, int *count, int *max) {
    int len = strlen(s);
    if (len < seg || len > (3 * seg )) {
        return;
    }

    if (seg == 0) {
        if (*count == *max) {
            *max *= 2;
            *result = realloc(*result, sizeof(char *) * *max);
        }
        data[offset-1] = 0;
        (*result)[*count] = strdup(data);
        *count += 1;
        return;
    }

    data[offset] = s[0];
    data[offset+1] = '.';
    splitIpAddress(s+1, data, offset+2, seg-1, result, count, max);

    if (s[0] != '0' && len > 1) {
        data[offset+1] = s[1];
        data[offset+2] = '.';
        splitIpAddress(s+2, data, offset+3, seg-1, result, count, max);
    }

    if (s[0] != '0' && len > 2) {
        data[offset+2] = s[2];
        data[offset+3] = 0;
        if (atoi(&data[offset]) < 256) {
            data[offset+3] = '.';
            splitIpAddress(s+3, data, offset+4, seg-1, result, count, max);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize){
    int max = 10, count = 0;
    char **result = malloc(max * sizeof (char *));
    char *data = malloc(strlen(s) + 4);
    splitIpAddress(s, data, 0, 4, &result, &count, &max);
    *returnSize = count;
    result = realloc(result, sizeof(char *) * count);
    return result;
}

int main() {
    int size;
    restoreIpAddresses("1111111", &size);
    return 0;
}