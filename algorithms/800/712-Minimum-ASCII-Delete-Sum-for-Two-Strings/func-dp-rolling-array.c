//DP: rolling-array
#define min(x, y) ((x) < (y) ? (x) : (y))

int minimumDeleteSum(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int prev_row[len2 + 1];
    int cur_row[len2 + 1];

    int *prev = prev_row;
    int *cur = cur_row;
    prev[0] = 0;
    for (int j = 1; j <= len2; j++) {
        prev[j] = prev[j-1] + s2[j-1];
    }

    for (int i = 1; i <= len1; i++) {
        cur[0] = prev[0] + s1[i-1];

        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                cur[j] = prev[j-1];
            } else {
                cur[j] = min(min(prev[j]+s1[i-1], cur[j-1]+s2[j-1]), prev[j-1]+s1[i-1]+s2[j-1]);
            }
        }

        int *tmp = prev;
        prev = cur;
        cur = tmp;
    }

    return prev[len2];
}
