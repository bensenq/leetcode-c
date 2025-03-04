bool checkPowersOfThreeCore(int n, int power) {
    if (n == 0) {
        return true;
    }
    for(int i = power; ;i++) {
        int remain = n - pow(3, i);
        if (remain < 0) break;
        if (checkPowersOfThreeCore(remain, i+1)) return true;

    }
    return false;
}

bool checkPowersOfThree(int n) {
    return checkPowersOfThreeCore(n, 0);
}