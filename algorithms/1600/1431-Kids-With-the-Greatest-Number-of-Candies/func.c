/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *result = malloc(sizeof(bool)*candiesSize);
    int max = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max) max = candies[i];
    }

    for (int i = 0; i < candiesSize; i++) {
        result[i] = ((candies[i] + extraCandies) >= max);
    }
    *returnSize = candiesSize;
    return result;
}