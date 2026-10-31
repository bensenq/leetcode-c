//binary search on answer
int hIndex(int* citations, int citationsSize) {
    int left = 0, right = citationsSize - 1;
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(citations[mid] <= (citationsSize - mid)) {
            if(citations[mid] > ans ) ans = citations[mid];
            left = mid + 1;
        } else {
            if(citationsSize - mid > ans) ans = citationsSize - mid;
            right = mid - 1;
        }
    }
    return ans;
}
