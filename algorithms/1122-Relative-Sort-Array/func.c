int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int i = 0;
    int *arr2Times = calloc(sizeof(int), arr2Size);
    int *result = malloc(sizeof(int) * arr1Size);
    int otherArr[1000];
    int index = 0;
    while (i < arr1Size) {
        int j = 0;
        while (j < arr2Size) {
            if (arr1[i] == arr2[j]) {
                arr2Times[j]++;
                break;
            }
            j++;
        }
        if (j == arr2Size) {
            otherArr[index] = arr1[i];
            index++;
        }
        i++;
    }

    qsort(otherArr, index, sizeof(int), compare);

    i = 0;
    index = 0;
    while (i < arr2Size) {
        int j;
        for (j = 0; j < arr2Times[i]; j++) {
            result[index] = arr2[i];
            index++;
        }
        i++;
    }

    memcpy(&result[index], otherArr, sizeof(int)*(arr1Size-index));

    *returnSize = arr1Size;
    free(arr2Times);
    return result;
}