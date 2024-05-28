/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    unsigned long long *hashmap1 = calloc(sizeof(unsigned long long), 2001/64 + 1);
    unsigned long long *hashmap1_uniq = calloc(sizeof(unsigned long long), 2001/64 + 1);
    unsigned long long *hashmap2 = calloc(sizeof(unsigned long long), 2001/64 + 1);
    unsigned long long *hashmap2_uniq = calloc(sizeof(unsigned long long), 2001/64 + 1);
    int **result = malloc(sizeof(int *) * 2);
    *returnColumnSizes = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int index, offset, size;
    /* build hashmap */
    for (int i = 0; i < nums1Size; i++) {
        index = (nums1[i] + 1000) / 64;
        offset = (nums1[i] + 1000) % 64;
        hashmap1[index] |= 1ULL << offset;
        hashmap1_uniq[index] |= 1ULL << offset;
    }
    for (int i = 0; i < nums2Size; i++) {
        index = (nums2[i] + 1000) / 64;
        offset = (nums2[i] + 1000) % 64;
        hashmap2[index] |= 1ULL << offset;
        hashmap2_uniq[index] |= 1ULL << offset;
    }

    size = 0;
    result[0] = malloc(sizeof(int)*nums1Size);
    for (int i = 0; i < nums1Size; i++) {
        index = (nums1[i] + 1000) / 64;
        offset = (nums1[i] + 1000) % 64;
        if ((hashmap1_uniq[index] & 1ULL << offset) != 0) {
            if ((hashmap2[index] & 1ULL << offset) == 0) {
                result[0][size] = nums1[i];
                size++;
                hashmap1_uniq[index] &= ~(1ULL << offset);
            }
        }
    }
    result[0] = realloc(result[0], sizeof(int)*size);
    (*returnColumnSizes)[0] = size;

    size = 0;
    result[1] = malloc(sizeof(int)*nums2Size);
    for (int i = 0; i < nums2Size; i++) {
        index = (nums2[i] + 1000) / 64;
        offset = (nums2[i] + 1000) % 64;
        if ((hashmap2_uniq[index] & 1ULL << offset) != 0) {
            if ((hashmap1[index] & 1ULL << offset) == 0) {
                result[1][size] = nums2[i];
                size++;
                hashmap2_uniq[index] &= ~(1ULL << offset);
            }
        }
    }
    result[1] = realloc(result[1], sizeof(int)*size);
    (*returnColumnSizes)[1] = size;
    free(hashmap1);
    free(hashmap1_uniq);
    free(hashmap2);
    free(hashmap2_uniq);
    return result;
}