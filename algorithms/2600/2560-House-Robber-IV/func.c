// Editorial: greedy + binary search
int minCapability(int* nums, int numsSize, int k) {
    // Store the maximum nums value in maxReward.
    int minReward = nums[0], maxReward = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxReward)
            maxReward = nums[i];
        else if (nums[i] < minReward)
            minReward = nums[i];
    }
    // Use binary search to find the minimum reward possible.
    while (minReward < maxReward) {
        int midReward = (minReward + maxReward) / 2;
        int possibleThefts = 0;

        for (int i = 0; i < numsSize; i++) {
            if (nums[i] <= midReward) {
                possibleThefts += 1;
                if (possibleThefts == k) break;
                i++;  // Skip the next house to maintain the non-adjacent condition
            }
        }

        if (possibleThefts >= k)
            maxReward = midReward;
        else
            minReward = midReward + 1;
    }

    return minReward;    
}