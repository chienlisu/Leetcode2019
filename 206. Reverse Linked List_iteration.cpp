/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//iteration solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) // special case
            return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* temp;
        
        prev->next = NULL;
        
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
};
