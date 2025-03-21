/* min heap */

// Define a structure for the hash map
typedef struct {
    int key;           // Rank
    int value;         // Count of mechanics with this rank
    UT_hash_handle hh; // Makes this structure hashable
} RankCount;

// Define a structure for the heap elements
typedef struct {
    long time;         // Time for the next repair
    int rank;          // Mechanic's rank
    long n;            // Cars repaired by this mechanic
    int mechCount;     // Number of mechanics with this rank
} HeapElement;

// Min-heap implementation
typedef struct {
    HeapElement* elements;
    int capacity;
    int size;
} MinHeap;

// Function to create a new min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->elements = (HeapElement*)malloc(capacity * sizeof(HeapElement));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Function to swap two heap elements
void swap(HeapElement* a, HeapElement* b) {
    HeapElement temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property
void heapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->elements[left].time < heap->elements[smallest].time)
        smallest = left;

    if (right < heap->size && heap->elements[right].time < heap->elements[smallest].time)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->elements[idx], &heap->elements[smallest]);
        heapify(heap, smallest);
    }
}

// Function to insert an element into the heap
void insertHeap(MinHeap* heap, HeapElement element) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }

    heap->elements[heap->size] = element;
    int i = heap->size;
    heap->size++;

    while (i != 0 && heap->elements[(i - 1) / 2].time > heap->elements[i].time) {
        swap(&heap->elements[i], &heap->elements[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the heap
HeapElement extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        HeapElement empty = {0, 0, 0, 0};
        return empty;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->elements[0];
    }

    HeapElement root = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to repair cars
long long repairCars(int* ranks, int ranksSize, int cars) {
    // Count the frequency of each rank using uthash
    RankCount* countMap = NULL;
    for (int i = 0; i < ranksSize; i++) {
        RankCount* s;
        HASH_FIND_INT(countMap, &ranks[i], s);
        if (s == NULL) {
            s = (RankCount*)malloc(sizeof(RankCount));
            s->key = ranks[i];
            s->value = 1;
            HASH_ADD_INT(countMap, key, s);
        } else {
            s->value++;
        }
    }

    // Create a min-heap
    MinHeap* minHeap = createMinHeap(ranksSize);

    // Add initial entries to the heap
    RankCount* current, *tmp;
    HASH_ITER(hh, countMap, current, tmp) {
        HeapElement element = {current->key, current->key, 1, current->value};
        insertHeap(minHeap, element);
    }

    long long time = 0;
    // Process until all cars are repaired
    while (cars > 0) {
        // Pop the mechanic with the smallest current repair time
        HeapElement currentElement = extractMin(minHeap);
        time = currentElement.time;
        int rank = currentElement.rank;
        long long n = currentElement.n;
        int mechCount = currentElement.mechCount;

        // Deduct the number of cars repaired by this mechanic group
        cars -= mechCount;

        // Increment the number of cars repaired by this mechanic
        n += 1;

        // Push the updated repair time back into the heap
        HeapElement newElement = {rank * n * n, rank, n, mechCount};
        insertHeap(minHeap, newElement);
    }

    // Free the hash map
    HASH_ITER(hh, countMap, current, tmp) {
        HASH_DEL(countMap, current);
        free(current);
    }

    // Free the heap
    free(minHeap->elements);
    free(minHeap);

    return time;
}