class Solution {
public:
    void dfs(int count, string curr, vector<string>& ans, vector<pair<char,char>> mapping)
    {
        if (count == 0)
        {
            if (curr[0] != '0')
                ans.push_back(curr);
            return;
        }
        
        for (auto i: mapping)
        {
            string next = i.first + curr + i.second;
            dfs(count-1, next, ans, mapping );
        }
    }
    vector<string> findStrobogrammatic(int n) {
        
        if (n == 0)
            return {};
        if (n == 1)
            return {"0", "1", "8"};
        
        vector<pair<char, char>> mapping;
        mapping.push_back(pair<char,char>{'0', '0'});
        mapping.push_back(pair<char,char>{'1', '1'});
        mapping.push_back(pair<char,char>{'6', '9'});
        mapping.push_back(pair<char,char>{'8', '8'});
        mapping.push_back(pair<char,char>{'9', '6'});
        
        vector<string> ans;
        
        if (n%2 == 0)
        {
            dfs(n/2, "", ans, mapping);
        }
        else
        {
            dfs(n/2, "0", ans, mapping);
            dfs(n/2, "1", ans, mapping);
            dfs(n/2, "8", ans, mapping);
        }
        return ans;
    }
};
