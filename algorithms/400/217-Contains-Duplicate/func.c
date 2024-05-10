#define BUCKETS 100000
#define BUCKET_SIZE (2000000000/BUCKETS)

bool containsDuplicate(int* nums, int numsSize){
    char **hashtable = calloc(BUCKETS + 1, sizeof(char *));
    int i = 0;
    bool result = false;
    while(i < numsSize) {
        int hash = (nums[i] + 1000000000) / BUCKET_SIZE;
        int offset = (nums[i] + 1000000000) % BUCKET_SIZE;
        if (hashtable[hash] == 0) {
            hashtable[hash] = calloc(BUCKET_SIZE, 1);
            hashtable[hash][offset] = 1;
        } else {
            if (hashtable[hash][offset] == 0) {
                hashtable[hash][offset] = 1;
            } else {
                result = true;
                break;
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