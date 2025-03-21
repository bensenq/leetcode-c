#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// memo[i][j] represents whether s[i:i+j-1] is a palindrome or not
void searchPalindrome(char *s, int len, char **memo) {
    for (int i = 0; i < len; i++) {
        memo[i][0] = 1; //true;
        memo[i][1] = 1; //true;
    }

    for (int j = 2; j <= len; j++) {
        for(int i = 0; i+j <= len; i++) {
            if (s[i] == s[i+j-1] && memo[i+1][j-2] == 1) {
                memo[i][j] = 1;
            }
        }
    }
}

int minCut(char* s) {
    int len = strlen(s);
    char **memo = malloc(sizeof(char*) *len);
    for (int i = 0; i < len; i++) {
        memo[i] = malloc(len+1-i);
        memset(memo[i], 0, len+1-i);
    }
    searchPalindrome(s, len, memo);

    // res[i] represents the minimum cut neededfrom s[0] to s[i]
    int res[len];

    for(int i = 0; i < len; i++) {
        // by default we need i cut from s[0] to s[j]
        int cut = i;
        for(int j = 0; j <= i; j++) {
            if (memo[j][i-j+1]) {
                // if s[j:i] is a palindrome, we don't need any cut
                cut = MIN(cut, j == 0 ? 0 : res[j-1]+1);
            }
        }
        res[i] = cut;
    }

    for (int i = 0; i < len; i++) {
        free(memo[i]);
    }
    free(memo);
    return res[len-1];
}

int main() {
    char *s = "fiefhgdcdcgfeibggchibffahiededbbegegdfibdbfdadfbdbceaadeceeefiheibahgececggaehbdcgebaigfacifhdbecbebfhiefchaaheiichgdbheacfbhfiaffaecicbegdgeiaiccghggdfggbebdaefcagihbdhhigdgbghbahhhdagbdaefeccfiaifffcfehfcdiiieibadcedibbedgfegibefagfccahfcbegdfdhhdgfhgbchiaieehdgdabhidhfeecgfiibediiafacagigbhchcdhbaigdcedggehhgdhedaebchcafcdehcffdiagcafcgiidhdhedgaaegdchibhdaegdfdaiiidcihifbfidechicighbcbgibadbabieaafgeagfhebfaheaeeibagdfhadifafghbfihehgcgggffgbfccgafigieadfehieafaehaggeeaaaehggffccddchibegfhdfafhadgeieggiigacbfgcagigbhbhefcadafhafdiegahbhccidbeeagcgebehheebfaechceefdiafgeddhdfcadfdafbhiifigcbddahbabbeedidhaieagheihhgffbfbiacgdaifbedaegbhigghfeiahcdieghhdabdggfcgbafgibiifdeefcbegcfcdihaeacihgdchihdadifeifdgecbchgdgdcifedacfddhhbcagaicbebbiadgbddcbagbafeadhddaeebdgdebafabghcabdhdgieiahggddigefddccfccibifgbfcdccghgceigdfdbghdihechfabhbacifgbiiiihcgifhdbhfcaiefhccibebcahidachfabicbdabibiachahggffiibbgchbidfbbhfcicfafgcagaaadbacddfiigdiiffhbbehaaacidggfbhgeaghigihggfcdcidbfccahhgaffiibbhidhdacacdfebedbiacaidaachegffaiiegeabfdgdcgdacfcfhdcbfiaaifgfaciacfghagceaaebhhibbieehhcbiggabefbeigcbhbcidbfhfcgdddgdffghidbbbfbdhcgabaagddcebaechbbiegeiggbabdhgghciheabdibefdfghbfbfebidhicdhbeghebeddgfdfhefebiiebdchifbcbahaddhbfafbbcebiigadhgcfbebgbebhfddgdeehhgdegaeedfadegfeihcgeefbbagbbacbgggciehdhiggcgaaicceeaefgcehfhfdciaghcbbgdihbhecfbgffefhgiefgeiggcebgaacefidghdfdhiabgibchdicdehahbibeddegfciaeaffgbefbbeihbafbagagedgbdadfdggfeaebaidchgdbcifhahgfdcehbahhdggcdggceiabhhafghegfdiegbcadgaecdcdddfhicabdfhbdiiceiegiedecdifhbhhfhgdbhibbdgafhgdcheefdhifgddchadbdggiidhbhegbdfdidhhfbehibiaacdfbiagcbheabaaebfeaeafbgigiefeaeheabifgcfibiddadicheahgbfhbhddaheghddceedigddhchecaghdegigbegcbfgbggdgbbigegffhcfcbbebdchffhddbfhhfgegggibhafiebcfgeaeehgdgbccbfghagfdbdfcbcigbigaccecfehcffahiafgabfcaefbghccieehhhiighcfeabffggfchfdgcfhadgidabdceediefdccceidcfbfiiaidechhbhdccccaigeegcaicabbifigcghcefaafaefd";
    printf("%d, %d\n",strlen(s), minCut(s));
    return 0;
}