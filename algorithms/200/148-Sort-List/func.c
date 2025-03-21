/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
// Comparator function for qsort
int compare(const void* a, const void* b) {
    ListNode* nodeA = *(ListNode**)a;
    ListNode* nodeB = *(ListNode**)b;
    return nodeA->val - nodeB->val;
}

// Function to sort the linked list
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head; // List is already sorted if it has 0 or 1 element
    }

    // Step 1: Collect all nodes into an array
    ListNode* current = head;
    int count = 0;
    while (current) {
        count++;
        current = current->next;
    }

    ListNode** nodes = (ListNode**)malloc(count * sizeof(ListNode*));
    current = head;
    for (int i = 0; i < count; i++) {
        nodes[i] = current;
        current = current->next;
    }

    // Step 2: Sort the array of nodes using qsort
    qsort(nodes, count, sizeof(ListNode*), compare);

    // Step 3: Reconstruct the linked list from the sorted array
    for (int i = 0; i < count - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[count - 1]->next = NULL; // Set the next pointer of the last node to NULL

    ListNode* result = nodes[0];
    // Step 4: Free the allocated array
    free(nodes);

    // Return the head of the sorted list
    return result;
}