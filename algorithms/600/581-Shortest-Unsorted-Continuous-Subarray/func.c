int findUnsortedSubarray(int* nums, int numsSize){
    int i;
    int first, last;
    int min, max;

    /* from left to right to find last element to sort*/
    max = nums[0];
    last = -1;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] < max) {
            last = i;
        } else {
            max = nums[i];
        }
    }

    if (last == -1) //not found, no need to continue
        return 0;

    /* from right to left to find first element to sort*/
    min = nums[numsSize - 1];
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i] > min) {
            first = i;
        } else {
            min = nums[i];
        }
    }

    return (last - first + 1);
}