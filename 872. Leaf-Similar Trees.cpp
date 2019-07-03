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
    void getLeaves(TreeNode* root, vector<int>& leaf)
    {
        if (root->left == NULL && root->right == NULL)
        {
            leaf.push_back(root->val);
            return;
        }
        if (root->left)
            getLeaves(root->left, leaf);
        if (root->right)
            getLeaves(root->right, leaf);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeaves(root1, leaf1);
        getLeaves(root2, leaf2);
        
        if(leaf1.size() != leaf2.size())
            return false;
        for (int i=0; i<leaf1.size(); ++i)
        {
            if (leaf1[i] != leaf2[i])
                return false;
        }
        return true;
    }
};
