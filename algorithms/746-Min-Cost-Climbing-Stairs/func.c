#define UNMEMOED    -1

int minCostClimbingStairsCore(int* cost, int costSize, int start, int* memo) {
    if (start == costSize || start == costSize - 1)
        return 0;
    
    if (start >= 0 && memo[start] != UNMEMOED)
        return memo[start];
    
    int step1Cost = cost[start] + minCostClimbingStairsCore(cost, costSize, start+1, memo);
    int step2Cost = cost[start+1] + minCostClimbingStairsCore(cost, costSize, start+2, memo);
    int costRet = step1Cost < step2Cost ? step1Cost : step2Cost;
    memo[start] = costRet;
    return costRet;

}

int minCostClimbingStairs(int* cost, int costSize){
    int *minCostMemo = malloc(sizeof(int) * costSize);
    int result;
    for (int i = 0; i < costSize; i++)
        minCostMemo[i] = UNMEMOED;
    result = minCostClimbingStairsCore(cost, costSize, 0, minCostMemo);
    free(minCostMemo);
    return result;
}