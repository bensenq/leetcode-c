//derived from 95 - Unique Binary Search Trees II
int numTrees(int n){
    int i;
    int sizes[n+1];
    sizes[0] = 1;
    sizes[1] = 1;
    i = 2;
    while (i <= n) {
        int left, right;
        sizes[i] = 0;
        for (left = i - 1; left > (i - 1 - left); left--) {
            sizes[i] += sizes[left] * sizes[i - 1 - left] * 2;
        }
        if (left == (i - 1 - left)) {
            sizes[i] += sizes[left] * sizes[left];
        }
        i++;
    }

    return sizes[n];
}