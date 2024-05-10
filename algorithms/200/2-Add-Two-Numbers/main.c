/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode *t1, *t2, *t3, *result;
        int v1, v2; 
        int carrier = 0;
        t1 = l1;
        t2 = l2;
        result = NULL;
        while (t1 != NULL || t2 != NULL) {
                struct ListNode *t = malloc(sizeof(struct ListNode));
                v1 = t1 ? t1->val : 0;
                v2 = t2 ? t2->val : 0;
                t->val = carrier + v1 + v2;
		t->next = NULL;
                if (t->val > 9) {
                        t->val = t->val - 10;
                        carrier = 1;
                } else {
                        carrier = 0;
                }
                if (result == NULL) {
                        result = t;
                        t3 = result;
                } else {
                        t3->next = t;
                        t3 = t;
                }
                if (t1) t1 = t1->next;
                if (t2) t2 = t2->next;
        }

	if (carrier == 1) {
		struct ListNode *t = malloc(sizeof(struct ListNode));
		t->val = 1;
		t->next = NULL;
		t3->next = t;
	}
	
        return result;
}
