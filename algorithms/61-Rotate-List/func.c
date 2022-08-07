/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    int len;
    int i;
    struct ListNode *last, *tmp, *prev;
    if (head == 0) return 0;
    len = 1;
    last = head;
    while (last->next != 0) { 
        len++;
        last = last->next;
    }

    if (len == 1 || k % len == 0)   //no need to rotate
        return head;

    k = (len - k % len);
    i = 0;
    tmp = head;
    while(i < k) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
    prev->next = 0;     //new last
    last->next = head;  
    head = tmp;
    return head;
}