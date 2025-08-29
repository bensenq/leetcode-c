int maximum69Number (int num) {
    int lastSixPos = -1;
    int i = 0;
    int orgNum = num;
    while(num > 0) {
        if (num % 10 == 6) {
            lastSixPos = i;
        }
        num /= 10;
        i++;
    }
    if (lastSixPos != -1) {
        int lastSixWeight = 1;
        for(int i = 0; i < lastSixPos; i++) {
            lastSixWeight *= 10;
        }
        orgNum = orgNum + 3 * lastSixWeight;
    }
    return orgNum;
}
