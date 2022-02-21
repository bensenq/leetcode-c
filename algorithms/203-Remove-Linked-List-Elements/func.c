/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *tmp, *prev;
    struct ListNode guard;  //use a guard node for generalize head process
    guard.next = head; 
    for (tmp = head, prev = &guard; tmp != 0; tmp = tmp->next) {
        if (tmp->val == val) {
            prev->next = tmp->next;
        } else {
            prev = tmp;
        }
    }
    return guard.next;
}