/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int count = 0;
    struct ListNode* p = head;
    while (p) {
        count++;
        p = p->next;
    }

    struct ListNode dummy;
    struct ListNode *nextfirst = head;
    struct ListNode *prevlast = &dummy;
    struct ListNode *curlast = 0;
    while (count >= k) {    //reverse every k-group
        struct ListNode *cur, *next, *tmp;
        curlast = nextfirst;
        cur = nextfirst;
        next = cur->next;
        int i = 1;
        while(i < k) {
            tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
            i++;
        }
        prevlast->next = cur;
        nextfirst = next;
        prevlast = curlast;
        count = count - k;
    }
    prevlast->next = nextfirst;

    return dummy.next;
}