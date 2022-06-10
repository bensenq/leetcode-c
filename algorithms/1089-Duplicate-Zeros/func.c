void duplicateZeros(int* arr, int arrSize){
    int i = 0, j = 0;
    int *temp = calloc(sizeof(int), arrSize);
    while(j < arrSize) {
        if(arr[i] == 0) {
            j = j+2; i++;
        } else
            temp[j++] = arr[i++];
    }
    memcpy(arr, temp, sizeof(int)*arrSize);
    return;
}