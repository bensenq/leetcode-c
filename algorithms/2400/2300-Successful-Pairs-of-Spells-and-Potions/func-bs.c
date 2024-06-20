/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int value;
    int index;
} IndexedValue;

int compare_indexed(const void *a, const void *b) {
    IndexedValue *iv_a = (IndexedValue *)a;
    IndexedValue *iv_b = (IndexedValue *)b;
    return iv_a->value - iv_b->value; // ascending
}

int compare(const void *a, const void *b) {
    return *((int *)a) - *((int *)b); // ascending
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    IndexedValue *indexed_spells = malloc(sizeof(IndexedValue) * spellsSize);
    int *result = malloc(sizeof(int) * spellsSize);
    for (int i = 0; i < spellsSize; i++) {
        indexed_spells[i].value = spells[i];
        indexed_spells[i].index = i;
    }

    qsort(indexed_spells, spellsSize, sizeof(IndexedValue), compare_indexed);
    qsort(potions, potionsSize, sizeof(int), compare);
    int left, right, mid;
    int ans = -1;
    for (int i = 0; i < spellsSize; i++) {
        /* binary search */
        int index = indexed_spells[i].index;
        double target = (double)success/spells[index];
        left = 0, right = ans != -1 ? ans : potionsSize - 1;
        ans = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (potions[mid] >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (ans == -1)
            result[index] = 0;
        else
            result[index] = potionsSize - ans;
    }
    free(indexed_spells);
    *returnSize = spellsSize;
    return result;
}