#define ABS(a) ((a) >= 0 ? (a) : -(a))

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (ABS(arr[i] - arr[j]) > a) continue;
            for (int k = j + 1; k < arrSize; k++) {
                if (ABS(arr[j] - arr[k]) > b) continue;
                if (ABS(arr[i] - arr[k]) <= c) count++;
            }
        }
    }
    return count;
}