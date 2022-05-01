int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize){
    int totalAlice = 0, totalBob = 0;
    int i, j, diff;
    int *result = malloc(sizeof(int) * 2);
    qsort(aliceSizes, aliceSizesSize, sizeof(int), compare);
    qsort(bobSizes, bobSizesSize, sizeof(int), compare);
    i = 0;
    while (i < aliceSizesSize) {
        totalAlice += aliceSizes[i];
        i++;
    }
    
    i = 0;
    while (i < bobSizesSize) {
        totalBob += bobSizes[i];
        i++;
    }
    
    diff = (totalAlice - totalBob) / 2;
    i = 0; j = 0;
    while (true) {
        if ((aliceSizes[i] - bobSizes[j]) == diff)
            break;
        
        if ((aliceSizes[i] - bobSizes[j]) < diff) {
            i++;
        } else {
            j++;
        }
    }
    
found:
    result[0] = aliceSizes[i];
    result[1] = bobSizes[j];
    *returnSize = 2;
    return result;
}