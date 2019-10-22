class Solution {
public:
    // to be improved: use some space to save check time
    bool valid(pair<int,int> pos, vector<pair<int,int>> curr)
    {
        for (int i=0; i<curr.size(); ++i)
        {
            // row (first) must be not the same.
            if (curr[i].second == pos.second || abs(curr[i].first - pos.first) == abs(curr[i].second - pos.second))
            {
                return false;
            }
        }
        return true;
    }
    void helper(int row, int n, vector<pair<int,int>>& curr, vector<vector<string>>& ans)
    {
        if (row == n)
        {
            string temp(n, '.');
            vector<string> sol(n, temp);
            for (int i=0; i<curr.size(); ++i)
            {
                sol[curr[i].first][curr[i].second] = 'Q';   
            }
            ans.push_back(sol);
        }
        
        for (int i=0; i<n; ++i)
        {
            pair<int, int>pos = {row, i};
            if (valid(pos, curr))
            {
                curr.push_back(pos);
                helper(row+1, n, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1)
            return {{"Q"}};
        
        vector<vector<string>> ans;
        vector<pair<int,int>> curr;
        helper(0,n, curr, ans);
        return ans;
    }
};
