int subsetXORSum(int* nums, int numsSize) {
    int sum = 0;
    int numSubSets = 1 << numsSize;
    int size = 1;
    int xor[numSubSets];
    xor[0] = 0;     //subset empty
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < size; j++) {
            xor[size+j] = nums[i] ^ xor[j];
            sum += xor[size+j];
        }
        size *= 2;
    }
    return sum;
}