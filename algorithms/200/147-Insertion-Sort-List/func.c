/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct ListNode ListNode;
 // Function to create a new node
 ListNode* createNode(int val) {
     ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
     newNode->val = val;
     newNode->next = NULL;
     return newNode;
 }
 
 // Function to perform insertion sort on a linked list
 ListNode* insertionSortList(ListNode* head) {
     if (!head || !head->next) {
         return head; // List is already sorted if it has 0 or 1 element
     }
 
     // Dummy node to simplify edge cases
     ListNode* dummy = createNode(0);
     dummy->next = head;
 
     ListNode* unsorted = head->next; // Pointer to the unsorted portion
     head->next = NULL; // Initial sorted portion has only the first node
 
     while (unsorted) {
         ListNode* current = unsorted;
         unsorted = unsorted->next; // Move the unsorted pointer forward
 
         // Find the correct position to insert the current node
         ListNode* prev = dummy;
         while (prev->next && prev->next->val < current->val) {
             prev = prev->next;
         }
 
         // Insert the current node into the sorted portion
         current->next = prev->next;
         prev->next = current;
     }
 
     // The sorted list starts from dummy->next
     ListNode* sortedHead = dummy->next;
     free(dummy); // Free the dummy node
     return sortedHead;
 }