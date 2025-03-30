/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* partitionLabels(char* s, int* returnSize) {
    int last[26];
    int *result = malloc(sizeof(int)*26);
    int size = 0;
    for (int i = 0; i < 26; i++) {
        last[i] = -1;
    }
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--) {
        if (last[s[i] - 'a'] == -1) {
            last[s[i] - 'a'] = i;
        }
    }

    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        if (last[s[i] - 'a'] > end) {
            end = last[s[i] - 'a'];
        }
        if (i == end) {
            result[size] = end - start + 1;
            size++;
            start = i + 1;
        }
    }
    *returnSize = size;
    return result;
}