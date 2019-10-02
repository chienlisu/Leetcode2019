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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode* after = head;
        bool is_new = true;
        
        while (after != NULL)
        {
            while (after->next != NULL && after->val == after->next->val)
            {
                is_new = false;
                after = after->next;
            }
            if (is_new)
            {
                curr->next = after;
                curr = curr->next;
                after = after->next;
            }
            else
            {
                is_new = true;
                after = after->next;
            }
        }
        
        if (is_new)
        {
            curr->next = after;    
        }
        else
        {
            curr->next = NULL;
        }
        return dummy->next;
    }
};
