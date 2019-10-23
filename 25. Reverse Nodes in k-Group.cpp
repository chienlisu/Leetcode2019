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
    void reverseK(ListNode*head, ListNode* tail)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;
        
        while (prev != tail)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr =temp;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* newHead = head;
        ListNode* front = head;
        ListNode* tail = head;
        
        while (front != NULL)
        {
            int count = 1;
            while (count < k && tail != NULL)
            {
                tail = tail->next;
                ++count;
            }
            if (tail == NULL)
            {
                break;
            }
            else
            {
                ListNode* temp = tail->next;
                reverseK(front, tail);
                front->next = temp;
                if (prev)
                {
                    prev->next = tail;
                }
                else
                {
                    newHead = tail;
                }
                prev = front;
                front = front->next;
                tail = front;
            }
        }
        return newHead;
    }
};
