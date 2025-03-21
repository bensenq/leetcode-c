/* BFS */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int inList(char *word, char **list, int size) {
    for (int i = 0; i < size; i++) {
        if(strcmp(word, list[i]) == 0)
            return i;
    }
    return -1;  //not in list
}

bool oneDiff(char *first, char *second) {
    int count = 0, i = 0;
    while(first[i] != 0) {
        if (first[i] != second[i]) {
            count++;
            if (count > 1) break;
        }
        i++;
    }
    if (count == 1) return true;
    else return false;
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int endIndex = inList(endWord, wordList, wordListSize);
    if (endIndex == -1) return 0;
    int ans = 0;
    int len = strlen(beginWord);
    int *distance = calloc(sizeof(int), wordListSize);  //0 means not covered

    int newReach;
    int currentDepth = 1;
    distance[endIndex] = 1;
    while(true) {
        newReach = 0;
        for (int i = 0; i < wordListSize; i++) {
            if (distance[i] == currentDepth) {
                if (oneDiff(beginWord, wordList[i])) {
                    ans = currentDepth + 1;
                    goto found;
                }
                for(int j = 0; j < wordListSize; j++) {
                    if(distance[j] == 0 && oneDiff(wordList[i], wordList[j])) {
                        distance[j] = currentDepth+1;
                        newReach++;
                    }
                }
            }
        }
        if(newReach == 0)break;
        currentDepth++;
    }
found:
    free(distance);
    return ans;
}

int main() {
    char *begin = "qa";
    char *end = "sq";
    char *wordlist[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    return ladderLength(begin, end, wordlist, sizeof(wordlist)/sizeof(wordlist[0]));
}