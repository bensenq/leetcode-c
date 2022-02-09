bool isPalindrome(int x){
    char digit[10];
    int i, j;
    
    if (x < 0)
        return false;
    
    for (i = 0; i < 10; i++) {
        digit[i] = x % 10;
        x = x / 10;
        if (x == 0)
            break;
    }
    for (j = 0; j <= (i+1)/2; j++) {
        if (digit[j] != digit[i-j])
            return false;
    }
    
    return true;
}
