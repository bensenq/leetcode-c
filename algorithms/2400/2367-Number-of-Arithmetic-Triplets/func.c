int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int count = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            if (nums[j] - nums[i] == diff) {
                for (int k = j + 1; k < numsSize; k++) {
                    if (nums[k] - nums[j] == diff) {
                        count++;
                        break;
                    }
                }
            }
        }
    }

    return count;
}