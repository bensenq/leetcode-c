int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int n = arr2Size;
    qsort(arr2, n, sizeof(int), cmp_int);
    int min = arr2[0], max=arr2[n-1];
    int ans = 0;
    for(int i = 0; i < arr1Size; i++) {
        int v = arr1[i];

        if(v <= min) {
            if(min - v > d) ans++;
            continue;
        }
        if(v >= max) {
            if(v - max > d) ans++;
            continue;
        }
        int l = 0, r = n - 1, m, f;
        while(l <= r) {
            m = l + (r - l) / 2;
            if(arr2[m] > v) {
                r = m - 1;
            } else {
                f = m;
                l = m + 1;
            }
        }
        if(v - arr2[f] > d && arr2[f+1] - v > d) ans++;
    }
    return ans;
}
