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
    int maxLevelSum(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return 1;
        
        int max = INT_MIN;
        int ans = 0;
        int currLevel = 0;
        
        queue<TreeNode*> levelNodes;
        levelNodes.push(root);
        
        while (!levelNodes.empty())
        {
            ++currLevel;
            int total = 0;
            int size = levelNodes.size();
            for (int i=0; i<size; ++i)
            {
                TreeNode* currNode = levelNodes.front();
                levelNodes.pop();
                total += currNode->val;

                if (currNode->left != NULL)
                    levelNodes.push(currNode->left);
                if (currNode->right != NULL)
                    levelNodes.push(currNode->right);
            }

            if (total > max)
            {
                ans = currLevel;
                max = total;
            }
        }
        return ans;
    }
};
