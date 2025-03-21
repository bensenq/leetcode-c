/* priority_queue start */
void swap(int *H, int a, int b) {
    int tmp = H[a];
    H[a] = H[b];
    H[b] = tmp;
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
void shiftUp(int *H, int i) {
    while (i > 0 && H[i] < H[parent(i)]) {
        // Swap parent and current node
        swap(H, parent(i), i); 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(int *H, int *size, int i) {
    int maxIndex = i;
    // Left Child
    int l = leftChild(i);  
    if (l <= *size && H[l] < H[i]) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size && H[r] < H[maxIndex]) {
        maxIndex = r;
    }
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H, i, maxIndex);
        shiftDown(H, size, maxIndex);
    }
}
 
// Function to insert a new element in the Binary Heap
void insert(int *H, int* size, int k)
{
    /* check if it is exist */
    for (int i = 0; i <= *size; i++) {
        if (H[i] == k) return;  //exist
    }
    *size = *size + 1;
    // printf("%d, %d\n", *size, k);
    H[*size] = k;
    // Shift Up to maintain heap property
    // printf("insert %d %d %d\n", i, j, p);
    shiftUp(H, *size);
}
 
// Function to extract the element with maximum priority
int extractMax(int *H, int *size)
{
    int result = H[0];
 
    // Replace the value at the root with the last leaf
    H[0] = H[*size];
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0);
    return result;
}


typedef struct {
    int *heap;
    int size;
    unsigned long long *bitmap;
} SmallestInfiniteSet;


SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet *obj = malloc(sizeof(SmallestInfiniteSet));
    obj->heap = malloc(sizeof(int)*1000);
    obj->bitmap = calloc(sizeof(unsigned long long), (1000/64 + 1));   /* 1 is absent */
    for (int i = 0; i < 1000; i++) {
        obj->heap[i] = i + 1;
    }
    obj->size = 999;
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int val = extractMax(obj->heap, &(obj->size));
    int index = val / 64, off = val % 64;
    obj->bitmap[index] |= 1ULL << off;  // mark 1 for absent
    return val;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    int index = num / 64, off = num % 64;
    if (obj->bitmap[index] & 1ULL << off)
        insert(obj->heap, &(obj->size), num);
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj->heap);
    free(obj->bitmap);
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 
 * smallestInfiniteSetAddBack(obj, num);
 
 * smallestInfiniteSetFree(obj);
*/