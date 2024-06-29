/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char **ans = malloc(sizeof(char *) * wordsSize);
    int wordsLen[wordsSize];
    int size = 0, i = 0;
    while (i < wordsSize) {
        wordsLen[i] = strlen(words[i]);
        i++;
    }
    i = 0;
    while (true) {
        int j = i;
        int len = wordsLen[i];
        int charlen = len;
        ans[size] = malloc(maxWidth+1);
        ans[size][maxWidth] = 0;
        while (j < wordsSize - 1 && len <= maxWidth) {
            j++;
            len += wordsLen[j] + 1;
            charlen += wordsLen[j];
        }

        if (len > maxWidth) {
            int gaps = j - 1 - i;
            if (gaps == 0) {                
                strcpy(ans[size], words[i]);
                memset(ans[size]+wordsLen[i], ' ', maxWidth-wordsLen[i]);

            } else {
                charlen -= wordsLen[j];
                int ave = (maxWidth - charlen) / gaps;
                int mod = (maxWidth - charlen) % gaps;
                strcpy(ans[size], words[i]);
                int k = 1, off = wordsLen[i];
                while(k <= gaps) {
                    if (k <= mod) {
                        memset(ans[size]+off, ' ', ave+1);
                        off += ave+1;
                    } else {
                        memset(ans[size]+off, ' ', ave);
                        off += ave;
                    }
                    strcpy(ans[size]+off, words[i+k]);
                    off += wordsLen[i+k];
                    k++;
                }
            }
            size++;
            i = j;
        } else {
            int off = 0;
            while(i < wordsSize - 1) {
                strcpy(ans[size]+off, words[i]);
                off += wordsLen[i];
                ans[size][off++] = ' ';
                i++;
            }
            strcpy(ans[size]+off, words[i]);
            off += wordsLen[i];
            memset(ans[size]+off, ' ', maxWidth-off);
            size++;
            break;
        }
    }
    *returnSize = size;
    ans = realloc(ans, sizeof(char *) * size);
    return ans;
}