// ref with little opt: https://leetcode.com/problems/insert-interval/discuss/21669/Easy-and-clean-O(n)-C%2B%2B-solution

// First, put all intervals that are to the left of the inserted interval.
// Second, merge all intervals that intersect with the inserted interval.
// Finally, put all intervals that are to the right of the inserted interval.

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **result = malloc((sizeof(int *) * (intervalsSize + 1)));
    int start, end, old, i, s = 0;
    *returnColumnSizes = malloc((sizeof(int) * (intervalsSize + 1)));
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[s] = malloc(sizeof(int) * 2);
        result[s][0] = intervals[i][0]; result[s][1] = intervals[i][1];
        (*returnColumnSizes)[s] = 2;
        s++; i++;
    }

    old = i;
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        i++;
    }
    if (old != i) {
        start = MIN(intervals[old][0], newInterval[0]);
        end = MAX(intervals[i-1][1], newInterval[1]);
    } else {
        start = newInterval[0];
        end = newInterval[1];
    }
    result[s] = malloc(sizeof(int) * 2);
    result[s][0] = start; result[s][1] = end;
    (*returnColumnSizes)[s] = 2;
    s++; 

    while (i < intervalsSize) {
        result[s] = malloc(sizeof(int) * 2);
        result[s][0] = intervals[i][0]; result[s][1] = intervals[i][1];
        (*returnColumnSizes)[s] = 2;
        s++; i++;
    }

    *returnSize = s;
    result = realloc(result, sizeof(int *) * s);
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * s);

    return result;
}