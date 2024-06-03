/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    int i = 0;
    struct ListNode dummyEven, dummyOdd;
    struct ListNode *even = &dummyEven, *odd = &dummyOdd;
    even->next = 0;
    odd->next = 0;
    while(head != 0) {
        if (i % 2 == 0) {
            odd->next = head;
            odd = odd->next;
        } else {
            even->next = head;
            even = even->next; 
        }
        head = head->next;
        i++;
    }
    odd->next = dummyEven.next;
    even->next = 0;
    return dummyOdd.next;
}