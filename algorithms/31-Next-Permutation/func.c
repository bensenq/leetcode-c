/* descending array is the last in fix len */
int isDescending(int *nums, int len) {
    int i = 0;
    while (i < len-1) {
        if (nums[i+1] > nums[i])
            return 0;
        i++;
    }
    return 1;
}

void reverse(int *nums, int len) {
    int i = 0, tmp;
    while (i < len/2) {
        tmp = nums[i];
        nums[i] = nums[len-1-i];
        nums[len-1-i] = tmp;
        i++;
    }
}

void nextPermutation2(int *nums, int len) {
    int i;
    int value = nums[0];
    
    /* find smallest element larger than nums[0] */
    for (i = len-1; i > 0; i--) {
        if (nums[i] > value) {
            nums[0] = nums[i];
            nums[i] = value;
            break;
        }
    }
    /* swap for ascending (smallest)*/
    reverse(&nums[1], len-1);
}

void nextPermutation(int* nums, int numsSize){
    int i, len;
    int tmp;
    if (numsSize == 1)
        return;
    
    i = numsSize - 2;
    len = 2;
    while (i >= 0) {
        /* find the shortest non-descending sub-array from the end */
        if (isDescending(&nums[i], len)) {
            i--; len++;
            continue;
        } else {
            nextPermutation2(&nums[i], len);
            break;
        }
    }
    
    /* could not find non-descending sub-array, then round to smallest */
    if (i < 0) {
        reverse(nums, numsSize);
    }
}

int main() {
    int test[3] = {1, 2, 3};
    nextPermutation(test, 3);
    return 0;
}