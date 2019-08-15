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
    // map: (x_idx, {y_level, value})
    void myDFS(TreeNode* root, map<int, vector<pair<int,int>>>& myMap, int idx, int level)
    {
        if (root == NULL)
            return;
        
        myMap[idx].push_back(pair<int, int>(level, root->val));
        myDFS(root->left, myMap, idx-1, level+1);
        myDFS(root->right, myMap, idx+1, level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> myMap;
        int idx = 0, level = 0;
    
        myDFS(root, myMap, idx, level);
        
        for (auto &i : myMap)
        {
            vector<pair<int, int>> myList = i.second;
            sort(myList.begin(), myList.end());
            
            vector<int> temp;
            for (auto j : myList)
                temp.push_back(j.second);
            
            ans.push_back(temp);
        }
        return ans;
    }
// not working: cannot handle same level order.
/*
    void helper(TreeNode* root, vector<vector<int>>& myVec, int curr, int& left, int& right)
    {
        if (root == NULL)
            return;
        
        if (curr >= left && curr <= right)
        {
            myVec[curr-left].push_back(root->val);
        }
        else if (curr < left)
        {
            myVec.insert(myVec.begin(), {root->val});
            --left;
        }
        else // curr > right
        {
            myVec.push_back({root->val});
            ++right;
        }
        
        helper(root->left, myVec, curr-1, left, right);
        helper(root->right, myVec, curr+1, left, right);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        int left = 0, right = 0;
        ans.push_back({});
        helper(root, ans, 0, left, right);
        return ans;
    }
*/
};
