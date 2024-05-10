bool canConstruct(char* ransomNote, char* magazine) {
    int count[26] = {0};
    int i = 0;
    while(magazine[i] != 0) {
        count[magazine[i] - 'a']++;
        i++;
    }
    i = 0;
    while(ransomNote[i] != 0) {
        if(count[ransomNote[i] - 'a'] > 0) {
            count[ransomNote[i] - 'a']--;
        } else {
            return  false;
        }
        i++;
    }

    return true;
}