#define MAX_CAPACITY 10001

// Define a doubly linked list node
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// Define the LRUCache structure
typedef struct {
    int capacity;
    int size;         // Current size of the linked list
    Node* nodeHead;   // Pointer to the head of the doubly linked list
    Node* nodeTail;   // Pointer to the tail of the doubly linked list
    Node* hashTable[MAX_CAPACITY];
} LRUCache;

// Create a new node
Node* createNode(int key, int value) {
    Node* node = (Node*)calloc(1, sizeof(Node));
    if (!node) return NULL;
    node->key = key;
    node->value = value;
    return node;
}

// Initialize LRUCache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)calloc(1, sizeof(LRUCache));
    if (!cache) return NULL;
    cache->capacity = capacity;
    return cache;
}

// Move a node to the end of the list
void moveToTail(LRUCache* obj, Node* node) {
    if (node == obj->nodeTail) return;
    if (node->prev) {
        node->prev->next = node->next; // Update the previous node's next pointer
    }
    if (node->next) {
        node->next->prev = node->prev; // Update the next node's previous pointer
    }
    if (node == obj->nodeHead) {
        obj->nodeHead = node->next; // Update the head pointer if necessary
    }
    if (obj->nodeTail) {
        obj->nodeTail->next = node; // Add the node to the end of the list
        node->prev = obj->nodeTail;
        node->next = NULL;
        obj->nodeTail = node;
    } else {
        obj->nodeTail = node;
        obj->nodeHead = node;
    }
}

// Get the value of the key
int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->hashTable[key] != NULL) {
        Node* node = obj->hashTable[key];
        // Move the node to the end of the list
        moveToTail(obj, node);
        return node->value;
    }
    return -1;
}

// Insert or update the key-value pair
void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->hashTable[key] != NULL) {
        // Key already exists, update the value and move the node to the end
        Node* node = obj->hashTable[key];
        node->value = value;
        moveToTail(obj, node);
    } else {
        // Key does not exist, insert a new node
        if (obj->size >= obj->capacity) {
            // Exceeds capacity, remove the least recently used item
            Node* toRemove = obj->nodeHead;
            if (toRemove) {
                obj->hashTable[toRemove->key] = NULL;
                obj->nodeHead = toRemove->next;
                if (obj->nodeHead) {
                    obj->nodeHead->prev = NULL;
                }
                if (toRemove == obj->nodeTail) {
                    obj->nodeTail = NULL;
                }
                free(toRemove);
                obj->size--;
            }
        }
        Node* newNode = createNode(key, value);
        if (!newNode) return;
        obj->hashTable[key] = newNode;
        moveToTail(obj, newNode);
        obj->size++;
    }
}

// Free the memory allocated for LRUCache
void lRUCacheFree(LRUCache* obj) {
    Node* current = obj->nodeHead;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(obj);
}