//DP：rolling array
#define min(x, y) (x < y ? x : y)

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    int prev_row[len2 + 1];
    int cur_row[len2 + 1];
    
    int *prev = prev_row;
    int *cur = cur_row;
    
    for (int j = 0; j <= len2; j++) {
        prev[j] = j;
    }
    
    for (int i = 1; i <= len1; i++) {
        cur[0] = i;
        
        for (int j = 1; j <= len2; j++) {
            if (word1[i-1] == word2[j-1]) {
                cur[j] = prev[j-1];
            } else {
                int del = prev[j] + 1;
                int ins = cur[j-1] + 1;
                int rep = prev[j-1] + 1;
                cur[j] = min(min(del, ins), rep);
            }
        }
        
        int *tmp = prev;
        prev = cur;
        cur = tmp;
    }
    
    return prev[len2];
}
