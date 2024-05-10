/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode *slow, *fast, *prev;
    struct ListNode guard;
    guard.next = head;
    slow = fast = head;
    prev = &guard;
    while(fast->next != 0) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast->next != 0) fast = fast->next;
    }
    prev->next = slow->next;
    free(slow);
    return guard.next; 
}