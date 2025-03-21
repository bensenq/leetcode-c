/* DP solution */
//ref: https://leetcode.com/problems/maximal-rectangle/solutions/29054/share-my-dp-solution/

// left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row
// right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row
// height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';
// height(i,j) = 0, if matrix[i][j]=='0'

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int maxA = 0;
    int left[n], right[n], height[n];
    for (int i = 0; i < n; i++) {
        left[i] = 0; right[i] = n - 1; height[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int cur_left = 0, cur_right = n - 1;
        for(int j = 0; j < n; j++) { // compute height
            if(matrix[i][j] == '1') height[j]++; 
            else height[j] = 0;
        }
        for(int j = 0; j < n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j] = max(left[j], cur_left);
            else { left[j] = 0; cur_left = j + 1;}
        }
        for(int j = n - 1; j >= 0; j--) { // compute right (from right to left)
            if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
            else { right[j] = n - 1; cur_right = j - 1; }    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j = 0; j < n; j++)
            maxA = max(maxA, (right[j] - left[j] + 1) * height[j]);         
    }
    return maxA;
}