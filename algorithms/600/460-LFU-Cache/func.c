// tow-level double linked list

#define MAX_CAPACITY 100001

// Define a doubly linked list node for the LRU list
typedef struct Node {
    int key;
    int value;
    int freq;
    struct Node* prev;
    struct Node* next;
    struct FreqNode* parentFreqNode; // Pointer to the parent frequency node
} Node;

// Define a doubly linked list node for the frequency list
typedef struct FreqNode {
    int freq;
    struct FreqNode* prev;
    struct FreqNode* next;
    Node* lruHead; // Head of the LRU list for this frequency
    Node* lruTail; // Tail of the LRU list for this frequency
} FreqNode;

// Define the LFUCache structure
typedef struct {
    int capacity;
    int size;         // Current size of the cache
    Node* hashTable[MAX_CAPACITY];
    FreqNode* freqListHead; // Head of the frequency list
} LFUCache;

// Create a new node for the LRU list
Node* createNode(int key, int value) {
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->key = key;
    node->value = value;
    node->freq = 1;
    return node;
}

// Create a new frequency node
FreqNode* createFreqNode(int freq) {
    FreqNode* freqNode = (FreqNode*)calloc(1, sizeof(FreqNode));
    freqNode->freq = freq;
    return freqNode;
}

// Initialize LFUCache
LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* cache = (LFUCache*)calloc(1, sizeof(LFUCache));
    cache->capacity = capacity;
    cache->size = 0;
    return cache;
}

// Remove a node from its current LRU list
void removeNodeFromLRU(Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    if (node == node->parentFreqNode->lruHead) {
        node->parentFreqNode->lruHead = node->next;
    }
    if (node == node->parentFreqNode->lruTail) {
        node->parentFreqNode->lruTail = node->prev;
    }
}

// Add a node to the end of the LRU list
void addToLRUEnd(FreqNode* freqNode, Node* node) {
    node->parentFreqNode = freqNode;
    node->prev = freqNode->lruTail;
    node->next = NULL;
    if (freqNode->lruTail) {
        freqNode->lruTail->next = node;
    } else {
        freqNode->lruHead = node;
    }
    freqNode->lruTail = node;
}

// Insert a frequency node after another frequency node
void insertFreqNodeAfter(FreqNode* existingFreqNode, FreqNode* newFreqNode) {
    newFreqNode->prev = existingFreqNode;
    newFreqNode->next = existingFreqNode->next;
    if (existingFreqNode->next) {
        existingFreqNode->next->prev = newFreqNode;
    }
    existingFreqNode->next = newFreqNode;
}

// Remove a frequency node from the frequency list and free it
void removeFreqNode(LFUCache* obj, FreqNode* freqNode) {
    if (freqNode->prev) {
        freqNode->prev->next = freqNode->next;
    }
    if (freqNode->next) {
        freqNode->next->prev = freqNode->prev;
    }
    if (freqNode == obj->freqListHead) {
        obj->freqListHead = freqNode->next;
    }
    free(freqNode);
}

// Increment the frequency of a node
void incrementFreq(LFUCache* obj, Node* node) {
    FreqNode* currentFreqNode = node->parentFreqNode;
    FreqNode* nextFreqNode = currentFreqNode->next;

    // Remove the node from its current LRU list
    removeNodeFromLRU(node);

    // If the next frequency node does not exist or has a higher frequency, create a new one
    if (!nextFreqNode || nextFreqNode->freq > currentFreqNode->freq + 1) {
        nextFreqNode = createFreqNode(currentFreqNode->freq + 1);
        insertFreqNodeAfter(currentFreqNode, nextFreqNode);
    }

    // Update the node's frequency and add it to the new LRU list
    node->freq++;
    addToLRUEnd(nextFreqNode, node);

    // If the current frequency node becomes empty, remove it
    if (!currentFreqNode->lruHead && !currentFreqNode->lruTail) {
        removeFreqNode(obj, currentFreqNode);
    }
}

// Get the value of the key
int lFUCacheGet(LFUCache* obj, int key) {
    if (obj->hashTable[key] != NULL) {
        Node* node = obj->hashTable[key];
        // Increment the frequency of the node
        incrementFreq(obj, node);
        return node->value;
    }
    return -1;
}

// Insert or update the key-value pair
void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj->hashTable[key] != NULL) {
        // Key already exists, update the value and increment the frequency
        Node* node = obj->hashTable[key];
        node->value = value;
        incrementFreq(obj, node);
    } else {
        // Key does not exist, insert a new node
        if (obj->size == obj->capacity) {
            // Exceeds capacity, remove the least frequently used item
            FreqNode* minFreqNode = obj->freqListHead;
            Node* toRemove = minFreqNode->lruHead;
            obj->hashTable[toRemove->key] = NULL;
            removeNodeFromLRU(toRemove);
            free(toRemove);
            obj->size--;

            // If the minimum frequency node becomes empty, remove it
            if (!minFreqNode->lruHead && !minFreqNode->lruTail) {
                removeFreqNode(obj, minFreqNode);
            }
        }
        Node* newNode = createNode(key, value);
        obj->hashTable[key] = newNode;

        // Add the new node to the frequency list with frequency 1
        FreqNode* freqOneNode = obj->freqListHead;
        if (!freqOneNode || freqOneNode->freq != 1) {
            freqOneNode = createFreqNode(1);
            freqOneNode->next = obj->freqListHead;
            if (obj->freqListHead) {
                obj->freqListHead->prev = freqOneNode;
            }
            obj->freqListHead = freqOneNode;
        }

        addToLRUEnd(freqOneNode, newNode);
        obj->size++;
    }
}

// Free the memory allocated for LFUCache
void lFUCacheFree(LFUCache* obj) {
    FreqNode* currentFreqNode = obj->freqListHead;
    while (currentFreqNode) {
        Node* currentNode = currentFreqNode->lruHead;
        while (currentNode) {
            Node* nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        }
        FreqNode* nextFreqNode = currentFreqNode->next;
        free(currentFreqNode);
        currentFreqNode = nextFreqNode;
    }
    free(obj);
}