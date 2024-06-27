int largestRectangleArea(int* heights, int heightsSize) {
    int n = heightsSize;
    int lindex[n], rindex[n];
    int max = 0;
    lindex[0] = 0;

    /* get longest value index larger than current index of left */
    for (int i = 1; i < n; i++) {
        if (heights[i] == heights[i-1]) {
            lindex[i] = lindex[i-1];
        } else if (heights[i] > heights[i-1]) {
            lindex[i] = i;
        } else {
            int last = lindex[i-1];
            for (int j = lindex[i-1]; j >= 0; j--) {
                if (heights[j] < heights[i]) break;
                else last = j;
            }
            lindex[i] = last;
        }
    }
    
    /* get longest value index larger than current index of right */
    rindex[n-1] = n-1;
    for (int i = n - 2; i >= 0; i--) {
        if (heights[i] == heights[i+1]) {
            rindex[i] = rindex[i+1];
        } else if (heights[i] > heights[i+1]) {
            rindex[i] = i;
        } else {
            int last = rindex[i+1];
            for (int j = rindex[i+1]; j < n; j++) {
                if (heights[j] < heights[i]) break;
                else last = j;
            }
            rindex[i] = last;
        }
    }

    for (int i = 0; i < n; i++) {
        int s = (rindex[i] - lindex[i] +  + 1) * heights[i];
        if (s > max) max = s;
    }

    return max;
}