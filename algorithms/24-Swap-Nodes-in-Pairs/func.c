/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *first, *second, *prev;
    struct ListNode guard;
    if (head == 0 || head->next == 0)
        return head;
    guard.next = head;
    first = head;
    second = head->next;
    prev = &guard;
    
    do {
        prev->next = second;
        first->next = second->next;
        second->next = first;
        prev = first;
        first = first->next;
        if (first != 0)
            second = first->next;
    } while(first != 0 && second != 0);
    
    return guard.next;
}