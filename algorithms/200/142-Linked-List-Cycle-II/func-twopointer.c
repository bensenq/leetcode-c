// Tortoise and Hare algorithm

// Function to detect the start of the cycle in the linked list using two pointers
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Phase 1: Finding the intersection point of the two runners
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            // Phase 2: Finding the entrance to the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Both pointers meet at the entrance of the cycle
        }
    }

    return NULL; // No cycle
}