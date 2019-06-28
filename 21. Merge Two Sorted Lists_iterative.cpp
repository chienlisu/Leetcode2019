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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode *lfst, *lsnd, *lhead;
        if(l1->val > l2->val)
        {
            lfst=l2;
            lsnd=l1;
        }
        else
        {
            lfst=l1;
            lsnd=l2;
        }
        lhead = lfst;
               
        ListNode* lfst_prev = NULL;
        while(lsnd != NULL)
        {            
            if(lfst == NULL)
            {
                lfst_prev->next = lsnd;
                break;
            }            
            else if(lsnd->val >= lfst->val)
            {
                lfst_prev = lfst;
                lfst = lfst->next;
            }
            else
            {
                ListNode *temp = lsnd->next;
                lfst_prev->next = lsnd;
                lsnd->next = lfst;
                lfst_prev = lsnd;
                lsnd = temp;
            }
        }
        
        return lhead;
    }
};
