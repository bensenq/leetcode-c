int convert(char *dayStr) {
    int monthdays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int mouth = atoi(strndup(dayStr, 2));
    int day = atoi(strndup(dayStr+3, 2));
    return monthdays[mouth-1] + day;
}
int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int aA = convert(arriveAlice), lA = convert(leaveAlice);
    int aB = convert(arriveBob), lB = convert(leaveBob);
    int arriveLast = aA > aB ? aA : aB;
    int leaveFirst = lA < lB ? lA : lB;
    return leaveFirst >= arriveLast ? leaveFirst - arriveLast + 1 : 0;
}
