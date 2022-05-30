int maxProduct(char ** words, int wordsSize){
    int *values = calloc(sizeof(int), wordsSize);
    int *sizes = malloc(sizeof(int) * wordsSize);
    int max = 0;
    for (int i = 0; i < wordsSize; i++) {
        sizes[i] = strlen(words[i]);
        for (int j = 0; j < sizes[i]; j++) {
            values[i] |= 1 <<(words[i][j] - 'a');
        }
    }
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i+1; j < wordsSize; j++) {
            if ((values[i] & values[j]) == 0 && (sizes[i] * sizes[j]) > max)
                max = sizes[i] * sizes[j];
        }
    }
    free(values);
    free(sizes);
    return max;
}