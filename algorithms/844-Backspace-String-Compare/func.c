bool backspaceCompare(char* s, char* t) {
    int lens, lent;
    bool result;
    char * ss = strdup(s);
    char * tt = strdup(t);
    int i = 0, j = 0;
    while (s[i] != 0) {
        if(s[i] == '#') {
            if(j > 0) j--;
        } else {
            ss[j] = s[i];
            j++;
        }
        i++;
    }
    lens = j;

    i = 0, j = 0;
    while (t[i] != 0) {
        if(t[i] == '#') {
            if(j > 0) j--;
        } else {
            tt[j] = t[i];
            j++;
        }
        i++;
    }
    lent = j;

    if(lent != lens) return false;
    result = !strncmp(ss, tt, lens);
    free(ss); free(tt);
    return result;
}

int main() {
    return backspaceCompare("ab#c", "ad#c");
}