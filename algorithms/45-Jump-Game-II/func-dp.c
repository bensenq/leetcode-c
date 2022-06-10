#define MIN(X,Y) ((X) < (Y) ?  (X) : (Y))

int jump(int *nums, int numsSize) {
    int jumps[numsSize];
    int i, j;
    for (i = 0; i < numsSize; i++) {
        jumps[i] = 10001;    //Max is 10000 steps
    }
    jumps[0] = 0;                       //initial state
    for (i = 0; i < numsSize; i++) {
        for (j = i+1; j <= i+nums[i] && j < numsSize; j++) {
            jumps[j] = MIN(jumps[j], jumps[i]+1);       // formula
        }
    }
    return jumps[numsSize-1];
}