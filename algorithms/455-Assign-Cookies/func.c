#include <stdbool.h>

int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i = 0, j = 0;
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    while (i < gSize && j < sSize) {
        if (g[i] > s[j]) {
            j++;
        } else {
            i++;j++;
        }
    }
    return i;
}
