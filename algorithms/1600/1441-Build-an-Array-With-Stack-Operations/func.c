/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    int maxOps = 2 * n;
    char** result = (char**)malloc(sizeof(char*) * maxOps);
    int idx = 0;

    int j = 0; // 指向 target

    for (int i = 1; i <= n && j < targetSize; i++) {
        // Push
        result[idx] = (char*)malloc(sizeof(char) * 5);
        strcpy(result[idx], "Push");
        idx++;

        if (i == target[j]) {
            // 匹配，保留
            j++;
        } else {
            // 不匹配，Pop
            result[idx] = (char*)malloc(sizeof(char) * 4);
            strcpy(result[idx], "Pop");
            idx++;
        }
    }

    *returnSize = idx;
    return result;    
}
