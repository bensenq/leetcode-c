int findUnsortedSubarray(int* nums, int numsSize){
    int left, right, rtmp;
    int i, j, found = 0;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = numsSize - 1; j > i; j--) {
            if (nums[i] > nums[j]) {
                left = i;
                rtmp = j;
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }
    
    if (!found)
        return 0;
    
    found = 0;
    right = rtmp;
    for (i = numsSize-1; i > rtmp; i--) {
        for (j = left + 1; j < i; j++) {
            if (nums[i] < nums[j]) {
                found = 1;
                break;
            }
        }
        if(found)
            break;
    }
    
    if(found) {
        right = i;
    }
    
    return (right - left + 1);
}