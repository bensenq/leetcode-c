/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* del;
    node->val = node->next->val;
    del = node->next;
    node->next = node->next->next;
    free(del);
}