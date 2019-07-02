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
    int getDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        
        int left = 1 + getDepth(root->left);
        int right = 1 + getDepth(root->right);
        
        return max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (abs(left-right) > 1)
            return false;
        else
            return (isBalanced(root->left) && isBalanced(root->right));
    }
};
