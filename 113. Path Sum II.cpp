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
    void myDFS(TreeNode* root, vector<vector<int>>& ans, vector<int> curr, int sum)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == root->val)
            {
                curr.push_back(root->val);
                ans.push_back(curr);
            }
            else
            {
                return;
            }
        }
        else
        {
            curr.push_back(root->val);
            myDFS(root->left, ans, curr, sum-root->val);
            myDFS(root->right, ans, curr, sum-root->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        myDFS(root, ans, curr, sum);
        return ans;
    }
};
