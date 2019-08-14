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
    TreeNode* helper(vector<int> pre, vector<int> post, int start, int end)
    {
        if (start > end)
            return NULL;
        
        TreeNode* curr = new TreeNode(pre[preIdx++]);
        
        if (start == end)
            return curr;

        int right = postMap[curr->val];
        int left = right;
        for (int i=start; i<right; ++i)
        {
            if (post[i] == pre[preIdx])
            {
                left = i;
                break;
            }
        }
        
        curr->left = helper(pre, post, start, left);
        curr->right = helper(pre, post, left+1, right-1);
        return curr;
            
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        for (int i=0; i<post.size(); ++i)
        {
            postMap[post[i]] = i;
        }
        return helper(pre, post, 0, pre.size()-1);
    }
private:
    int preIdx;
    unordered_map<int, int> postMap;
};
