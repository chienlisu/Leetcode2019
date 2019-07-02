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
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        
        int curr = left+right;
        return max(curr, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};
