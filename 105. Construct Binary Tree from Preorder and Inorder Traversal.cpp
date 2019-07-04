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
    Solution()
    {
        preIdx = 0;
    }
    
    TreeNode* helper(vector<int>& pre, vector<int>& in, int inStr, int inEnd)
    {
        if (inStr > inEnd)
            return NULL;
        
        TreeNode* node = new TreeNode(pre[preIdx++]);
        
        if (inStr == inEnd)
            return node;
        
        int idx = inMap[node->val];
        
        node->left = helper(pre, in, inStr, idx-1);
        node->right = helper(pre, in, idx+1, inEnd);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i=0; i<inorder.size(); ++i)
        {
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = helper(preorder, inorder, 0, preorder.size()-1);
        return root;
    }
private:
    int preIdx;
    unordered_map<int, int> inMap;
};
