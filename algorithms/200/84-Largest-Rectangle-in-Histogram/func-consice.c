/* same idea, but more consice */

int largestRectangleArea(int* heights, int heightsSize) {
    int n = heightsSize;
    int lindex[n], rindex[n];
    int max = 0;
    lindex[0] = -1;

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && heights[j] >= heights[i]) {
            j = lindex[j];
        }
        lindex[i] = j;
    }


    rindex[n-1] = n;
    for (int i = n-2; i >= 0; i--) {
        int j = i + 1;
        while (j < n && heights[j] >= heights[i]) {
            j = rindex[j];
        }
        rindex[i] = j;
    }

    for (int i = 0; i < n; i++) {
        int s = (rindex[i] - lindex[i] - 1) * heights[i];
        if (s > max) max = s;
    }

    return max;
}