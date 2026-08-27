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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* next;
        ListNode* t= head;
        int pos = 1;

        ListNode* before = NULL;
        while(t != NULL)
        {
            if(pos < left)
            {
                before = t;
                t = t->next;
                pos++;
                continue;
            }
            ListNode* curr = t;
            ListNode* prev = NULL;
            int time = right - left + 1;
            while(time--)
            {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            t->next = curr;
             if (before != NULL) {
                before->next = prev;
            } else {
                head = prev; // The reversed portion now starts the list
            }
            break;
        }
        return head;
    }
};