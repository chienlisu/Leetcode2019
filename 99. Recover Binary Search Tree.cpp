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
    TreeNode *prev = NULL, *curr = NULL, *x = NULL, *y = NULL; 

    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        
        helper(root->left);
        curr = root;
        if (prev != NULL && curr->val < prev->val)
        {
            y = curr;
            if (x == NULL)
                x = prev;
            else
                return;
        }
        prev = curr;
        helper(root->right);
    }
    void recoverTree(TreeNode* root)
    {
        helper(root); // find two swapped nodes.
        //swap nodes:
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        return;
    }
};
