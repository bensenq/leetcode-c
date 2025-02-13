/* 
 * 1. XOR all the numbers in the array. Since XOR of two identical numbers is 0, pairs will cancel out, leaving us with the XOR of the two unique numbers.
 * 2. Find any set bit in the result from step 1. This bit is different between the two unique numbers.
 * 3. Divide all numbers into two groups based on whether they have this bit set or not. Each group will contain one of the unique numbers and some pairs.
 * 4. XOR all numbers within each group separately. The result from each group will be one of the unique numbers.
 * 
 * Magic of find rightmost set bit: A & (-A)
 */

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int xor = 0;
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }

    // Find a set bit (rightmost set bit)
    int diffBit = xor & (-((unsigned int)xor));
    int *result = malloc(sizeof(int)*2);
    *returnSize = 2;
    result[0] = 0;
    result[1] = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & diffBit) {
            result[0] ^= nums[i];
        } else {
            result[1] ^= nums[i];
        }
    }
    return result;
}