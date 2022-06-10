#include <stdbool.h>

#define BUCKETS 100000
#define BUCKET_SIZE (2000000000/BUCKETS)

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int **hashtable = calloc(BUCKETS + 1, sizeof(int *));
    int i = 0;
    bool result = false;
    while(i < numsSize) {
        int hash = (nums[i] + 1000000000) / BUCKET_SIZE;
        int offset = (nums[i] + 1000000000) % BUCKET_SIZE;
        if (hashtable[hash] == 0) {
            hashtable[hash] = calloc(BUCKET_SIZE, sizeof(int));
            hashtable[hash][offset] = i + 1;
        } else {
            if (hashtable[hash][offset] == 0) {
                hashtable[hash][offset] = i + 1;
            } else {
                if ((i + 1 - hashtable[hash][offset]) <= k) {
                    result = true;
                    break;
                } else {
                    hashtable[hash][offset] = i + 1;
                }
            }
        }
        i++;
    }
    
    for(i = 0; i < BUCKETS+1; i++) {
        if (hashtable[i] != 0)
            free(hashtable[i]);
    }
    free(hashtable);
    return result;
}

int main() {
    int t[] = {1, 2, 3, 1};
    containsNearbyDuplicate(t, 4, 3);
    return 0;
}