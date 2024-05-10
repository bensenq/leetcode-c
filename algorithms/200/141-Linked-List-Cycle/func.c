/* O(1) space */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    int count = 0, i;
    struct ListNode *cur = head, *tmp;
    while (cur != 0) {
        count++;
        tmp = head;
        i = 0;
        while (tmp != 0 && i < count - 1) {
            if (cur == tmp) return true;
            tmp = tmp->next;
            i++;
        }
        cur = cur->next;
    }
    return false;
}