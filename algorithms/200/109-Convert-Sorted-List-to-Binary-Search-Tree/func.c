/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *sortedArrayToBST(int *array, int size) {
    if (size == 0) return 0;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    int mid = size / 2;
    root->val = array[mid];
    root->left = sortedArrayToBST(array, mid);
    root->right = sortedArrayToBST(array+mid+1, size-mid-1);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int len = 128;
    int *array = malloc(sizeof(int) * len);
    int size = 0;
    struct ListNode *p = head;
    while(p != 0) {
        array[size++] = p->val;
        if (size == len) {
            len *= 2;
            array = realloc(array, sizeof(int) * len);
        }
        p = p->next;
    }
    struct ListNode *root = sortedArrayToBST(array, size);
    free(array);
    return root;
}