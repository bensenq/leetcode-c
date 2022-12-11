/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *first, *last, *prev, *next;
    struct ListNode guard;
    int pos = 0;
    guard.next = head;
    first = &guard;
    while(pos < left-1) {
        first = first->next;
        pos++;
    }

    last = first->next;
    prev = last;
    next = last->next;
    pos++;

    while(pos < right) {
        last = next;
        next = next->next;
        last->next = prev;
        prev = last;
        pos++;
    }

    first->next->next = next;
    first->next = last;

    return guard.next;
}