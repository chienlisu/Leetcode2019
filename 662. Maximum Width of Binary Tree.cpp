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
    void myDFS(TreeNode* root, vector<unsigned int>& start, unsigned int& ans, int level, unsigned int idx)
    {
        if (root == NULL)
            return;
        
        if (start.size() <= level)
            start.push_back( idx);
        else
            ans = max(ans, idx-start[level]+1);
        
        if (root->left) myDFS(root->left, start, ans, level+1, 2*idx);
        if (root->right) myDFS(root->right, start, ans, level+1, 2*idx + 1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        vector<unsigned int>start;
        unsigned int ans = 1;
        
        myDFS(root, start, ans, 0, 0);
        return ans;
    }
};
