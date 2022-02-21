/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int distance = n - 1;
    int i;
    struct ListNode *prev, *fast, *slow;
    struct ListNode guard;
    guard.next = head;
    prev = &guard;
    slow = head;
    fast = head;
    i = 0;
    while (fast->next != 0) {
        if (i == distance)
            break;
        fast = fast->next;
        i++;
    }
    
    if (i != distance)
        return head;
    while (fast->next != 0) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    free(slow);   //this is slow
    return guard.next;
}