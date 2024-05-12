//Binary Search
//https://leetcode.com/problems/k-th-smallest-prime-fraction/solutions/862410/c-binary-search-short-and-easy-faster-than-99/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    int n = arrSize;
    double l = 0, r = 1.0;
    //p and q are used for storing the indices of max fraction
    int total, p, q;
    while(l < r){
        double m = (l + r)/2;
        //max_f is used to store the maximum fraction less than mid (which might be the result)
        double max_f = 0.0;
        total = 0, p = 0, q = 0;
        int j = 1;
        for(int i = 0; i < n - 1; i++){
        //if this fraction is greater than mid , move denominator rightwards to find a smaller mid
            while(j < n && arr[i] > m * arr[j])
                j++;
                //j elements are greater than mid in this row , n-j are smaller , add them to result
            total += (n - j);
            if(j == n)  //no need to goon (all below is larger)
                break;
            //cast to double speedily
            double f = (double)arr[i] / arr[j];
            //update max fraction for this mid
            if (f > max_f) {
                p = i;
                q = j;
                max_f = f;
            }
        }
        if (total == k)
            break;
        //there are too many fractions less than mid=> mid is too big => make mid smaller and try
        else if (total > k)
            r = m;
        else
            l = m;
    }
    result[0] = arr[p];
    result[1] = arr[q];
    *returnSize = 2;
    return result;
}