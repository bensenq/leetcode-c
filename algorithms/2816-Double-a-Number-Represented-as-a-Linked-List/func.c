/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseIt(struct ListNode *head) {
    struct ListNode *prev = head;
    struct ListNode *next = head->next;
    struct ListNode *tmp;
    head->next = 0;
    while(next) {
        tmp = next->next;
        next->next = prev;
        prev = next;
        next = tmp;
    }
    return prev;
} 
struct ListNode* doubleIt(struct ListNode* head){
    struct ListNode *p = reverseIt(head);
    int val, carry = 0;
    head = p;
    while (p != NULL) {
        val = p->val * 2 + carry;
        p->val = val % 10;
        carry = val / 10;
        p = p->next;
    }
    head = reverseIt(head);
    if (carry) {
        p = malloc(sizeof(struct ListNode));
        p->val = 1;
        p->next = head;
        head = p;
    }
    return head;
}