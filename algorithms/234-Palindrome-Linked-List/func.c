/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *cur = head;
        while(cur != 0) {
            s.push(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur != 0) {
            if (cur->val != s.top())
                return false;
            cur = cur->next;
            s.pop();
        }
        return true;
    }
};