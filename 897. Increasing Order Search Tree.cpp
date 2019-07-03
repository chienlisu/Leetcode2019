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
    TreeNode* newRoot;
    TreeNode* newCurr;
    TreeNode* createNode(int val)
    {
        TreeNode* root = new TreeNode(val); 
        return root;
    }
    void helper(TreeNode* root)
    {
        if (root == NULL)
            return;
        
        helper(root->left);
        
        if (newRoot == NULL)
        {
            newRoot = createNode(root->val);
            newCurr = newRoot;
        }
        else
        {
            newCurr->right = createNode(root->val);
            newCurr = newCurr->right;
        }
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        newRoot = NULL;
        newCurr = NULL;
        helper(root);
        return newRoot;
    }
};
