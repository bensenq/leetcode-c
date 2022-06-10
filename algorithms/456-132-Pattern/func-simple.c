/* 
 * algo: keep tracking the largest (32) pattern from right 
 */

bool find132pattern(int* nums, int numsSize) {
    int stack[numsSize];
    int stackTop = 0;

    int second = INT_MIN;
    for (int i = numsSize-1; i >= 0; i--) {
        if (nums[i] < second)
            return true;
        
        while(stackTop > 0 && nums[i] > stack[stackTop - 1]) {
            second = stack[stackTop-1];
            stackTop--;
        }
        
        if (stackTop == 0 || nums[i] < stack[stackTop - 1])
            stack[stackTop++] = nums[i];
    }
    return false;
}