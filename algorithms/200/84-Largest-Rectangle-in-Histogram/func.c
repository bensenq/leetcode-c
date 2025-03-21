int largestRectangleArea(int* heights, int heightsSize) {
    int n = heightsSize;
    int lindex[n], rindex[n];
    int max = 0;
    lindex[0] = 0;

    for (int i = 1; i < n; i++) {
        if (heights[i] == heights[i-1]) {
            lindex[i] = lindex[i-1];
        } else if (heights[i] > heights[i-1]) {
            lindex[i] = i;
        } else {
            int j = lindex[i-1];
            while (j >= 0 && heights[j] >= heights[i]) {
                lindex[i] = j;
                if (j != lindex[j])
                    j = lindex[j];
                else
                    j--;
            }
            if (j < 0) lindex[i] = 0;
        }
    }


    rindex[n-1] = n-1;
    for (int i = n - 2; i >= 0; i--) {
        if (heights[i] == heights[i+1]) {
            rindex[i] = rindex[i+1];
        } else if (heights[i] > heights[i+1]) {
            rindex[i] = i;
        } else {
            int j = rindex[i+1];
            while (j < n && heights[j] >= heights[i]) {
                rindex[i] = j;
                if (j != rindex[j])
                    j = rindex[j];
                else
                    j++;
            }
            if (j == n) rindex[i] = n - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int s = (rindex[i] - lindex[i] + 1) * heights[i];
        if (s > max) max = s;
    }

    return max;
}