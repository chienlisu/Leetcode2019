class Solution {
public:
    void backtracking(vector<int>& candidates, set<vector<int>>& ans, vector<int>& curr, int start, int end, int& sum, int& target)
    {
        if (sum == target)
        {
            ans.insert(curr);
            return;
        }
        else if (sum > target)
        {
            return;
        }
        if (start > end)
        {
            return;
        }
        
        for (int i=start; i<=end; ++i)
        {
            curr.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, ans, curr, i+1, end, sum, target);
            sum -= candidates[i];
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        if (candidates[0] > target)
            return {};
        
        int start = 0, end = candidates.size()-1;
        
        for (int i=0; i<candidates.size(); ++i)
        {
            if (candidates[i] > target)
            {
                end = i-1;
                break;
            }
        }
        
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> curr;
        int sum = 0;
        backtracking(candidates, ans, curr, start, end, sum, target);
        
        for (auto i: ans)
        {
            res.push_back(i);
        }
        
        return res;
    }
};
