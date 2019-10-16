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
   int getLeftDepth(TreeNode* root)
    {
        int depth = 0;
        while(root != nullptr)
        {
            depth++;
            root = root->left;
        }
        return depth;
    }
    int getRightDepth(TreeNode* root)
    {
        int depth = 0;
        while(root != nullptr)
        {
            depth++;
            root = root->right;
        }
        return depth;
    }
    
    int countNodes(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int left = getLeftDepth(root);
        int right = getRightDepth(root);

        if (left == right)
            return ((1 << left) - 1);
        else
            return (1 + countNodes(root->left) + countNodes(root->right));    
    }
};
