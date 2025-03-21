#define MAX_TASKS 26

/* max heap start */
// Define the structure for the max-heap
typedef struct {
    int *elements;   // Array to store heap elements
    int size;        // Current size of the heap
    int capacity;    // Maximum capacity of the heap
} MaxHeap;

// Create a max-heap
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->elements = (int*)malloc((capacity + 1) * sizeof(int)); // 1-based indexing
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up to maintain max-heap property
void heapifyUp(MaxHeap *heap, int index) {
    while (index > 1 && heap->elements[index] > heap->elements[index / 2]) {
        swap(&heap->elements[index], &heap->elements[index / 2]);
        index /= 2;
    }
}

// Heapify down to maintain max-heap property
void heapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= heap->size && heap->elements[left] > heap->elements[largest]) {
        largest = left;
    }
    if (right <= heap->size && heap->elements[right] > heap->elements[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->elements[index], &heap->elements[largest]);
        heapifyDown(heap, largest);
    }
}

// Insert an element into the max-heap
void insert(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        return; // Heap is full
    }
    heap->size++;
    heap->elements[heap->size] = value;
    heapifyUp(heap, heap->size);
}

// Delete and return the maximum element from the max-heap
int deleteMax(MaxHeap *heap) {
    if (heap->size == 0) {
        return -1; // Heap is empty
    }
    int max = heap->elements[1];
    heap->elements[1] = heap->elements[heap->size];
    heap->size--;
    heapifyDown(heap, 1);
    return max;
}

// Get the current size of the max-heap
int size(MaxHeap *heap) {
    return heap->size;
}

// Free the allocated memory for the max-heap
void freeMaxHeap(MaxHeap *heap) {
    free(heap->elements);
    free(heap);
}

/* max heap end */

// Main function to calculate the minimum intervals required
int leastInterval(char* tasks, int tasksSize, int n) {
    // Count the frequency of each task
    int taskCounts[MAX_TASKS] = {0};
    for (int i = 0; i < tasksSize; i++) {
        taskCounts[tasks[i] - 'A']++;
    }

    // Create a max-heap
    MaxHeap *heap = createMaxHeap(MAX_TASKS);
    for (int i = 0; i < MAX_TASKS; i++) {
        if (taskCounts[i] > 0) {
            insert(heap, taskCounts[i]);
        }
    }

    // Initialize a circular cooling queue
    int coolingQueue[MAX_TASKS][2]; // [0] stores remaining task counts, [1] stores cooling time
    int head = 0, tail = 0; // Head and tail pointers for the circular queue
    int coolingQueueSize = 0;

    int time = 0;

    while (size(heap) > 0 || coolingQueueSize > 0) {
        // Check if any task in the cooling queue can be re-added to the max-heap
        if (coolingQueueSize > 0 && coolingQueue[head][1] <= time) {
            insert(heap, coolingQueue[head][0]);
            head = (head + 1) % MAX_TASKS; // Move head pointer in circular manner
            coolingQueueSize--;
        }

        // Schedule a task from the max-heap
        if (size(heap) > 0) {
            int count = deleteMax(heap);
            if (count > 1) {
                coolingQueue[tail][0] = count - 1;
                coolingQueue[tail][1] = time + n + 1;
                tail = (tail + 1) % MAX_TASKS; // Move tail pointer in circular manner
                coolingQueueSize++;
            }
        }

        time++;
    }

    // Free the max-heap
    freeMaxHeap(heap);

    return time;
}