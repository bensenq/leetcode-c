// dp solution
int maxAbsoluteSum(int* nums, int numsSize) {
    int max = abs(nums[0]);
    int negtiveAdjMin = 0, positiveAdjMax = 0;
    if (nums[0] < 0) {
        negtiveAdjMin = nums[0];
    } else {
        positiveAdjMax = nums[0];
    }
    int i = 1;
    while(i < numsSize) {
        positiveAdjMax += nums[i];
        negtiveAdjMin += nums[i];
        if(nums[i] > 0) {
            if (positiveAdjMax > max) max = positiveAdjMax;
            if (negtiveAdjMin > 0) negtiveAdjMin = 0; 
        } else if(nums[i] < 0) {
            if (-negtiveAdjMin > max) max = -negtiveAdjMin;
            if (positiveAdjMax < 0) positiveAdjMax = 0; 
        }
        i++;
    }
    return max;
}