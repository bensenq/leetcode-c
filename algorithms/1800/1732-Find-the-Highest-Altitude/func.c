int largestAltitude(int* gain, int gainSize) {
    int max = 0, i = 0, autitude = 0;
    while (i < gainSize) {
        autitude += gain[i];
        if (gain[i] > 0 && autitude > max) {
            max = autitude;
        }
        i++;
    }
    return max;
}