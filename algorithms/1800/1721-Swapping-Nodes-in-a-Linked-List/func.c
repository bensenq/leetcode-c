/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapNodes(struct ListNode* head, int k){
    int distance = k - 1;
    int i, j;
    struct ListNode *prev1, *fast, *slow;
    struct ListNode *prev2, *tmp;
    struct ListNode guard;
    guard.next = head;
    prev1 = prev2 = &guard;
    slow = head;
    fast = head;
    i = 0;
    j = 1;
    while (fast->next != 0) {
        if (i == distance)
            break;
        fast = fast->next;
        i++;
        if (j != k) {
            prev2 = prev2->next;
            j++;
        }
    }
    
    while (fast->next != 0) {
        prev1 = slow;
        slow = slow->next;
        fast = fast->next;
        if (j != k) {
            prev2 = prev2->next;
            j++;
        }
    }
    
    if (prev1->next != prev2->next) {
        tmp = prev1->next;
        prev1->next = prev2->next;
        prev2->next = tmp;
        tmp = prev1->next->next;
        prev1->next->next =prev2->next->next;
        prev2->next->next = tmp;
    }
    
    return guard.next;
}