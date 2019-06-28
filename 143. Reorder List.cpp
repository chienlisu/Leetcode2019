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
    void reorderList(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return;
        
        // get size
        int size = 0;
        ListNode* cnt = head;
        
        while (cnt != NULL)
        {
            cnt = cnt->next;
            ++size;
        }
        
        // get second half to reverse
        ListNode *first = head, *second = head;
        int i = 0;
        
        while (i < size/2)
        {
            second = second->next;
            ++i;
        }
        
        // get medium if size = odd.
        ListNode *tail = NULL;
        if (size%2)
        {
            tail = second;
            second = second->next;
            tail->next = NULL;
        }
        
        // reverse second half
        ListNode *curr= second;
        ListNode *prev = NULL;
        ListNode *temp;
        
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }
        second = prev;
        
        // reorder
        ListNode *temp_first, *temp_second;
        while (second->next != NULL)
        {
            temp_first = first->next;
            temp_second = second->next;
            first->next = second;
            second->next = temp_first;
            
            first = temp_first;
            second = temp_second;
        }
        first->next = second;
        second->next = tail;
    }
};
