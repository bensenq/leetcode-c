int maxNumberOfBalloons(char* text) {
    int i = 0;
    int count[5] = {0, 0, 0, 0, 0};
    int min;
    while (text[i] != 0) {
        switch(text[i]) {
            case 'a': count[0]++; break;
            case 'b': count[1]++; break;
            case 'l': count[2]++; break;
            case 'n': count[3]++; break;
            case 'o': count[4]++; break;
        }
        i++;
    }
    count[2] /= 2;
    count[4] /= 2;
    min = count[0];
    i = 1;
    while (i < 5) {
        if (count[i] < min) min = count[i];
        i++;
    }  
    return min;
}