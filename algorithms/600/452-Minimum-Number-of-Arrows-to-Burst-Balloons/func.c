// same idea with 435

int compare (const void * a, const void * b){
    const int **ca = a;
    const int **cb = b;
	if ((*ca)[0] < (*cb)[0]) return -1;
    else if ((*ca)[0] > (*cb)[0]) return 1;
    else return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), compare);
    int end = points[0][1];
    int count = 1;

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] <= end) {
            if (points[i][1] < end)
                end = points[i][1];
        } else {
            count++;
            end = points[i][1];
        }        
    }
    return count;
}