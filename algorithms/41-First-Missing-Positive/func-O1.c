//ref: https://leetcode.com/problems/first-missing-positive/solutions/17080/python-o-1-space-o-n-time-solution-with-explanation/

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    while(i < numsSize) {
        if (nums[i] <= 0 || nums[i] > numsSize) {
            nums[i] = 0;
        }
        i++;
    }
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % (numsSize+1) > 0)
            nums[nums[i]%(numsSize+1)-1] += numsSize+1;
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] <= numsSize)
            return i+1;
    }

    return numsSize+1; 
}

int main()
{
    int test[3] = {0,1,2};
    return firstMissingPositive(test, 3);
}