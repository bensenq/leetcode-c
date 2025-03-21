//priority queue: min heap

/* priority_queue start */

// HNode: low 32-bit for index, high 32-bit for val
#define index(h)    (h & 0xFFFFFFFFUL)
#define value(h)    (h >> 32)
void swap(unsigned long long *H, int a, int b) {
    unsigned long long tmp = H[a];
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
void shiftUp(unsigned long long *H, int i) {
    while (i > 0 && H[i] < H[parent(i)]) {
        // Swap parent and current node
        swap(H, parent(i), i); 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(unsigned long long *H, int *size, int i) {
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
void insert(unsigned long long *H, int* size, unsigned long long k)
{
    *size = *size + 1;
    H[*size] = k;
    // Shift Up to maintain heap property
    // printf("insert %d %d %d\n", i, j, p);
    shiftUp(H, *size);
}
 
// Function to extract the element with maximum priority
unsigned long long extractMax(unsigned long long *H, int *size)
{
    unsigned long long result = H[0];
 
    // Replace the value at the root with the last leaf
    H[0] = H[*size];
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0);
    return result;
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    long long *heap = malloc(sizeof(long long) * candidates * 2);
    int hsize = -1;
    int left = 0, right = costsSize - 1;
    for (; left < candidates; left++) {
        insert(heap, &hsize, (unsigned long long)costs[left] << 32 | left);
    }
    for (; right > costsSize - 1 - candidates; right--) {
        if (right < left) break;
        insert(heap, &hsize, (unsigned long long)costs[right] << 32 | right);
    }
    int i = 0;
    long long total = 0;
    while (i < k) {
        unsigned long long val = extractMax(heap, &hsize);
        int ind = index(val);
        total += value(val);
        costs[ind] = 0; //mark it selected;
        if (hsize + 1 >= candidates) {
            if (ind < left) {
                //advance left
                while(left < costsSize && costs[left] == 0) left++;
                if (left < costsSize && left <= right)
                    insert(heap, &hsize, (unsigned long long)costs[left] << 32 | left);
                left++;
            }
            if (ind > right) {
                //advance right
                while(right >= 0 && costs[right] == 0) right--;
                if (right >= 0 && right >= left)
                    insert(heap, &hsize, (unsigned long long)costs[right] << 32 | right);
                right--;
            }
        }
        i++;
    }
    free(heap);
    return total;
}