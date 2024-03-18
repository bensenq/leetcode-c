#include <stack>
using namespace std;
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
    ListNode* reverseList(ListNode* head) {
        if (head == 0) return 0;
        stack<ListNode *> s;
        ListNode *cur = head;
        while(cur != 0) {
            s.push(cur);
            cur = cur->next;
        }
        head = s.top();
        s.pop();
        cur = head;
        while(!(s.empty())) {
            cur->next = s.top();
            cur = cur->next;
            s.pop();
        }
        cur->next = 0;
        return head;
    }
};