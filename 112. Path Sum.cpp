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
    void helper(TreeNode* root, int sum, int total, bool& ans)
    {
        if (ans != false)
            return;
        
        total += root->val;
        
        if (root->left == NULL && root->right == NULL)
        {
            ans = (total == sum);
            return;
        }
        if (root->left)
            helper(root->left, sum, total, ans);
        if (root->right)
            helper(root->right, sum, total, ans);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (root == NULL)
            return false;
        
        bool ans = false;
        helper(root, sum, 0, ans);
        return ans;
    }
};
