/* classic Greedy problem: Interval Scheduling */
// ref https://leetcode.com/problems/non-overlapping-intervals/solutions/91713/java-least-is-most

int compare (const void * a, const void * b){
    const int **ca = a;
    const int **cb = b;
	if ((*ca)[1] < (*cb)[1]) return -1;
    else if ((*ca)[1] > (*cb)[1]) return 1;
    else return 0;
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