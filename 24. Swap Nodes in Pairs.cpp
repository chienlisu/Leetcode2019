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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *even = head, *even_head = even;
        ListNode *odd = head->next, *odd_head = odd;
        ListNode *temp;
        ListNode *tail = NULL;
        
        // 1->3 (even), 2->4 (odd), 5(tail)
        while (odd->next != NULL && odd->next->next != NULL)
        {
            even->next = odd->next;
            odd->next = even->next->next;
            
            even = even->next;
            odd = odd->next;
        }
        if (odd->next != NULL)
        {
            tail = odd->next;
            even->next = NULL;
            odd->next = NULL;
        }    
        
        //2->1->4  ->3 ->5
        odd = odd_head;
        even = even_head;
        ListNode *temp_odd, *temp_even;
        
        while(odd->next != NULL)
        {
            temp_odd = odd->next;
            temp_even = even->next;
            odd->next = even;
            even->next = temp_odd;
            
            odd = temp_odd;
            even = temp_even;
        }
        odd->next = even;
        even->next = tail;
        
        return odd_head;
    }
};
