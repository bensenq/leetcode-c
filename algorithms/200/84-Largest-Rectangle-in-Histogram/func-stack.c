//stack based solution 
//ref: https://leetcode.com/problems/largest-rectangle-in-histogram/solutions/28900/short-and-clean-o-n-stack-based-java-solution/

int largestRectangleArea(int* heights, int heightsSize) {
    int len = heightsSize;
    int stack[len+1], top = 0;
    int max = 0, s;
    for (int i = 0; i <= len; i++){
        int h = (i == len ? 0 : heights[i]);
        // if (s.isEmpty() || h >= heights[s.peek()]) {
        if (top == 0 || h >= heights[stack[top-1]]) {
            // s.push(i);
            stack[top] = i;
            top++;
        } else {
            // int tp = s.pop();
            int tp = stack[top-1];
            top--;
            // maxArea = max(maxArea, heights[tp] * (s.isEmpty() ? i : i - 1 - s.peek()));
            s = heights[tp] * (top == 0 ? i : i - 1 - stack[top-1]);
            if (s > max) max = s;
            i--;    // reprocess current index
        }
    }
    return max;
}