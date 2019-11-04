/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode* head)
    {
        int ans = 0;
        while (head != NULL)
        {
            ++ans;
            head = head->next;
        }
        return ans;
    }
    
    TreeNode* inOrderTraversal(ListNode*& head, int l, int h)
    {
        if (l > h)
            return NULL;
        
        int med = l + (h-l)/2;
        
        // inorder traversal: left recursion + add current + right recursion
        TreeNode* left = inOrderTraversal(head, l, med-1);
        TreeNode* curr = new TreeNode(head->val);
        head = head->next;
        curr->left = left;
        curr->right = inOrderTraversal(head, med+1, h);
        return curr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int size = getSize(head);
        
        return inOrderTraversal(head, 0, size-1);
    }
};
