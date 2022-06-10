bool canJump(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0 && i != (numsSize-1)) {
            int j;
            for (j = i-1; j >= 0; j--) {
                if (nums[j] > (i - j))
                    break;
            }
            if (j >= 0)
                continue;
            else
                return false;
        }
    }
    return true;
}