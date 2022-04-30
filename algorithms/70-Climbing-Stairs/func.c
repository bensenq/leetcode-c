int memo[46];

int climbStairs(int n){
    int result;
    if (memo[n] != 0)
        return memo[n];
        
    if (n == 0) {
        result = 1;
    } else if (n == -1) {
        result = 0;
    } else {
        if (memo[n-1] != 0)
            result = memo[n-1];
        else
            result = climbStairs(n-1);
        
        if (n > 1) {
            if (memo[n-2] != 0)
                result += memo[n-2];
            else
                result += climbStairs(n-2);
        }
    }
    memo[n] = result;
    return result;
}