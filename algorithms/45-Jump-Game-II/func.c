int jumpCore(int* nums, int numsSize, int start, int *memo){ 
    if (numsSize == 1)
        return 0;
    
    if (nums[0] >= numsSize - 1)
        return 1;

    int min = 10000;
    for (int i = start; i <= nums[0]; i++) {
        if (nums[i] != 0) {
            int ret;
            if (memo[numsSize-i] == 0) 
                ret = jumpCore(&nums[i], numsSize-i, nums[0]-i+1, memo);
            else 
                ret = memo[numsSize-i];
            if (ret < min)
                min = ret;
        }
    }
    
    memo[numsSize] = min+1;
    return min+1;
}

int jump(int *nums, int numsSize) {
    int ret;
    int *memo = calloc(sizeof(int), numsSize+1);
    ret = jumpCore(nums, numsSize, 1, memo);
    free(memo);
    return ret;
}

int main() {
    int t[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    return jump(t, 12);
}