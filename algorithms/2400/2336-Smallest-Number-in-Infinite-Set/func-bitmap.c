typedef struct {
    unsigned long long *bitmap;
} SmallestInfiniteSet;

#define SIZE 1000

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet *obj = malloc(sizeof(SmallestInfiniteSet));
    obj->bitmap = calloc(sizeof(unsigned long long), (SIZE/64 + 1));   /* 0 is present, 1 is absent */
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int i, j, val;
    for (i = 0; i < (SIZE/64 + 1); i++) {
        if (obj->bitmap[i] != ~0ULL) break;
    }

    for (j = 0; j < 64; j++) {
        if ((obj->bitmap[i] & (1ULL << j)) == 0) break;
    }

    val = i * 64 + j + 1;
    obj->bitmap[i] |= 1ULL << j;
    return val;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    int index = (num - 1) / 64, off = (num - 1) % 64;
    obj->bitmap[index] &= ~(1ULL << off);
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj->bitmap);
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 
 * smallestInfiniteSetAddBack(obj, num);
 
 * smallestInfiniteSetFree(obj);
*/