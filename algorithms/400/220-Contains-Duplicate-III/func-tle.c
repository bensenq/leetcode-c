
#include <stdbool.h>
#define ABS(x) ((x) >=0 ? (x) : -(x))

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    int i = 0;
    while (i < numsSize-1) {
        for (int j = 1; j <= k && i+j < numsSize; j++) {
            if (ABS((long)nums[i]-(long)nums[i+j]) <= t)
                return true;
        }
        i++;
    }
    return false;
}

int main() {
    int nums[] = {1,5,9,1,5,9};
    return containsNearbyAlmostDuplicate(nums, 6, 3, 2);
}