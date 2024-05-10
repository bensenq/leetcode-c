// divide and conquer
// ref: https://leetcode.com/problems/merge-k-sorted-lists/solutions/10919/python-easy-to-understand-divide-and-conquer-solution/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode *left, struct ListNode *right) {
    struct ListNode guard;
    struct ListNode *head = &guard;
    guard.next = 0;
    while(left != 0 && right != 0) {
        if (left->val < right->val) {
            head->next = left;
            left = left->next;
        } else {
            head->next = right;
            right = right->next;
        }
        head = head->next;
    }
    if (left != 0) {
        head->next = left;
    } else {
        head->next = right;
    }
    return guard.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0)
        return 0;
    if (listsSize == 1)
        return lists[0];
    
    int mid = listsSize / 2;
    struct ListNode *left = mergeKLists(lists, mid);
    struct ListNode *right = mergeKLists(&lists[mid], listsSize-mid);
    return merge(left, right);
}