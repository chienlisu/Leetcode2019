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
    TreeNode* myDFS(TreeNode* root, int& depth)
    {
        if (root == NULL)
        {
            depth = 0;
            return NULL;
        }
        
        int depth_l;
        int depth_r;
        TreeNode* left = myDFS(root->left, depth_l);
        TreeNode* right = myDFS(root->right, depth_r);
        depth = max(depth_l, depth_r) + 1;
        
        if (depth_l > depth_r)
            return left;
        else if (depth_r > depth_l)
            return right;
        else
            return root;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = 0;
        return myDFS(root, depth);
    }
};
