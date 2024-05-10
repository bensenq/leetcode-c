char * removeDuplicates(char * s, int k){
    int i, j;
    int len = strlen(s);
    char *result = malloc(len+1);
    int *repeat = calloc(sizeof(int), len);
    int top;
    i = 0; j = 0;
    top = 0;
    while(i < len) {
        result[j] = s[i];
        if (j != 0 && result[j] == result[j-1]) {
            if (++repeat[top-1] == k) {
                top--;
                j = j - k;
            }
        } else {
            repeat[top] = 1;
            top++;
        }
        i++;j++;
    }
    free(repeat);
    result[j] = 0;
    return result;
}

int main() {
    char *s = "deeedbbcccbdaa";
    removeDuplicates(s, 3);
}