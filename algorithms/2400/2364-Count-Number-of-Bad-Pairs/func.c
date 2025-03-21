typedef struct {
    int key;          // Element in the array
    int count;        // Number of occurrences of the element
    UT_hash_handle hh; // Handle required by uthash
} HashEntry;

long long countBadPairs(int* nums, int numsSize) {
    long long bad = 0;
    HashEntry* hashMap = NULL;
    HashEntry* entry = NULL;
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i] - i;
        HASH_FIND_INT(hashMap, &key, entry); 

        if (entry == NULL) {
            bad += i;
            // If the key does not exist, create a new entry
            entry = (HashEntry*)malloc(sizeof(HashEntry));
            entry->key = key;
            entry->count = 1;
            HASH_ADD_INT(hashMap, key, entry); // Add to hash table
        } else {
            bad += (i - entry->count);
            // If the key exists, increment the count
            entry->count++;
        }
    }

    HashEntry* tmp;
    HASH_ITER(hh, hashMap, entry, tmp) {
        HASH_DEL(hashMap, entry); // Delete from hash table
        free(entry);              // Free memory
    }
    return bad;    
}
