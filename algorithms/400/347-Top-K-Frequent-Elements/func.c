/* uthash and priority queue(max heap) */

/* uthash structure */
struct my_struct {
    int id;            /* key */
    int freq;           /* frequency */
    UT_hash_handle hh;  /* makes this structure hashable */
};

// C code to implement priority-queue using array implementation of binary heap

typedef union {
    struct {
        int id;
        int freq;
    };
    unsigned long long data;
} Node;

/* priority_queue start */
void swap(Node *H, int a, int b) {
    unsigned long long tmp = H[a].data;
    H[a].data = H[b].data;
    H[b].data = tmp;
}

// Function to return the index of the parent node of a given node
int parent(int i) {
    return (i - 1) / 2;
}
 
// Function to return the index of the left child of the given node
int leftChild(int i) {
    return ((2 * i) + 1);
}
 
// Function to return the index of the right child of the given node
int rightChild(int i) {
    return ((2 * i) + 2);
}
 
// Function to shift up the node in order to maintain the heap property
void shiftUp(Node *H, int i) {
    while (i > 0 && H[i].freq > H[parent(i)].freq) {
        // Swap parent and current node
        swap(H, parent(i), i); 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(Node *H, int *size, int i) {
    int maxIndex = i;
    // Left Child
    int l = leftChild(i);  
    if (l <= *size && H[l].freq > H[i].freq) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size && H[r].freq > H[maxIndex].freq) {
        maxIndex = r;
    }
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H, i, maxIndex);
        shiftDown(H, size, maxIndex);
    }
}
 
// Function to insert a new element in the Binary Heap
void insert(Node *H, int* size, int id, int freq)
{
    *size = *size + 1;
    H[*size].id = id;    
    H[*size].freq = freq;
    // Shift Up to maintain heap property
    // printf("insert %d %d %d\n", i, j, p);
    shiftUp(H, *size);
}
 
// Function to extract the element with maximum priority
unsigned long long extractMax(Node *H, int *size)
{
    unsigned long long result = H[0].data;
 
    // Replace the value at the root with the last leaf
    H[0].data = H[*size].data;
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0);
    return result;
}
/* priority_queue end */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *result = malloc(sizeof(int) * k);
    struct my_struct *users = NULL;    /* important! initialize to NULL */
    struct my_struct *s, *tmp;
    for(int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(users, &nums[i], s);
        if (s == NULL) {
            s = (struct my_struct *)malloc(sizeof *s);
            s->id = nums[i];
            s->freq = 1;
            HASH_ADD_INT(users, id, s);  /* id: name of key field */
        } else {
            s->freq += 1;
        }
    }
    // HASH_ITER(hh, users, s, tmp) {
    //     printf("user id %d: freq %d\n", s->id, s->freq);
    //     /* ... it is safe to delete and free s here */
    // }
    unsigned int *heap = malloc(sizeof(unsigned long long) * numsSize);
    int heapSize = -1;
    HASH_ITER(hh, users, s, tmp) {
        // printf("user id %d: freq %d\n", s->id, s->freq);
        /* ... it is safe to delete and free s here */
        HASH_DEL(users,s);
        insert(heap, &heapSize, s->id, s->freq);
        free(s);
    }   

    Node top;
    int i = 0;
    while(i < k) {
        top.data = extractMax(heap, &heapSize);
        result[i++] = top.id;
    }
    free(heap);
    *returnSize = k;
    return result;
}