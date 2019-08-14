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
    TreeNode* createNode(int val)
    {
        TreeNode* root = new TreeNode(val);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> myStack;
        TreeNode* root = createNode(preorder[0]);
        TreeNode* curr = root;
        myStack.push(root);
        
        for (int i=1; i<preorder.size(); ++i)
        {
            TreeNode* temp = createNode(preorder[i]);
            if (preorder[i] < preorder[i-1])
            {
                curr->left = temp;
                myStack.push(temp);
                curr = temp;
            }
            else
            {
                while(!myStack.empty() && myStack.top()->val < preorder[i])
                {
                    curr = myStack.top();
                    myStack.pop();
                }
                curr->right = temp;
                myStack.push(temp);
                curr = curr->right;
            }
        }
        return root;
    }
};
