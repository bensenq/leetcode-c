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
    int ans;
    int len = strlen(beginWord);
    char **relation = malloc(sizeof(char*)*(wordListSize+1));
    for (int i = 0; i <= wordListSize; i++) {
        relation[i] = malloc(sizeof(char) * wordListSize);
    }
    int *distance = calloc(sizeof(int), wordListSize);  //0 means not covered

    for (int i = 0; i < wordListSize-1; i++) {
        for (int j = i+1; j < wordListSize; j++) {
            if (oneDiff(wordList[i], wordList[j])) {
                relation[i][j] = 1;
                relation[j][i] = 1;
            } else {
                relation[i][j] = 0;
                relation[j][i] = 0;
            }
        }
    }
    for (int i = 0; i < wordListSize; i++) {
        if (oneDiff(beginWord, wordList[i])) {
            relation[wordListSize][i] = 1;
        } else {
            relation[wordListSize][i] = 0;
        }
    }
    
    //char *visited = calloc(1, wordListSize);
    int newReach;
    int currentDepth = 1;
    distance[endIndex] = 1;
    while(true) {
        newReach = 0;
        for (int i = 0; i < wordListSize; i++) {
            if (distance[i] == currentDepth) {
                if (relation[wordListSize][i] == 1) {
                    ans = currentDepth + 1;
                    goto found;
                }
                for(int j = 0; j < wordListSize; j++) {
                    if(distance[j] == 0 && relation[i][j] == 1) {
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
    // cleanup
    for (int i = 0; i <= wordListSize; i++) {
        free(relation[i]);
    }
    free(relation);

    return ans;
}

int main() {
    char *begin = "qa";
    char *end = "sq";
    char *wordlist[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    return ladderLength(begin, end, wordlist, sizeof(wordlist)/sizeof(wordlist[0]));
}