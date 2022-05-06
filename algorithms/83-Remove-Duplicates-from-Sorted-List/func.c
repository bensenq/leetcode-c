/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode tmp;
    struct ListNode *prev = &tmp;
    struct ListNode *next;
    prev->next = head;
    prev->val = 101;
    next = head;
    while(next != 0) {
        if (prev->val != next->val) {
            prev->next = next;
            prev = next;
            next = next->next;
        } else {
            next = next->next;
        }
    }
    prev->next = next;
    return head;
}