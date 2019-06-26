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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        
        if (head->next == NULL && n == 1) // linklist only one element
            return NULL;
        
        while (n >= 1)
        {
            fast = fast->next;
            --n;
        }
        
        if(fast == NULL) // delete the head of linklist
            return head->next; 
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};
