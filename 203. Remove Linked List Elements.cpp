/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* curr = head;
        
        while (curr != NULL && curr->val == val)
        {
            curr = curr->next;
        }
        
        if (curr == NULL)
        {
            return curr;
        }
        else
        {    
            head = curr;
        }
        
        while (curr->next != NULL)
        {
            if (curr->next->val == val)
            {
                curr->next = curr->next->next;
            }
            else
            {    
                curr = curr->next;
            }
        }
        
        return head;
    }
};
