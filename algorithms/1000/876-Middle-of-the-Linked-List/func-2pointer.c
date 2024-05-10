/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow, *fast;
    slow = fast = head;
    while(fast->next != 0) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != 0)
            fast = fast->next;
    }
    return slow;
}