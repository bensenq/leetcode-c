/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode guard;
    struct ListNode *last, *first, *prev, *next;
    guard.next = head;
    prev = &guard;
    next = head;
    while (next != 0) {
        if (next->val < x) {
            prev = next;
            next = next->next;
        } else {
            break;
        }
    }
    
    last = prev;
    first = next;
    
    
    while (first != 0) {
        prev = first;
        next = prev->next;
        while (next != 0 && next->val < x) {
            prev = next;
            next = next->next;
        }
        
        if (first != prev) { 
            prev->next = last->next;
            last->next = first->next;
            first->next = next;
            last = prev;
            first = next;
        } else {
            first = first->next;
        }
    }
    
    return guard.next;
}