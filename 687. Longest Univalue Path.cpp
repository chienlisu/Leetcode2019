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
    // get larget path from root to one side
    int helper(TreeNode* root, int& ans)
    {
        // exit
        if (root == NULL)
            return 0;

        // divide
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        int newLeft = 0, newRight = 0;
        
        // conquer
        if (root->left && root->left->val == root->val)
            newLeft = left + 1;
        if (root->right && root->right->val == root->val)
            newRight = right + 1;
        
        ans = max(ans, newLeft + newRight);
        
        return max(newLeft, newRight);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};
