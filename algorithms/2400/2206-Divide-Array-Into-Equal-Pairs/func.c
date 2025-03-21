bool divideArray(int* nums, int numsSize) {
    int hash[501] = {0};
    int ret = false;
    for (int i = 0; i < numsSize; i++)
        hash[nums[i]]++;
    int count = 0;
    for (int i = 1; i < 501; i++) {
        if (hash[i] != 0) {
            if (hash[i] % 2 != 0) {
                break;
            }
            count += hash[i];
            if (count == numsSize) {
                ret = true;
                break;
            } 
        }
    }
    return ret;
}