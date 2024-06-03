/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur, *prev, *next;
    cur = head; prev = 0;
    while(cur != 0) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    int count = 0, max = 0, pair;
    struct ListNode *first = head, *second = head;
    while (first != 0) {
        count++;
        first = first->next;
    }
    first = head;
    int i = 0;
    while (i < count / 2) {
        i++;
        second = second->next;
    }
    
    second = reverseList(second);
    while (i > 0) {
        pair = first->val + second->val;
        if (pair > max) max = pair;
        first = first->next;
        second = second->next;
        i--;
    }
    return max;
}