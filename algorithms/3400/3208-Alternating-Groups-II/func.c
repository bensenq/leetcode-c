int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    int i = 1;
    int last = colors[0];
    int len = 1;
    int count = 0;
    while(i < colorsSize) {
        if(colors[i] != last) {
            len += 1;
            last = !last;
        } else {
            if (len >= k) count += len - k + 1;
            len = 1;
        }
        i += 1;
    }

    // check rounded
    i = 0;
    int lenBegin = 0;
    while(colors[i] != last && len != colorsSize) {
        len += 1;
        lenBegin += 1;
        last = !last;
        i += 1;
    }

    if (len >= k) {
        if (len == colorsSize && len % 2 == 0) {
            count += len;
        } else {
            int counted = 0;
            if (lenBegin >= k) counted = lenBegin - k + 1;
            count += len - k + 1 - counted;
        }
    }
    return count;
}