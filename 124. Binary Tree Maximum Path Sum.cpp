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
    int getStraightPathSum(TreeNode* root, int& sum)
    {
        if (root == NULL)
            return 0;
        
        int leftSum = max(0,getStraightPathSum(root->left, sum));
        int rightSum = max(0,getStraightPathSum(root->right, sum));
        
        sum = max(sum, leftSum + rightSum + root->val);
        
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        
        int sum = INT_MIN;
        getStraightPathSum(root, sum);
        
        return sum;
    }
};
