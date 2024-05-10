#include <stdbool.h>
#include <string.h>

bool isMatchCore(char * s, char * p, int i, int j, char **memo){
    bool result;
    if (memo[i][j] == 1)    //check memo
        return false;

    if (p[j] == 0 && s[i] == 0)
        return true;

    if (p[j] == 0 && s[i] != 0) {
        result = false;
        goto out;
    }

    if (s[i] !=0 && (s[i] == p[j] || p[j] == '.')) {
        if (p[j+1] == '*') {
            result = isMatchCore(s, p, i+1, j, memo) || isMatchCore(s, p, i, j+2, memo);
        } else {
            result = isMatchCore(s, p, i+1, j+1, memo);
        }
    } else if (p[j+1] == '*') {
        result = isMatchCore(s, p, i, j+2, memo);
    } else {
        result = false;
    }
out:
    if (result == false) {
        memo[i][j] = 1;
    }
    return result;
}

bool isMatch(char * s, char * p){
    bool result;
    int sl = strlen(s) + 1;
    int pl = strlen(p) + 1;
    char **memo = malloc(sizeof(char *) * sl);
    for (int i = 0; i < sl; i++) {
        memo[i] = calloc(sizeof(char), pl);
    }
    result = isMatchCore(s, p, 0, 0, memo);
    for (int i = 0; i < sl; i++) {
        free(memo[i]);
    }
    free(memo);
    return result;
}

int main() {
    return isMatch("aaa", "a*a");
}