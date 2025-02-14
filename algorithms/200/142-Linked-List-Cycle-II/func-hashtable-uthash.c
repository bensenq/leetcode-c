// Define hash table item structure with UTHASH macros
typedef struct HashTableItem {
    struct ListNode *key;
    UT_hash_handle hh; // Makes this structure hashable
} HashTableItem;

// Function to detect the start of the cycle in the linked list using UTHASH
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    HashTableItem* table = NULL;
    struct ListNode* current = head;
    struct ListNode* cycleStart = NULL;

    while (current != NULL) {
        // Check if the current node is already in the hash table
        HashTableItem* entry;
        HASH_FIND_PTR(table, &current, entry);

        if (entry == NULL) { // If not found, add it to the hash table
            entry = (HashTableItem*)malloc(sizeof(HashTableItem));
            entry->key = current;
            HASH_ADD_PTR(table, key, entry);
        } else {
            // Found a cycle
            cycleStart = entry->key;
            break;
        }
        current = current->next;
    }

    // Destroy the hash table and free memory
    HashTableItem* curr_entry, *tmp;
    HASH_ITER(hh, table, curr_entry, tmp) {
        HASH_DEL(table, curr_entry);
        free(curr_entry);
    }

    return cycleStart;
}