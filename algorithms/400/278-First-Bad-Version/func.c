// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start = 0, end = n - 1, value, mid;
    while(start != end) {
        mid = ((long long)start + end) / 2;
        value = isBadVersion(mid+1);
        if (value) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start + 1;
}