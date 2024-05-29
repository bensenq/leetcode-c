/* simulation */

/* 0 not over; 1 for R win; -1 for D win */
int playRound(char* senate, int i) {
    char enemy;
    int j = i + 1;
    if (senate[j] == 0) j = 0;  /* wrap */
    if (senate[i] == 'R') enemy = 'D';
    else enemy = 'R';
    while (j != i) {
        if (senate[j] == enemy) {
            senate[j] = '-'; /* ban */
            break;
        }
        j++;
        if (senate[j] == 0) j = 0;  /* wrap */
    } 
    if (j == i) {
        if (enemy == 'D') return 1;
        else return -1;
    } else return 0;
}
char* predictPartyVictory(char* senate) {
    int i, j;
    int rc = 0, dc = 0;
    int result;
    i = 0;
    while(true) {
        if (senate[i] != '-') {
            result = playRound(senate, i);
            if (result != 0) break;
        }
        i++;
        if (senate[i] == 0) i = 0;  /* wrapping */
    }
    if (result == 1) return "Radiant";
    else return "Dire";
}