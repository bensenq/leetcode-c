/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode *tmp, *prev;
    struct ListNode guard;
    int count, middle, i;
    guard.next = head;
    count = 0;
    tmp = &guard;
    while(tmp->next != 0) {
        count++;
        tmp = tmp->next;
    }
    middle = count/2;
    i = 0;
    tmp = head;
    prev = &guard;
    while (i < middle) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
    prev->next = tmp->next;
    free(tmp);
    return guard.next; 
}