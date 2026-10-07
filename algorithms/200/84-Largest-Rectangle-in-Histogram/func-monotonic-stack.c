// monotonic stack
int largestRectangleArea(int* heights, int heightsSize) {
    int n = heightsSize;
    int *left = malloc(sizeof(int) * n);
    int *right = malloc(sizeof(int) * n);
    int *stack = malloc(sizeof(int) * n);
    int top = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while(top != -1 && heights[i] < heights[stack[top]]) {
            right[stack[top]] = i;
            top--;
        }
        top++;
        stack[top] = i;
    }

    while(top != -1) {  //right end
        right[stack[top]] = n;
        top--;
    }

    for(int i = n - 1; i >= 0; i--) {
        while(top != -1 && heights[i] < heights[stack[top]]) {
            left[stack[top]] = i;
            top--;
        }
        top++;
        stack[top] = i;
    }

    while(top != -1) {  //left end
        left[stack[top]] = -1;
        top--;
    }

    for(int i = 0; i < n; i++) {
        // printf("%d %d\n", right[i], left[i]);
        int area = (right[i] - left[i] - 1) * heights[i];
        if(area > ans) ans = area;
    }
    free(left);free(right);free(stack);
    return ans;
}
