/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode guard;
    struct ListNode *prev, *pprev;
    int prevVal;
    int prevDup = 0;
    guard.val = -101;
    guard.next = head;
    head = &guard;
    prevVal = head->val;
    prev = head;
    while(head->next != 0) {
        head = head->next;
        if (head->val == prevVal) {
            free(prev);
            prevDup = 1;
            prev = head;
        } else {
            if (prevDup) {
                free(prev);
                prevDup = 0;
                pprev->next = head;
            } else {
                pprev = prev; 
            }
            prev = head;
            prevVal = prev->val;
        }
    }

    if (prevDup) {
        free(prev);
        pprev->next = 0;
    }

    return guard.next;
}