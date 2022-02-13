/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *cur;
    struct ListNode *head;
    if (list1 && list2) {
        if (list1->val < list2->val) {
            head = list1;
            cur = list1;
            list1 = list1->next;
        } else {
            head = list2;
            cur = list2;
            list2 = list2->next;
        }
    } else if(list1 && !list2) {
        return list1;
    } else if(!list1 && list2) {
        return list2;
    } else {
        return NULL;
    }
    while (list1 && list2) {
        if(list1->val < list2->val) {
            cur->next = list1;
            cur = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            cur = list2;
            list2 = list2->next;
        }
    }
    if (list1 == 0) {
        cur->next = list2;
    } else
        cur->next = list1;
    
    return head;
}