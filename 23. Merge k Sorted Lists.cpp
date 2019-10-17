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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while( l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if (l1 != NULL)
        {
            curr->next = l1;
        }
        else if (l2 != NULL)
        {
            curr->next = l2;
        }
        
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int size = lists.size();
        
        if (size == 0)
            return {};
        else if (size == 1)
            return lists[0];
        
        while (size > 1)
        {
            for (int i=0; i<size/2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[size-1-i]);
            }
            size = size - (size/2);
        }
        return lists[0];
    }
};
