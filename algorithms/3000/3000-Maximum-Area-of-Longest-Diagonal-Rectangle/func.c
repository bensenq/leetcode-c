int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int maxAera = 0;
    int maxSquareSum = 0;
    int delta;
    for (int i = 0; i < dimensionsSize; i++) {
        int squareSum = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
        if (squareSum > maxSquareSum) {
            maxSquareSum = squareSum;
            maxAera = dimensions[i][0] * dimensions[i][1];
            delta = dimensions[i][0] > dimensions[i][1] ? dimensions[i][0] : dimensions[i][1];
        } else if (squareSum == maxSquareSum) {
            int d = dimensions[i][0] > dimensions[i][1] ? dimensions[i][0] : dimensions[i][1];
            if (d < delta) {
                maxAera = dimensions[i][0] * dimensions[i][1];
                delta = d;
            }
        }
    }
    return maxAera;
}
