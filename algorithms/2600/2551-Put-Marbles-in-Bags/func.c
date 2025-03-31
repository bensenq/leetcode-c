//Editorial: Sorting

int compare (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

long long putMarbles(int* weights, int weightsSize, int k) {
// We collect and sort the value of all n - 1 pairs.
int n = weightsSize;
int *pairWeights = malloc(sizeof(int) * (n - 1));
for (int i = 0; i < n - 1; i++) {
    pairWeights[i] = weights[i] + weights[i + 1];
}

qsort(pairWeights, n - 1, sizeof(int), compare);
// Get the difference between the largest k - 1 values and the
// smallest k - 1 values.
long long answer = 0;
for (int i = 0; i < k - 1; ++i) {
    answer += pairWeights[n - 2 - i] - pairWeights[i];
}

return answer;
}