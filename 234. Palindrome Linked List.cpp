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
    bool checkPal(ListNode* l1, ListNode* l2)
    {
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return (l1==NULL && l2==NULL);
    }    
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return true;
        
        // get linklist size
        int size =0;
        ListNode* temphead = head;
        while(temphead!=NULL)  
        {
            temphead = temphead->next;
            size++;
        }
        
        //reverse the first half
        int i=0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;
        while (i < size/2)
        {
            temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
            ++i;
        }
        
     
        bool ans;
        if(size%2 == 0)
            ans = checkPal(prev,curr);
        else
            ans = checkPal(prev,curr->next);
        
        return ans;
    }
};
