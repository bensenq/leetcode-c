/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *tmp;
    int count, middle, i;
    count = 0;
    tmp = head;
    while(tmp != 0) {
        count++;
        tmp = tmp->next;
    }
    middle = count / 2;
    
    i = 0;
    tmp = head;
    while (i < middle) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}