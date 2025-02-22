//bucket sort
// https://leetcode.com/problems/maximum-gap/solutions/50643/bucket-sort-java-solution-with-explanation-o-n-time-and-space/

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    int min = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        } else if (nums[i] < min) {
            min = nums[i];
        }
    }
    int bucketNum = numsSize - 1;
    int gap = (int)ceil((double)(max - min)/bucketNum);
    int *bucketsMin = malloc(sizeof(int) * bucketNum);
    int *bucketsMax = malloc(sizeof(int) * bucketNum);
    for (int i = 0; i < bucketNum; i++) {
        bucketsMin[i] = INT_MAX;
        bucketsMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == min || nums[i] == max) continue;
        int id = (nums[i] - min) / gap;
        if(nums[i] > bucketsMax[id]) bucketsMax[id] = nums[i];
        if(nums[i] < bucketsMin[id]) bucketsMin[id] = nums[i];
    }

    int maxGap =  INT_MIN;
    int previous = min;
    for (int i = 0; i < bucketNum; i++) {
        if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN) continue;
        if (bucketsMin[i] - previous > maxGap) maxGap = bucketsMin[i] - previous;
        previous = bucketsMax[i];
    }
    if (max - previous > maxGap) maxGap = max - previous;
    free(bucketsMin);
    free(bucketsMax);
    return maxGap;
}