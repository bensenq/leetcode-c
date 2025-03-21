// line sweep: deference array is the key

#define max(a,b) ((a) > (b) ? (a) : (b))

int minZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int n = numsSize, sum = 0, k = 0;
    int *differenceArray = calloc(sizeof(int), n + 1);
    // Iterate through nums
    for (int index = 0; index < n; index++) {
        // Iterate through queries while current index of nums cannot equal zero
        while (sum + differenceArray[index] < nums[index]) {
            k++;

            // Zero array isn't formed after all queries are processed
            if (k > queriesSize) {
                return -1;
            }
            int left = queries[k - 1][0], right = queries[k - 1][1],
                val = queries[k - 1][2];

            // Process start and end of range
            if (right >= index) {
                differenceArray[max(left, index)] += val;
                differenceArray[right + 1] -= val;
            }
        }
        // Update prefix sum at current index
        sum += differenceArray[index];
    }
    return k;  
}