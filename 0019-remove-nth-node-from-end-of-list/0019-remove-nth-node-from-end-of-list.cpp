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
             ListNode* removeNthFromEnd(ListNode* head, int n) {

                     int count = 0;
                             ListNode* temp = head;

                                     // Count total nodes
                                             while(temp != NULL) {
                                                         count++;
                                                                     temp = temp->next;
                                                                             }

                                                                                     // If first node needs to be deleted
                                                                                             if(count == n) {
                                                                                                         ListNode* del = head;
                                                                                                                     head = head->next;
                                                                                                                                 delete del;
                                                                                                                                             return head;
                                                                                                                                                     }

                                                                                                                                                             int pos = count - n;
                                                                                                                                                                     temp = head;

                                                                                                                                                                             // Move to node before the one to delete
                                                                                                                                                                                     for(int i = 1; i < pos; i++) {
                                                                                                                                                                                                 temp = temp->next;
                                                                                                                                                                                                         }

                                                                                                                                                                                                                 ListNode* del = temp->next;
                                                                                                                                                                                                                         temp->next = temp->next->next;
                                                                                                                                                                                                                                 delete del;

                                                                                                                                                                                                                                         return head;
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                             };