char* digitSum(char* s, int k) {
    char *ans = strdup(s);
    int len = strlen(ans), newlen = 0;
    while(len > k) {
        char *temp = malloc(101);
        int i = 0, j = 0, sum = 0;
        while(i <= len) {
            if(j == k || i == len) {
                j = 0;
                sprintf(temp+newlen, "%d", sum);
                newlen = strlen(temp);
                sum = 0;
            }
            sum += ans[i] - '0';
            i++;j++;
        }
        len = newlen;
        newlen = 0;
        free(ans);
        ans = temp;
    }
    return ans;
}
