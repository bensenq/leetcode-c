/* classic Greedy problem: Interval Scheduling */
// ref https://leetcode.com/problems/non-overlapping-intervals/solutions/91713/java-least-is-most

int compare (const void * a, const void * b){
	return (*(int**)a)[1] - (*(int**)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* 
intervalsColSize) {
    if (intervalsSize == 0) return 0;
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int end = intervals[0][1];
    int count = 1;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= end) {
            end = intervals[i][1];
            count++;
        }        
    }

    return intervalsSize - count;
}