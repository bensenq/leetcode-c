bool uniqueOccurrences(int* arr, int arrSize) {
    unsigned short *count = calloc(sizeof(unsigned short), 2001);
    char *set = calloc(sizeof(char), 2001);
    char *occurrences = calloc(sizeof(char), 1001);
    bool ans = true;
    int index;
    for (int i = 0; i < arrSize; i++) {
        index = arr[i]+1000;
        count[index]++;
        set[index] = 1;
    }

    for (int i = 0; i < arrSize; i++) {
        index = arr[i]+1000;
        if (set[index] == 1) {
            if (occurrences[count[index]] != 0) {
                ans = false;
                break;
            } else {
                occurrences[count[index]] = 1;
                set[index] = 0;
            }
        }
    }
    free(count);
    free(set);
    free(occurrences);
    return ans;
}