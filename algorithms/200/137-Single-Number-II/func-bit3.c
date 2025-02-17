int singleNumber(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int j = 0; j < numsSize; j++) {
            sum += (nums[j] >> i) & 1;
        }
        sum %= 3;
        // ans |= (1 << i) * sum;
        ans |= ((unsigned int)1 << i) * sum;    // escape "left shift of 1 by 31 places cannot be represented in type 'int'" error
    }

    return ans;
}