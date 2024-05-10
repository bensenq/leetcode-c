/* BFS Solution */

int jump(int *nums, int numsSize) {
    if (numsSize < 2)
        return 0;
    int end = 0, level = 1;
    int i = 0;
    int max = 0;
    while(i < numsSize) {
        if (nums[i] + i > max) {
            max = i + nums[i];
            if (max >= numsSize-1)
                break;
        }
        i++;
        if (i > end) {
            level++;
            end = max;
            max = 0;
        }
    }
    return level;
}