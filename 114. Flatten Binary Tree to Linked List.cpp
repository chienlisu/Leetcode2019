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
    void flatten(TreeNode* root) {
        stack<TreeNode*> myStack;
        TreeNode* curr = root;
        
        while (curr != NULL || !myStack.empty())
        {
            TreeNode* prev = curr;
            while (curr != NULL)
            {
                TreeNode* temp = curr->left;
                if (curr->right != NULL)
                    myStack.push(curr->right);
                curr->right = curr->left;
                curr->left = NULL;
                prev = curr;
                curr = temp;
            }
            
            if(!myStack.empty())
            {    
                prev->right = myStack.top();
                curr = prev->right;
                myStack.pop();
            }
        }
    }
};
