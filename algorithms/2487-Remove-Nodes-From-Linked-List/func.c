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

struct ListNode* removeNodes(struct ListNode* head) {
    head = reverseIt(head);
    int max = head->val;
    struct ListNode *p = head->next, *prev = head;
    while(p) {
        if (p->val < max) {
            prev->next = p->next;
        } else {
            max = p->val;
            prev = p;
        }
        p = p->next;
    }
    head = reverseIt(head);
    return head;
}