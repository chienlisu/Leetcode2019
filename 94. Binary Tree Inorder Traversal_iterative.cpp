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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inordered;
        stack<TreeNode*> stored;
        TreeNode* node = root;
        
        while (node || !stored.empty())
        {
            while (node != NULL)
            {
                stored.push(node);
                node = node->left;
            }
            
            node = stored.top();
            inordered.push_back(node->val);
            stored.pop();
            node = node->right;
        }
        return inordered;
    }   
};
