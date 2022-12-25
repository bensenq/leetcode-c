#include <stdbool.h>

bool isInterleaveInner(char * s1, char * s2, char * s3, char * s1_org, char * s2_org, char *memo, int len1) {
    if (*s1 == 0 && *s2 == 0 && *s3 == 0) return true;
    if (memo[(s2-s2_org)*(len1+1) + (s1-s1_org)] != 0) return false;
    if ((*s1 == *s3) && (isInterleaveInner(s1+1, s2, s3+1, s1_org, s2_org, memo, len1) == true)) return true;
    if ((*s2 == *s3) && (isInterleaveInner(s1, s2+1, s3+1, s1_org, s2_org, memo, len1) == true)) return true;
    memo[(s2-s2_org)*(len1+1) + (s1-s1_org)] = 1;
    return false;    
}

bool isInterleave(char * s1, char * s2, char * s3){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    if ((len1 + len2) != len3) return false;
    char *memo = calloc((len1+1)*(len2+1)*sizeof(char), 1);
    bool ret = isInterleaveInner(s1, s2, s3, s1, s2, memo, len1);
    free(memo);
    return ret;
}

int main(){
    return isInterleave("abababababababababababababababababababababababababababababababababababababababababababababababababbb",
    "babababababababababababababababababababababababababababababababababababababababababababababababaaaba",
    "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb");
}
