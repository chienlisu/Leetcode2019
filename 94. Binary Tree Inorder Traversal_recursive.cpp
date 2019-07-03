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
    vector<int> inordered;
    void helper(TreeNode* root)
    {
        if (root == NULL)
            return;
        
        helper(root->left);
        inordered.push_back(root->val);
        helper(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);  
        return inordered;
    }
 }
