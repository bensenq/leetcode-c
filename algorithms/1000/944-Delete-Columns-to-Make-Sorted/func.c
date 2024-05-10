int minDeletionSize(char ** strs, int strsSize){
    int i = 0;
    int del = 0;
    if (strsSize == 0) return 0;
    for(i = 0; strs[0][i] != 0; ++i) {
        int j = 1;
        while (j < strsSize) {
            if (strs[j][i] < strs[j-1][i]) {
                del++;
                break;
            }
            j++;
        }
    }
    return del;
}